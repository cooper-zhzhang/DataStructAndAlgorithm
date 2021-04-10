#include <vector>
#include <iostream>

using namespace std;

class Solution
{

public:
    double
    getValue(vector<int> &nums1, vector<int> &nums2, int index1, int index2)
    {
        if(index1 > index2)
        {
            int temp = index2;
            index2 = index1;
            index1 = temp;
        }


        int curIndex = -1;
        int numsIndex1 = -1;
        int numsIndex2 = -1;

        int value1 = 0;
        int value2 = 0;

        while (true)
        {
            // 1 判断哪个进行自增
            int tempNums1Index = numsIndex1 + 1;
            int tempNums2Index = numsIndex2 + 1;

            int nums1Value = INT32_MAX;
            if (tempNums1Index < nums1.size())
            { // 第一个数组还没有走到尾部
                nums1Value = nums1[tempNums1Index];
            }

            int nums2Value = INT32_MAX;
            if (tempNums2Index < nums2.size())
            {
                nums2Value = nums2[tempNums2Index];
            }

            if (nums2Value == INT32_MAX && nums1Value == INT32_MAX)
            {
                break;
            }

            // 比较数值移动哪一个数组的下边
            bool assNusm1Index = false;
            if (nums1Value < nums2Value)
            {
                numsIndex1 = tempNums1Index;
                assNusm1Index = true;
            }
            else
            {
                numsIndex2 = tempNums2Index;
            }

            ++curIndex;
            if (curIndex == index1)
            {
                if (assNusm1Index)
                {
                    value1 = nums1[numsIndex1];
                }
                else
                {
                    value1 = nums2[numsIndex2];
                }
            }

            if (curIndex == index2)
            {
                if (assNusm1Index)
                {
                    value2 = nums1[numsIndex1];
                }
                else
                {
                    value2 = nums2[numsIndex2];
                }
                break;
            }
        }

        if(index2 >= 0 && index1 >= 0)
        {
            return (value1 + value2) / 2.0;
        }

        return (value1 + value2);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1VcCount = nums1.size();
        int nums2VcCount = nums2.size();

        int allCount = nums1VcCount + nums2VcCount;

        if (allCount % 2 == 0)
        {
            return getValue(nums1, nums2, allCount / 2 - 1, allCount / 2);
        }
        else
        {
            return getValue(nums1, nums2, allCount / 2, -1);
        }
    }
};

int main()
{

    Solution solution;

    std::vector<int> nums1;
     nums1.push_back(1);
    // nums1.push_back(2);
     nums1.push_back(3);
    // nums1.push_back(4);
    // nums1.push_back(5);
    std::vector<int> nums2;
     nums2.push_back(2);
    // nums2.push_back(4);

    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
