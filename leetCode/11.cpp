/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 会超时

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxValue = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            int newValue = min(height[i], height[j]) * (j - i);
            if (newValue > maxValue)
            {
                maxValue = newValue;
            }

            // 开始移动
            if (height[i] > height[j])
            {
                j --;
            }
            else //if (height[i] < height[j])
            {
                i++;
            }
        }

        return maxValue;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> height{1,2,1};

    int result = solution.maxArea(height);
    std::cout << result << std::endl;

    return 0;
}