#pragma once

#include "heap.h"
#include "quick.h"
#include "merge.h"

enum sort_type
{
    heap = 0,
    quick = 1,
    merge = 2,
    select = 3,
    bubble = 4,
    stl_stable = 6,
};


class sort_algo
{
    sort_type m_type;
public:
        
    sort_algo(sort_type t)
        : m_type(t)
    {}


    template<typename T, typename Pred = std::less<T>>
    void sort(std::vector<T> & arr, Pred pred = Pred()) const
    {
        if (sort_type::heap == m_type)
        {
            heap_sort(arr, pred);
        }
        else if (sort_type::quick == m_type)
        {
            quick_sort(arr, pred);
        }
        else if (sort_type::merge == m_type)
        {
            merge_sort(arr, pred);
        }
        else if (sort_type::stl_stable == m_type)
        {
            std::stable_sort(arr.begin(), arr.end(), pred);
        }
    }
};
