
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = new ListNode(-1001);
        // prev->next = head;
        ListNode* t = prev; 
        ListNode* temp = head;

        while(temp){
            if(prev && prev ->val == temp->val){
                temp = temp->next; 
            }
            else {
                prev->next = temp; 
                temp = temp->next;
                prev = prev->next;  
            }
        }
        prev->next = nullptr; // unlinking the last node
        return t->next;  
    }
};