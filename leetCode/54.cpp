#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxCount;
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.size() <= 0)
        {
            return result;
        }
        maxCount = matrix.size() * matrix[0].size();
        display(matrix, 1, result, 0);

        return result;
    }

private:
    void display(vector<vector<int>> &matrix, int count, vector<int> &result, int curCount)
    { //1,2,3, 6,9, 8, 7,4,5   [1,2,3,4, 8,12,11, 10,9,5, 6,7]
        // 向右
        int col = 0;
        int row = 0;
        int maxRow = 0;
        int maxCol = 0;

        maxCol = matrix[0].size() - count + 1;
        row = count - 1;

        for (col = count - 1; col < maxCol; ++col)
        {
            if (curCount >= maxCount)
            {
                return;
            }
            result.push_back(matrix[row][col]);

            ++curCount;
        }

        maxRow = matrix.size() - count + 1;
        col = matrix[0].size() - count;
        for (row = count; row < maxRow; ++row)
        {
            if (curCount >= maxCount)
            {
                return;
            }
            result.push_back(matrix[row][col]);
            ++curCount;
        }

        maxCol = count - 1;
        row = matrix.size() - count;
        for (col = matrix[0].size() - count - 1; col >= maxCol; --col)
        {
            if (curCount >= maxCount)
            {
                return;
            }

            result.push_back(matrix[row][col]);
            ++curCount;
        }

        col = count - 1;
        for (row = matrix.size() - count - 1; row >= count; --row)
        {
            if (curCount >= maxCount)
            {
                return;
            }
            result.push_back(matrix[row][col]);
            ++curCount;
        }

        if (curCount >= maxCount)
            return;

        display(matrix, count + 1, result, curCount);
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    Solution solution;
    auto result = solution.spiralOrder(matrix);

    for (auto it : result)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;

    return 0;
}
