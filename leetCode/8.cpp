#include <iostream>
#include <string>

/*
函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {

        const char *pStr = s.c_str();

        while (*pStr == ' ')
        {
            ++pStr;
        }

        // 判断有没有结束
        if (*pStr == '\0')
        {
            return 0;
        }

        bool isE = false;
        if (*pStr == '-')
        {
            isE = true;
            ++pStr;
        }
        else if (*pStr == '+')
        {
            ++pStr;
        }

        long long result = 0;
        long long value = 0;
        while (*pStr != '\0')
        {
            if (*pStr >= '0' && *pStr <= '9')
            {
                value *= 10;
                value += (*pStr - '0');

                 result = value;
                if (isE)
                {
                    result = -value;
                }
                if (result > INT_MAX)
                {
                    return INT_MAX;
                }
                if (result < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                break;
            }

            ++pStr;
        }

        return result;
    }

    void deleteSpace(string &s)
    {
        char *pStr = const_cast<char *>(s.c_str());
        char *begin = pStr;
        while (*pStr != '\0')
        {
            while (*pStr == ' ')
            {
                ++pStr;
            }

            *begin = *pStr;
            if (*begin == '\0')
            {
                return;
            }

            ++begin;
            ++pStr;
        }
        *begin = '\0';
    }
};

int main()
{
    Solution solution;
    int value;
    // value = solution.myAtoi("       -4-2");
    // std::cout << value << std::endl;

    // value = solution.myAtoi("4193 with words");
    // std::cout << value << std::endl;

    // value = solution.myAtoi("words and 987");
    // std::cout << value << std::endl;

    // value = solution.myAtoi("-91283472332");
    // std::cout << value << std::endl;

    // value = solution.myAtoi("-91283472332");
    // std::cout << value << std::endl;

    value = solution.myAtoi("  0000000000012345678");
    std::cout << value << std::endl;


value = solution.myAtoi(" -42");
    std::cout << value << std::endl;


    return 0;
}