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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int N = findSize(head);
        ListNode node(0);
        ListNode* dummy = &node;
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i=0;i<n+1;i++) first = first->next;
        
        while(first){
            first = first->next;
            second = second->next;
        }
        ListNode* del = second->next;
        second->next = second->next->next;
        delete del;
        return dummy->next;

    }


    int findSize(ListNode* head){
        int ans = 0;
        ListNode* temp = head;
        while(!temp){
            temp = temp->next;
            ans++;
        }
        return ans;
    }
};
