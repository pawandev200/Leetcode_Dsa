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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(-101);
        // dummy->next = head;
        ListNode* temp = head;
        ListNode* ntemp = dummy;

        while (temp) {
            if (temp->val < x) {
                ntemp->next = new ListNode(temp->val);
                ntemp = ntemp->next;
                temp = temp->next;
            } else
                temp = temp->next;
        }
        temp = head;
        while (temp) {
            if (temp->val >= x) {
                ntemp->next = new ListNode(temp->val);
                ntemp = ntemp->next;
                temp = temp->next;
            } else
                temp = temp->next;
        }
        return dummy->next;
    }
};