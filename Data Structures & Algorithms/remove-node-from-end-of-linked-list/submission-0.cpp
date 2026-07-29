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
        if (head->next == nullptr) { return nullptr; }

        ListNode* start = head;
        ListNode* tail = head;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        if (head == nullptr) {
            return start->next;
        }

        while (head->next != nullptr) {
            head = head->next;
            tail = tail->next;
        }

        tail->next = tail->next->next;
        return start;
    }
};
