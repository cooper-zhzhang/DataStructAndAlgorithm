#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void exchangeValue(int &l, int &r)
{
    int temp = l;
    l = r;
    r = temp;
}

int random_partition(vector<int> &vec, int beginIndex, int endIndex)
{
    int lastMinIndex = beginIndex-1;// 指向分割点
    for (int i = beginIndex; i < endIndex; ++i)
    {
        if (vec[i] <= vec[endIndex])
        {
            exchangeValue(vec[++lastMinIndex], vec[i]);
        }
    }

    exchangeValue(vec[++lastMinIndex], vec[endIndex]);
    return lastMinIndex;
}

int random_min_select(vector<int> &vec, int beginIndex, int endIndex, int k)
{
    if (beginIndex == endIndex)
    {
        return vec[beginIndex];
    }

    int diff = random_partition(vec, beginIndex, endIndex);
    int cur = diff - beginIndex + 1;// 表示在[beginIndex, endIndex]范围内得排名
    if (cur == k)
    {// k表示需要得排名
        return vec[diff];
    }
    else if (cur < k)
    {// 在小的那部分
        return random_min_select(vec, diff-1, endIndex, k-cur);
    }
    else
    {// 在大的那部分
        return random_min_select(vec, beginIndex, diff-1, k);
    }
}

int random_max_select(vector<int> &vec, int beginIndex, int endIndex, int k)
{
    if (beginIndex == endIndex)
    {
        return vec[beginIndex];
    }

    int diff = random_partition(vec, beginIndex, endIndex);
    int cur = endIndex - diff + 1;

    if (cur == k)
    {// k表示需要得排名
        return vec[diff];
    }
    else if (cur < k)
    {// 在小的那部分
        return random_max_select(vec, beginIndex, diff-1, cur-k);
    }
    else
    {// 在大的那部分
        return random_max_select(vec, diff-1, endIndex, k);
    }
}

int main(int argc, char** argv)
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};

    random_shuffle(vec.begin(), vec.end());

    std::cout << random_max_select(vec, 0, vec.size()-1, 1) << std::endl;


    random_shuffle(vec.begin(), vec.end());

    std::cout << 
    random_min_select(vec, 0, vec.size()-1, 1)
    << std::endl;

    
    return 0;
}
