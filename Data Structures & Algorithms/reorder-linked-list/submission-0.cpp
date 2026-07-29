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
    void reorderList(ListNode* head) {
        ListNode* cursor = head;



        stack<ListNode*> myStack;
        ListNode* backup;


        while (cursor->next != nullptr) {
            myStack.push(cursor);
            cursor = cursor->next;
        }

        while (cursor != head) {
            backup = head->next;
            head->next = cursor;
            head = backup;
            if (cursor == head) { break; }
            cursor->next = head;
            cursor = myStack.top();
            myStack.pop();

        }
        head->next = nullptr;

        return ;
         
    }
};
