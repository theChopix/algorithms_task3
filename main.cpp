#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "print.h"
#include "sort.h"
using namespace std;

/* input of columns is numbered from 1;
    array indexes go from 0... */
#define ARRAyOFFSET(x) (x - 1)

#define UNATTAINABLE -1
#define isATTAINABLE(x) (x != -1)

int get_max_in_array(int arr[], int length);
int get_max_possible(int row[], int width, int col, int heightDiff);
int get_biggest_profit(vector<coord_t> coords, int width);

int main()
{
    int width, numOfEggs;
    cin >> width >> numOfEggs;

    vector<coord_t> coords;
    for (int i = 0; i < numOfEggs; i++) {
        coord_t c;
        cin >> c.column >> c.height;
        coords.push_back(c);
    }

    /* sorting positions of eggs according to their height
        from that with biggest height to that with smallest */
    sort(coords.begin(), coords.end());

    int res = get_biggest_profit(coords, width);
    cout << res << "\n";
}

int get_max_in_array(int arr[], int length)
{
    int ret = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > ret)
            ret = arr[i];
    }
    return ret;
}

/* propagates biggest values of prior row according to difference between
    heights of last procceeded egg and current one [heightDiff] */
int get_max_possible(int row[], int width, int col, int heightDiff)
{
    /* straight-down */
    int ret = row[col];

    int currentCol;

    /* left-down */
    for (int i = 1; i <= heightDiff; i++) {
        currentCol = col - i;
        /* if the position is still on game desk = not too left
            and value on that postion is bigger than previsously achieved */
        if (currentCol >= 0 && row[currentCol] > ret)
            ret = row[currentCol];
    }

    /* right-down */
    for (int i = 1; i <= heightDiff; i++) {
        currentCol = col + i;
        /* if the position is still on game desk = not too right
            and value on that postion is bigger than previsously achieved */
        if (currentCol < width && row[currentCol] > ret)
            ret = row[currentCol];
    }

    return ret;
}

int get_biggest_profit(vector<coord_t> coords, int width)
{
    /* there is no need to keep whole row in memory
        our only interest is to track position of left pixel of basket
        which can each but not last, thus length = width - 1 */
    int actualWidth = width - 1;

    /* record of only two rows is needed; the prior [0] one and the above
        [1] thus is index always changing at the end of while cycle when we
        go higher */
    int currentRows[2][actualWidth];
    bool currentRowIndex = false;

    /* setting starting position of basket to 0 (e.t. 0 collected eggs) */
    currentRows[int(currentRowIndex)][0] = 0;

    /* setting positions that are unattainable by basket */
    for (int i = 1; i < actualWidth; i++) {
        currentRows[int(currentRowIndex)][i] = UNATTAINABLE;
    }

    int prevHeight = 0;
    int currHeight;

    while (!coords.empty()) {

        currHeight = coords.back().height;

        for (int i = 0; i < actualWidth; i++) {
            int heightDiff = currHeight - prevHeight;
            currentRows[int(!currentRowIndex)][i] = get_max_possible(
                currentRows[int(currentRowIndex)], width - 1, i, heightDiff);
        }

        while (coords.back().height == currHeight) {

            int currentColumn = coords.back().column;

            int *currentRow = currentRows[int(!currentRowIndex)];

            /* if column of current egg is not the last one, than it's
                achievable even if left pixel of basekt is right on the column
             */
            if (currentColumn < width &&
                isATTAINABLE(currentRow[ARRAyOFFSET(currentColumn)]))
                currentRow[ARRAyOFFSET(currentColumn)] += 1;

            /* if column of current egg is not the first one, than it's
                achievable even if left pixel of basket is one field more to the
                left */
            if (currentColumn > 1 &&
                isATTAINABLE(currentRow[ARRAyOFFSET(currentColumn) - 1])) {
                currentRow[ARRAyOFFSET(currentColumn) - 1] += 1;
            }
            coords.pop_back();
        }

        prevHeight = currHeight;
        /* record of only two rows is needed; the prior [0] one and the above
            [1] thus is index always changing at the end of while cycle when we
            go higher */
        currentRowIndex = !currentRowIndex;
    }

    /* gets maximum value in last filled column (with highest placed egg) */
    return get_max_in_array(currentRows[int(currentRowIndex)], width - 1);
}