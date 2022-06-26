#ifndef MY_SORT_H_
#define MY_SORT_H_

#include <algorithm>
#include <iomanip>
using namespace std;

struct coord_t {
    int column, height;
};

bool operator<(const coord_t &a, const coord_t &b)
{
    return a.height > b.height || (a.height == b.height && a.column > b.column);
}

#endif //MY_SORT_H_