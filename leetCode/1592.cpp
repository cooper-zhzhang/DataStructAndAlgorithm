/*给你一个字符串 text ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证 text 至少包含一个单词 。

请你重新排列空格，使每对相邻单词之间的空格数目都 相等 ，并尽可能 最大化 该数目。如果不能重新平均分配所有空格，请 将多余的空格放置在字符串末尾 ，这也意味着返回的字符串应当与原 text 字符串的长度相等。

返回 重新排列空格后的字符串 。

 

示例 1：

输入：text = "  this   is  a sentence "
输出："this   is   a   sentence"
解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rearrange-spaces-between-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {

        std::vector<string> words;

        std::string word;
        int index = 0;
        int spaceCount = 0;

        while (index < text.length())
        {
            if(text[index] == ' ')
            {
                ++spaceCount;
                if(!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += text[index];
            }

            index++;
        }

        if (!word.empty())
        {
            words.push_back(word);
            word.clear();
        }

        int wordCount = words.size();
        int spaceCountInWord = 0;
        int leftSpaceCount = 0;
        if (wordCount > 1)
        {
            spaceCountInWord = spaceCount / (wordCount-1);
            leftSpaceCount = spaceCount % (wordCount-1);
        }
        else
        {
            spaceCountInWord = 0;
            leftSpaceCount = spaceCount;
        }
        
        
        std::string space(spaceCountInWord, ' ');
        std::string leftSpaceStr(leftSpaceCount, ' ');
        size_t i = 0;
        for (; i < wordCount-1; i++)
        {
            word += words[i];
            word += space;
        }

        word += words[i];
        word += leftSpaceStr;

        return word;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    std::vector<std::string> sourceWords;

    sourceWords.push_back("  this   is  a sentence ");
    sourceWords.push_back(" practice   makes   perfect");
    sourceWords.push_back("hello   world");
    sourceWords.push_back("  walks  udp package   into  bar a");
    sourceWords.push_back("a");

    std::string result = solution.reorderSpaces(sourceWords[4]);

    std::cout << "*" << sourceWords[4] << "*" << std::endl;
    std::cout << "*" << result << "*" << std::endl;

    // for (size_t i = 0; i < sourceWords.size(); i++)
    // {
    //     std::string result = solution.reorderSpaces(sourceWords[i]);
    //     std::cout << "*" << sourceWords[i] << "*" << std::endl;
    //     std::cout << "*" << result << "*" << std::endl;
    // }

    return 0;
}