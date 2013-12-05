//快速排序。
//快排就是一个挖坑填坑的过程。在左边挖个坑，先在右边找个位置，填入左边坑；
//然后从左边坑之后，找个位置,填入右边的坑。

#pragma once

//找到一个分隔点
template<typename T, typename Pred>
int quick_split(std::vector<T> & arr, int left, int right, Pred pred)
{
    int l = left;
    int r = right;

    T temp = arr[l]; //挖个坑
    while (r > l)
    {
        //先从右侧找到一个大于参考值的位置
        while (r > l && pred(temp, arr[r])) --r;
        if (r > l) arr[l++] = arr[r];

        //从左侧找到一个小于参考值的位置
        while (r > l && pred(arr[l], temp)) ++l;
        if (r > l) arr[r--] = arr[l];
    }
    arr[l] = temp;
    return l;
}

template<typename T, typename Pred>
void quick_sort_real(std::vector<T> & arr, int left, int right, Pred pred)
{
    if (left >= right) return;

    int pos = quick_split(arr, left, right, pred);

    //对分割点两侧的数据分别进行快排
    quick_sort_real(arr, left, pos - 1, pred);
    quick_sort_real(arr, pos + 1, right, pred);
}

template<typename T, typename Pred = std::less<T>>
void quick_sort(std::vector<T> & arr, Pred pred = Pred())
{
    if (arr.empty()) return;
    
    quick_sort_real(arr, 0, int(arr.size()) - 1, pred);
}
