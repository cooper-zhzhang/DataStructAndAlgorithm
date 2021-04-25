/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head ==  NULL)
        {
            return NULL;
        }

        ListNode *pNewHead = head;
        head = head->next;
        pNewHead->next = NULL;

        while(head)
        {
            ListNode *temp = head->next;
            head->next = pNewHead;
            pNewHead = head;
            head= temp;
        }

        return pNewHead;
    }
};