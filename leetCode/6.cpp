#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        // 一组可以容纳的数量
        int groupCapacity = numRows + numRows - 2;

        int strLength = s.length();

        // 计算多少个组
        int groupNums = strLength / groupCapacity;
        if (strLength % groupCapacity)
        {
            ++groupNums;
        }

        // 在一个组中有多少列
        int columnsInGroup = 1 + numRows - 2;

        //计算多少个列
        int allColumns = strLength / groupCapacity * columnsInGroup;
        int tem = strLength % groupCapacity;
        if (tem > 0)
        {
            ++allColumns;
        }
        tem -= numRows;
        if (tem > 0)
        {
            allColumns += tem;
        }

        std::string resultStr;

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < allColumns; ++j)
            {
                // 1先算出是在哪一个组
                int groupIndex = j / columnsInGroup;
                int pos = groupIndex * groupCapacity;

                int col = j % columnsInGroup;
                if (col == 0)
                {
                    pos += i;
                }
                else if (col == numRows - i - 1)
                {
                    // 有数据
                    pos += numRows;
                    pos += col;pos -= 1;
                }
                else
                {
                    // 判断这里有没有数据
                    continue;
                }

                if(pos < strLength)
                {
                    resultStr += s[pos];
                }
            }
        }
        return resultStr;
    }
};

int main(int argc, char **argv)
{

    Solution solution;

    std::string sourceStr = "PAYPALISHIRING";
    int rows = 2;

    std::string destStr =
        solution.convert(sourceStr, rows);

    std::cout << destStr << std::endl;

    return 0;
}

/*将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。*/