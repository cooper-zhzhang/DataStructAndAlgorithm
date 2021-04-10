#include <vector>
#include <iostream>

using namespace std;

void exchangeValue(int &l, int &r)
{
    int temp = l;
    l = r;
    r = temp;
}

int partition(std::vector<int> &vec, int l, int r)
{
    int partitionIndex = l-1;// 机制分割点 指向最后一个小于基值的下标

    int baseValue = vec[r];
    for (int i = l; i < r; i++)
    {
        if (vec[i] <= baseValue)
        {
            ++partitionIndex;

            int tem = vec[partitionIndex];
            vec[partitionIndex] = vec[i];
            vec[i] = tem;
        }
    }

    ++partitionIndex;
    int temp = vec[partitionIndex];
    vec[partitionIndex] = vec[r];
    vec[r] = temp;

    return partitionIndex;
}

void quick_sort(std::vector<int> &vec, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int index = partition(vec, l, r);
    quick_sort(vec, l, index-1);
    quick_sort(vec, index+1, r);
}

int main()
{
    //std::vector<int> vec{1, 2, 3, 4, 9, 6, 7, 8, 5};
    std::vector<int> vec{8, 7, 6, 9, 4, 3, 2, 1, 5};

    //partition(vec, 0, vec.size()-1);

    quick_sort(vec, 0, vec.size()-1);


    for(auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}