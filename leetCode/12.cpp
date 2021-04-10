/*

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。
但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:


    string intToRoman(int num)
    {
        // 1 先是特殊情况
        // 2 再进行基底的划分

        // 1 I
        // 2 II
        // 3 III
        // 4 IV
        // 5 V
        // 6 VI
        // 7 VII
        // 8 VII
        // 9 IX
        // 10 X
        // 40 XL
        // 50 L
        // 90 XC
        // 100 C
        // 500 D
        // 900 CM
        // 1000 M

        // 4 9 使用减法 其余使用加法

        std::string word;

        int index1 = num / 1000;// 整千
        if (index1 > 0)
        {
            switch(index1)
            {
                case 1:
                {
                    word += "M";
                }break;
                case 2:
                {
                    word += "MM";
                }break;
                case 3:
                {
                    word += "MMM";
                }break;
            }
        }

        int index2 = (num % 1000 / 100);
        if (index2 > 0)
        {
            switch(index2)
            {
                case 1:
                {
                    word += "C";
                }break;
                case 2:
                {
                    word += "CC";
                }break;
                case 3:
                {
                    word += "CCC";
                }break;
                case 4:
                {
                    word += "CD";
                }break;
                case 5:
                {
                    word += "D";
                }break;
                case 6:
                {
                    word += "DC";
                }break;
                case 7:
                {
                    word += "DCC";
                }break;
                case 8:
                {
                    word += "DCCC";
                }break;
                case 9:
                {
                    word += "CM";
                }break;
            }
        }


        int index3 = (num % 1000 % 100 / 10);
        if(index3 > 0)
        {
            switch(index3)
            {
                case 1:
                {
                    word += "X";
                }break;
                case 2:
                {
                    word += "XX";
                }break;
                case 3:
                {
                    word += "XXX";
                }break;
                case 4:
                {
                    word += "XL";
                }break;
                case 5:
                {
                    word += "L";
                }break;
                case 6:
                {
                    word += "LX";
                }break;
                case 7:
                {
                    word += "LXX";
                }break;
                case 8:
                {
                    word += "LXXX";
                }break;
                case 9:
                {
                    word += "XC";
                }break;
            }
        }


        int index4 = (num % 1000 % 100 % 10);

        if(index4 > 0)
        {
            switch(index4)
            {
                case 1:
                {
                    word += "I";
                }break;
                case 2:
                {
                    word += "II";
                }break;
                case 3:
                {
                    word += "III";
                }break;
                case 4:
                {
                    word += "IV";
                }break;
                case 5:
                {
                    word += "V";
                }break;
                case 6:
                {
                    word += "VI";
                }break;
                case 7:
                {
                    word += "VII";
                }break;
                case 8:
                {
                    word += "VIII";
                }break;
                case 9:
                {
                    word += "IX";
                }break;
            }
        }
        
        return word;
    }
};

int main()
{
    Solution solution;

    std::vector<int> sourceValue{3, 4, 5, 9, 58, 1994, 3999};

    for (auto it = sourceValue.begin(); it != sourceValue.end(); ++it)
    {
        std::cout << *it << " " << solution.intToRoman(*it) << std::endl;
    }
    
    return 0;
}