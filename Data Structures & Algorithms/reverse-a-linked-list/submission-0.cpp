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
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) { return nullptr; }

        ListNode* precedant = nullptr;
        ListNode* actuel = head;
        ListNode* suivant = actuel->next;


        while (actuel->next != nullptr) {
            actuel->next = precedant;

            precedant = actuel;
            actuel = suivant;
            suivant = suivant->next;


            //cout << suivant->val << " " << actuel->val << " " << precedant->val << "\n";

            

        }
        actuel->next = precedant;        
        return actuel;
        
    }
};




/*



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };



//int current_number = head->val;
//ListNode* the_next_node = head->next;
//head = head->next;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head -> next == nullptr) {return nullptr; }

        int current_number = head->val;

        ListNode* previous = new ListNode(current_number);

        while (true) {
            head = head->next;
            if (head->next == nullptr) { break; }
            cout << current_number << " ";
            
            current_number = head->val;
            previous = head;

            ListNode* head = new ListNode(current_number);

            head->next = previous; 


        }

        return head;



        
    }
};


*/