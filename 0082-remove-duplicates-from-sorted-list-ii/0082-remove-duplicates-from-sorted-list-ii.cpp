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
        if(!head || !head->next) return head; 

        ListNode* dummy = new ListNode(-101);
        ListNode* temp = head; 
        ListNode* ntemp = dummy;
        map<int, int>mp; // node, cnt 
        while(temp){
            mp[temp->val]++;
            temp= temp->next; 
        }
        for(auto it: mp){
            if(it.second == 1){
                ntemp->next = new ListNode(it.first);
                ntemp = ntemp->next; 
            } 
        }
        return dummy->next; 
    }
};