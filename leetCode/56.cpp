/*以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> &it1, vector<int> &it2) { return it1[0] < it2[0]; });

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> &curData = intervals[i];
            vector<int> &data = *(result.rbegin());

            if (data[1] < curData[0])
            {// 不相交
                result.push_back(curData);
                continue;
            }
            
            data[1] = data[1] > curData[1] ? data[1] : curData[1];
        }
        
        return result;
    }
};

int main()
{
    Solution solution;

    //std::vector<vector<int>> vec{{0, 0}};
    std::vector<vector<int>> vec{{1,3},{2,6},{8,10},{15,18}};
    auto result =
        solution.merge(vec);

    for (auto it : result)
    {
        std::cout << it[0] << " " << it[1] << std::endl;
    }

    return 0;
}