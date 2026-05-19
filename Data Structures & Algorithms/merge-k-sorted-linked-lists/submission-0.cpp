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
        ListNode* head = nullptr;
        int n = lists.size();
        for(int i=1;i<n;i++){
            head = mergeTwo(lists[i-1],lists[i]);
            lists[i]= head;
        }
        return head;
    }

    ListNode* mergeTwo(ListNode* one,ListNode* two){
        ListNode node = ListNode();
        ListNode* dummy = &node;
        ListNode* temp = dummy;
        while(one && two){
            if(one->val >= two->val){
                temp->next = two;
                two = two->next;
            }
            else{
                temp->next = one;
                one = one->next;
            }
            temp = temp->next;
        }
        while(one){
            temp->next = one;
            one = one->next;
            temp = temp->next;
        }
        while(two){
            temp->next = two;
            two = two->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
