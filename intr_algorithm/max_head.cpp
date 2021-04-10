#include <iostream>
#include <vector>

using namespace std;


int left(int index)
{
    return (index + 1) * 2 - 1;
}

int right(int index)
{
    return (index + 1) * 2;
}

int parent(int index)
{
    if (index <= 0)
    {
        return -1;
    }
    
    if (index & 1)
    {
        return (index + 1)/2-1;
    }

    return index / 2 -1;
}


void head_max_heapify(std::vector<int> &vec, int index, int len)
{
    while (index < len)
    {
        int l = (index + 1) * 2 - 1;
        int r = (index + 1) * 2;

        int largest = index;
        if (l < len && vec[l] > vec[index])
        {
            largest = l;
        }

        if (r < len && vec[r] > vec[largest])
        {
            largest = r;
        }

        if (largest == index)
        {
            break;
        }

        int temp = vec[largest];
        vec[largest] = vec[index];
        vec[index] = temp;
        index = largest;
    }
}

void max_head(std::vector<int> &vec, int index)
{
    int l = (index + 1) * 2 - 1;
    int r = (index + 1) * 2;

    int largest = index;
    if (l < vec.size() && vec[l] > vec[index])
    {
        largest = l;
    }

    if (r < vec.size() && vec[r] > vec[index])
    {
        largest = r;
    }

    if (largest != index)
    {
        int temp = vec[largest];
        vec[largest] = vec[index];
        vec[index] = temp;
        max_head(vec, largest);
    }
}

void build_max_head(std::vector<int> &vec, int len)
{
    if (len > vec.size())
    {
        return;
    }
    
    for (int i = len/2-1; i >= 0; --i)
    {
        head_max_heapify(vec, i, len);
    }
}

void head_sort(std::vector<int> &vec)
{
    // 循环中每次构建一个最大堆 
    // 把最大的元素放在最后
    build_max_head(vec, vec.size());

    for (int i = vec.size()-1; i >= 1; --i)
    {
        int temp =vec[0];
        vec[0] = vec[i];
        vec[i] = temp;

        head_max_heapify(vec, 0, i);
    }
}

// 最大优先队列插入
void head_increase_key(std::vector<int> &vec, int index, int key)
{
    if (index >= vec.size() || vec[index] >= key)
    {
        return;
    }

    vec[index] = key;

    while (parent(index) >= 0)
    {
        int parentIndex = parent(index);
        if (vec[parentIndex] >= vec[index])
        {
            break;
        }

        int temp = vec[index];
        vec[index] = vec[parentIndex];
        vec[parentIndex] = temp;

        index = parentIndex;
    }
}

void head_insert_key(std::vector<int> &vec, int key)
{
    vec.push_back(INT_MIN);

    head_increase_key(vec, vec.size()-1, key);

}

int main()
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    head_sort(vec);

    build_max_head(vec, vec.size());

    head_increase_key(vec, 4, 10);

    head_insert_key(vec, 11);


    for (auto it : vec)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;

    return 0;
}