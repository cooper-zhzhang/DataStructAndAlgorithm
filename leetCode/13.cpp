/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        std::map<std::string, int> tableMap{
            std::make_pair("M", 1000),
            std::make_pair("CM", 900),
            std::make_pair("D", 500),
            std::make_pair("CD", 400),
            std::make_pair("C", 100),
            std::make_pair("XC", 90),
            std::make_pair("L", 50),
            std::make_pair("XL", 40),
            std::make_pair("X", 10),
            std::make_pair("IX", 9),
            std::make_pair("V", 5),
            std::make_pair("IV", 4),
            std::make_pair("I", 1)
         };

        int value = 0;
         for (size_t i = 0; i < s.size(); )
         {
             std::string str1 = s.substr(i, 1);
             std::string str2 = s.substr(i, 2);
            auto it = tableMap.find(str2);
             if (it != tableMap.end())
             {
                value += it->second;
                i += 2;
                continue;
             }

            it = tableMap.find(str1);
            value += it->second;
            i += 1;
            
         }

         return  value;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> sourceStr;

    sourceStr.push_back("MCMXCIV");
    sourceStr.push_back("LVIII");
    sourceStr.push_back("IX");
    sourceStr.push_back("IV");
    sourceStr.push_back("III");

    Solution soul;

    for (auto it : sourceStr)
    {
        std::cout << it << " " << soul.romanToInt(it) << std::endl;
    }

    return 0;
}

