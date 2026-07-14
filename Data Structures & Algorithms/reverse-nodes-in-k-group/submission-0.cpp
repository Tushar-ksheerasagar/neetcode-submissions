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
    ListNode * reverse(ListNode * head){
        ListNode * temp = head;
        ListNode * prev = 0;
        ListNode * front = 0;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front; 
        }
        return prev;
    }
    ListNode * getKth(ListNode * head , int k){
        while(head && k>0){
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode * dummy = new ListNode(0);
       dummy->next = head;
       ListNode * groupprev = dummy;
       while(true){
            ListNode * kth = getKth(groupprev , k);
            if(!kth) break;
            ListNode * groupnext = kth->next;
            kth->next = nullptr;
            ListNode * groupstart = groupprev->next;
            ListNode * newhead = reverse(groupstart);
            groupprev->next = newhead;
            groupstart->next = groupnext;
            groupprev = groupstart;
       }
       return dummy->next;
    }
};
