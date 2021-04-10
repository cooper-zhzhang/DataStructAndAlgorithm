/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        char preChar = '\0';

        int offsize = -1;
        int i = 0;
        for (; i < S.length(); i++)
        {
            char c = S[i];

            if (offsize >= 0)
            {
                S.erase(offsize, i - offsize);
                i = max(offsize - 1, 0) - 1; // i 指向前一个
                offsize = -1;
                preChar = '\0';
                continue;
            }

            if (c == preChar)
            {
                if (offsize == -1)
                {
                    offsize = i - 1;
                }
            }

            preChar = c;
        }

        if (offsize >= 0)
        {
            S.erase(offsize, i - offsize);
            i = max(offsize - 1, 0) - 1; // i 指向前一个
            offsize = -1;
            preChar = '\0';
        }

        return S;
    }
};

int main()
{
    Solution solution;

    std::string result = solution.removeDuplicates("abbaca");

    std::cout << result << std::endl;

    result = solution.removeDuplicates("aaaaaaaaaa");

    std::cout << result << std::endl;

    return 0;
}
