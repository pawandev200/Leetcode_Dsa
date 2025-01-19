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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp) >q(comp);

        for(auto it: lists) {
            if(it) q.push(it);
        }
        if(q.empty()) return NULL;
  
        ListNode *dummy  = new ListNode(-1);
        ListNode *temp = dummy;
        while(!q.empty()){
            ListNode *nextnode = q.top();
            q.pop();
            temp ->next = nextnode;
            temp = temp->next;
            if(nextnode->next) q.push(nextnode->next);
        }
        return dummy->next;
    }
};