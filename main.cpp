// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sort.h"
#include <iostream>

struct node
{
    int idx;
    int val;

    node()
    {}

    node(int i, int v)
        : idx(i)
        , val(v)
    {}

    bool operator < (const node & r) const
    {
        return val < r.val;
    }

    bool operator > (const node & r) const
    {
        return val > r.val;
    }
};

bool operator == (const node & l, const node & r)
{
    return l.val == r.val;
}

void output_arr(std::vector<node> & arr)
{
    for (node & x : arr) std::cout << x.val << ":" << x.idx << " ";
    std::cout << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    sort_algo sort(sort_type::stl_stable);

    int int_arr[] = {9, 5, 8, 8, 1, 10, 11, 3, 2, 1, 1};

    std::vector<node> arr;

    {
        int i = 0;
        for (int x : int_arr)
        {
            arr.push_back(node(i++, x));
        }
    }

    std::cout << "before sort: ";
    output_arr(arr);

    sort.sort(arr, std::less<node>());

    std::cout << "after sort: ";
    output_arr(arr);

    sort.sort(arr, big_than<node>);

    std::cout << "after sort2: ";
    output_arr(arr);

	return 0;
}

