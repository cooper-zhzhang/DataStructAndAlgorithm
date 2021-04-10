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
        // 先进行一个排序
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> &it1, vector<int> &it2) { return it1[0] < it2[0]; });

        for (int i = 0; i < intervals.size() - 1; ++i)
        {
            int begin1 = intervals[i][0];
            int end1 = intervals[i][1];

            int begin2 = intervals[i + 1][0];
            int end2 = intervals[i + 1][1];

            // 如果不进行合并
            int minValue = intervals[i][0];
            int maxValue = intervals[i][1];

            if (intersect(begin1, end1, begin2, end2))
            {// 如果进行合并则要更改值
                intervals[i + 1][0] = minValue = min(begin1, begin2);
                intervals[i + 1][1] = maxValue = max(end1, end2);
            }

            vector<int> ve{minValue, maxValue};
            if (result.empty())
            {
                result.push_back(ve);
            }
            else
            {
                auto &back = result.back();
                if (back[0] == ve[0])
                {
                    back[1] = ve[1];
                }
                else
                {
                    result.push_back(ve);
                }
            }
        }

        // 最后一个元素
        auto back_value = intervals.back();
        auto back_value_in_result = result.back();

        if (!intersect(back_value_in_result[0], back_value_in_result[1], back_value[0], back_value[1]))
        {
            result.push_back(back_value);
        }

        return result;
    }

private:
    bool intersect(int begin1, int end1, int begin2, int end2)
    {
        return begin2 <= end1;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         vector<vector<int>> res;
//         vector<int> starts, ends;
//         for (int i = 0; i < n; ++i) {
//             starts.push_back(intervals[i][0]);
//             ends.push_back(intervals[i][1]);
//         }
//         sort(starts.begin(), starts.end());
//         sort(ends.begin(), ends.end());
//         for (int i = 0, j = 0; i < n; ++i) {
//             if (i == n - 1 || starts[i + 1] > ends[i]) {
//                 res.push_back({starts[j], ends[i]});
//                 j = i + 1;
//             }
//         } 
//         return res;
//     }
// };

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