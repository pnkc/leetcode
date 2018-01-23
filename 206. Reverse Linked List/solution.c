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
        if(!head || !head->next)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }    
        ListNode* prev=NULL;
        ListNode* cur=head;
        while(cur != NULL) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
                
        }
        return prev;
        
    }
};
