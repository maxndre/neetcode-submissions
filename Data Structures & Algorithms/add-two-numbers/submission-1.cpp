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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* solution = new ListNode(0);
        ListNode* suivant;
        ListNode* current = solution;

        int reste = 0;
        while (l1 != nullptr || l2 != nullptr) {

            if (l1 == nullptr) {
                l1 = new ListNode(0);
            } else if (l2 == nullptr) {
                l2 = new ListNode(0);
            }

            if (l1->val + l2->val + reste >= 10) {
                suivant = new ListNode(l1->val + l2->val + reste - 10 );
                reste = 1;
            } else {
                suivant = new ListNode(l1->val + l2->val + reste);
                reste = 0;
            }
            current->next = suivant;
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;

        }

                            

        if (reste == 1) {
            suivant = new ListNode(1);
            current->next = suivant;
        }
            
        
        return solution->next;
        
    }
};
