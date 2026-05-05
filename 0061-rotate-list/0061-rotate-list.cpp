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
ListNode*findkthnode(ListNode* head, int k){
    ListNode* temp = head;
    int cnt = 1; 
    while(cnt < k){
        cnt++;
        temp = temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode* temp = head;
        int l = 1;
        while(temp->next){
            l++;
            temp = temp->next;
        }
        if(k%l == 0) return head;
        k = k%l;
        temp->next = head;
        ListNode* newlastnode = findkthnode(head, l-k);
        head = newlastnode->next;
        newlastnode ->next = NULL;

        return head;
    }
};