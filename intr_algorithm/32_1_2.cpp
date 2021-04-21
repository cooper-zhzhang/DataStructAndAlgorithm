/*
 * =====================================================================================
 *
 *       Filename:  32_1_2.cpp
 *
 *    Description: p 中不包换重复的字符串 
 *
 *        Version:  1.0
 *        Created:  2021年04月21日 22时03分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cooper (陆沉), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>

using namespace std;

int str_str(const string &t, const string &p)
{
    int t_index = 0;
    int p_index = 0;
    while(t_index < t.size())
    {
        if(t[t_index] == p[p_index])
        {
            t_index ++;
            p_index ++;
        }
        else
        {
            //向后移动
            if(p_index == 0)
                t_index ++;
            p_index = 0;
        }

        if(p_index >= p.size())
        {
            return t_index-p_index;
        }
    }

    return -1;
}

int main()
{
    std::cout << 
        str_str("sdfababc", "abc") << std::endl;

    return 0;
}
