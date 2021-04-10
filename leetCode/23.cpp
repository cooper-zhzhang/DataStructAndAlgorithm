#include <vector>
#include <list>
#include <iostream>

using namespace std;

struct ListNode
{
    ListNode()
    {
        next = NULL;
    }

    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        size_t len = lists.size();

        ListNode *root = new ListNode;
        ListNode *tail = nullptr;

        root->next = nullptr;
        tail = root;
        //tail->next = NULL;

        while (true)
        {
            int minValue = INT_MAX;
            int updateIndex = -1;
            ListNode *pNode = nullptr;
            for (int i = 0; i < len; ++i)
            {
                // 不能使用下标
                pNode = lists[i];
                if (pNode == nullptr)
                {
                    continue;
                }

                if (pNode->val < minValue)
                {
                    updateIndex = i;
                    minValue = pNode->val;
                }
            }

            // 更新这个节点
            

            if (updateIndex < 0)
            {
                tail->next = nullptr;
                break;
            }

            tail->next = lists[updateIndex];
            lists[updateIndex] = lists[updateIndex]->next;
            tail = tail->next;
            tail->next = nullptr;

        }

        return root->next;
    }
};

ListNode* GetNewNode(int value)
{
    ListNode *pNode = new ListNode;
    pNode->val = value;
    pNode->next = nullptr;

    return pNode;
}

bool PushBackNode(ListNode *pNode, ListNode *newNode)
{
    if (pNode == nullptr)
    {
        return false;
    }

    while(pNode->next != nullptr) pNode = pNode->next;

    pNode->next = newNode;

    return true;
}

void Display(ListNode *pNode)
{
    while(pNode != nullptr)
    {
        std::cout << pNode->val << " ";
        pNode = pNode->next;
    }
        std::cout << std::endl;
}


int main(int argc, char **argv)
{

    //lists = [[1,4,5],[1,3,4],[2,6]]

    vector<ListNode*> vec;

    ListNode *root1 = GetNewNode(1);
    ListNode *newNode = GetNewNode(4);
    PushBackNode(root1, newNode);

    newNode = GetNewNode(5);
    PushBackNode(root1, newNode);
    PushBackNode(root1, nullptr);


    ListNode *root2 = GetNewNode(1);
    newNode = GetNewNode(3);
    PushBackNode(root2, newNode);
    newNode = GetNewNode(4);
    PushBackNode(root2, newNode);
    PushBackNode(root2, nullptr);

    ListNode *root3 = GetNewNode(2);
    newNode = GetNewNode(6);
    PushBackNode(root3, newNode);
    PushBackNode(root3, nullptr);

    vec.push_back(root1);
    vec.push_back(root2);
    vec.push_back(root3);

    vector<ListNode*> vec1;
    Solution  solution;
    ListNode *resultNode = solution.mergeKLists(vec);

    Display(resultNode);

    return 0;
}