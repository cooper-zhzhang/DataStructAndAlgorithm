#include <vector>
#include <algorithm>

using namespace std;

void min_max_num(vector<int> &vec, int &minValue, int &maxValue)
{
    if (vec.size() <= 0)
    {
        return ;
    }

    minValue = 0;
    maxValue = 0;
    int beginIndex = 0;
    if (vec.size() & 1)
    {
        // 奇数
        minValue = maxValue = vec[0];
        beginIndex = 1;
    }
    else
    {
        minValue = std::min(vec[0], vec[1]);
        maxValue = std::max(vec[0], vec[1]);
        beginIndex = 2;
    }

    for (size_t i = beginIndex; i < vec.size(); i = i+2)
    {
        if (vec[i] < vec[i+1])
        {
            if (vec[i] < minValue)
            {
                minValue = vec[i];
            }
        }
        else
        {
            if (vec[i+1] > maxValue)
            {
                maxValue = vec[i+1];
            }
        }
    }
}

void min_num(vector<int> &vec)
{
    if (vec.size() <= 0)
    {
        return ;
    }

    int min = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
    }
}


int main(int argc, char** argv)
{
    return 0;
}