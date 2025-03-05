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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp; 
        int ps =0; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        // first filling the map and calculating the ps  
        while(temp){
            ps+=temp->val;
            mp[ps] = temp;  
            temp = temp->next; 
        }
        temp = dummy;
        ps = 0; 
        while(temp){
            ps+=temp->val;
            temp->next = mp[ps]->next;
            temp = temp->next;  
        }
        return dummy->next;   
    }
};