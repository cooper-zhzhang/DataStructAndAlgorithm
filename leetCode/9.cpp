#include <iostream>

/**
 *给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 *回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        if (x < 10)
        {
            return true;
        }

        if (x % 10 == 0)
        {
            return false;
        }
        
        int newValue = 0;

        while( x > newValue)
        {
            newValue = newValue * 10 + x % 10;
            x /= 10;
        }

        return x == newValue || x == newValue / 10;
    }
};

int main()
{

    Solution solution;

    std::cout << solution.isPalindrome(121) << std::endl;
    std::cout << solution.isPalindrome(-121) << std::endl;
    std::cout << solution.isPalindrome(10) << std::endl;
    std::cout << solution.isPalindrome(-101) << std::endl;
    std::cout << solution.isPalindrome(0) << std::endl;

    

}