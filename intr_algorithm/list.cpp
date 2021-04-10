#include <vector>
#include <iostream>

using namespace std;

class List
{
public:
    List(int dataCount)
    {
        if (dataCount <= 0)
        {
            return;
        }

        m_Key.resize(dataCount);
        m_Next.resize(dataCount);
        m_Prev.resize(dataCount);
        m_Head = -1;
        m_Free = -1;
        m_DataCount = dataCount;

        Init();
    }

    bool Insert(int value)
    {
        if (m_Free < 0)
        {
            return false;
        }

        int index = m_Free;
        m_Free = m_Next[index];

        if (m_Head >= 0)
        {
            m_Prev[m_Head] = index;
        }

        m_Key[index] = value;
        m_Prev[index] = -1;
        m_Next[index] = m_Head;
        m_Head = index;

        return true;
    }

    void Remove(int value)
    {
        int index = m_Head;
        while (index >= 0)
        {
            if (value != m_Key[index])
            {
                index = m_Next[index];
                continue;
            }

            int nextIndex = m_Next[index];
            int preIndex = m_Prev[index];
            if (preIndex >= 0)
            {
                m_Next[preIndex] = m_Next[index];
            }
            else
            {
                m_Head = nextIndex;
            }

            if (nextIndex >= 0)
            {
                m_Prev[nextIndex] = preIndex;
            }

            // 把index节点放到free中
            m_Next[index] = m_Free;
            m_Free = index;

            return;
        }
    }

    void Print()
    {
        int index = m_Head;
        while (index >= 0)
        {
            std::cout << m_Key[index] << std::endl;
            index = m_Next[index];
        }
    }

private:
    void Init()
    {
        m_Free = 0;
        for (size_t i = 0; i < m_DataCount - 1; i++)
        {
            m_Next[i] = i + 1;
        }

        m_Next[m_DataCount - 1] = -1;
    }

    int m_DataCount;
    int m_Head;
    int m_Free;
    std::vector<int> m_Key;
    std::vector<int> m_Next;
    std::vector<int> m_Prev;
};

int main(int argc, char **argv)
{
    List list(5);
    list.Insert(4);
    list.Insert(3);
    list.Insert(2);
    list.Insert(1);
    list.Print();

    list.Remove(2);
    list.Insert(5);


    list.Print();

    return 0;
}