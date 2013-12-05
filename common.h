#pragma once

#include <vector>
#include <algorithm>

template<typename T, typename Pred>
void cmp_and_swap(T & a, T & b, Pred pred)
{
    if (pred(b, a)) std::swap(a, b);
}


template<typename T>
bool big_than(const T & x, const T & y)
{
    return x > y;
}
