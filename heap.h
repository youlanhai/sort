//堆排序
#pragma once

//调整堆。使最大（最小）元素位于堆顶
template<typename T, typename Pred>
inline void heap_ajust(std::vector<T> & arr, size_t i, size_t n, Pred pred)
{
    size_t lchild = i * 2;
    size_t rchild = lchild + 1;

    size_t max_i = i;
    if (lchild < n && pred(arr[max_i], arr[lchild])) std::swap(arr[max_i], arr[lchild]);
    if (rchild < n && pred(arr[max_i], arr[rchild])) std::swap(arr[max_i], arr[rchild]);
}

//使用n个元素构建堆
template<typename T, typename Pred>
void heap_build(std::vector<T> & arr, size_t n, Pred pred)
{
    //对非叶结点进行调整，变成大顶堆（小顶堆）。
    size_t half = n / 2;
    for (size_t i = 0; i <= half; ++i)
    {
        heap_ajust(arr, half - i, n, pred);
    }
}

//堆排序
template<typename T, typename Pred = std::less<T>>
void heap_sort(std::vector<T> & arr, Pred pred = Pred())
{
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i)
    {
        heap_build(arr, n - i, pred);
        std::swap(arr[0], arr[n - i - 1]); //堆内首尾交换
    }
}
