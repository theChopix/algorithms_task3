#ifndef MY_PRINT_H_
#define MY_PRINT_H_

#include <iostream>
#include <vector>

#include "sort.h"

using namespace std;

void print_coords(vector<coord_t> c, int eggs)
{
    for (int i = 0; i < eggs; i++) {
        cout << c[i].height << " " << c[i].column << "\n";
    }
}

void print_cur_col(int col[], int wdth, int hght)
{
    cout << setw(3) << hght << "| ";
    for (int i = 0; i < wdth; i++) {
        cout << setw(4) << col[i] << " ";
    }
    cout << "\n";
}

#endif //MY_PRINT_H_