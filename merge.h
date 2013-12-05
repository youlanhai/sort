//归并排序
//空间复杂度O(n)，时间复杂度N*O(logN)
//稳定排序
#pragma once

template<typename T, typename Pred>
void merge_sort_merge(std::vector<T> & dest, std::vector<T> & arr, int start, int half, int end, Pred pred)
{
    int x = 0;
    int i = start;
    int j = half + 1;

    while (i <= half && j <= end)
    {
        if (!pred(arr[j], arr[i])) dest[x++] = arr[i++];
        else dest[x++] = arr[j++];
    }

    while (i <= half) dest[x++] = arr[i++];
    while (j <= end) dest[x++] = arr[j++];

    for (int y = 0; y < x; ++y) arr[start + y] = dest[y];
}

template<typename T, typename Pred>
void merge_sort_real(std::vector<T> & temp, std::vector<T> & arr, int start, int end, Pred pred)
{
    if (end - start < 1) return;

    //只剩2个元素时，直接比较排序
    if (end - start == 1)
    {
        cmp_and_swap(arr[start], arr[end], pred);
        return;
    }

    //将数据分割成两部分
    int half = start + (end - start) / 2;
    merge_sort_real(temp, arr, start, half, pred);
    merge_sort_real(temp, arr, half + 1, end, pred);

    //合并分割后的两部分
    merge_sort_merge(temp, arr, start, half, end, pred);
}


template<typename T, typename Pred = std::less<T>>
void merge_sort(std::vector<T> & arr, Pred pred = Pred())
{
    if (arr.empty()) return;

    std::vector<T> temp(arr.size());
    merge_sort_real(temp, arr, 0, int(arr.size()) - 1, pred);
}