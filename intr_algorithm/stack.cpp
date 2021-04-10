#include <vector>

using namespace std;


class Stack
{
    public:
    Stack()
    {
        m_Index = 0;
        m_Data.reserve(64);
    }

    bool Push(int value)
    {
        if (m_Index >= m_Data.size())
        {
            m_Data.push_back(value);
            ++m_Index;

            return true;
        }
        
        m_Data[m_Index++] = value;
    }


private:
    int m_Index;
    std::vector<int> m_Data;
};