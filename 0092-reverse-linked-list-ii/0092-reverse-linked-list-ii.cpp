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
    ListNode* rev(ListNode* leftnode, ListNode* rightnode) {
        ListNode* prev = nullptr;
        ListNode* curr = leftnode;
        ListNode* end = rightnode->next; 

        while (curr != end) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev; 
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head || !head->next) return head; 

        ListNode* dummy = new ListNode(-5001);
        dummy->next = head; 
        ListNode* temp = dummy; 
         for (int i = 1; i < l; i++) temp = temp->next;

        ListNode* leftnode = temp->next;
        ListNode* rightnode = leftnode;

        for (int i = l; i < r; i++) rightnode = rightnode->next;

        ListNode* lnodes = rightnode->next;
        ListNode* revhead = rev(leftnode, rightnode);

        temp->next = revhead;
        leftnode->next = lnodes; 

        return dummy->next;  
    }
};