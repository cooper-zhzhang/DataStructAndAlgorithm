#include <iostream>

using namespace std;

/*
给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution
{
public:
    int reverse(int x)
    {
        int result = conv(x);
        if (x % 10 == 0)
        {
            return result;
        }
        
        // 原先的x最后一位是否为0
        int sourValue = conv(result);

        if (sourValue != x)
        {
            return 0;
        }

        return result;
    }

private:
    int conv(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        int tem = x;
        if (x < 0)
        {
            x = ~x + 1;
        }

        int result = 0;
        while (x)
        {
            int tempx = x % 10;
            result = result * 10 + tempx;
            x = x / 10;
        }

        if (tem < 0)
        {
            result = -result;
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    
    int x = 120;
    int result = solution.reverse(x);

    std::cout << result << std::endl;

    return 0;
}