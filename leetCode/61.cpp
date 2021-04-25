/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
        {
            return NULL;
        }

        int nodeCount = 0;
        ListNode* temp = head;
        ListNode *endNode = NULL;
        while(temp)
        {
            ++nodeCount;
            endNode = temp; 
            temp = temp->next;
        }


        k = k % nodeCount;
        if(k == 0)
        {
            return head;
        }

        ListNode* pChangeNode = head;
        int i = 1;
        while(i++ < nodeCount-k)
        {
            pChangeNode = pChangeNode->next;
        }

        ListNode* pNewHead = pChangeNode->next;
        pChangeNode->next = NULL;
        endNode->next = head;
         
        return pNewHead;

    }
};