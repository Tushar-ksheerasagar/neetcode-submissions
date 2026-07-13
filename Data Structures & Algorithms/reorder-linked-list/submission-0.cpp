class Solution {
   public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    void merge(ListNode* first, ListNode* second) {
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* middle = findMiddle(head);
        ListNode* second = reverse(middle->next);

        middle->next = nullptr;

        merge(head, second);
    }
};