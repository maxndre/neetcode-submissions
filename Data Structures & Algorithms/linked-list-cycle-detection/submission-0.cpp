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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;

        while (head != nullptr) {
            head = head->next;
            if (head == nullptr) {
                return false;
            }
            head = head->next;
            slow = slow->next;

            if (head == slow) {
                return true;
            }
        }

        return false;


        
    }
};
