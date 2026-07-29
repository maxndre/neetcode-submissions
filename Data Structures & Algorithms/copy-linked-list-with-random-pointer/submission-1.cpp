/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) { return nullptr; }
        
        map<Node*, Node*> link;

        Node* start_head = head;

        Node* start = new Node(head->val);
        Node* current = start;
        Node* suivant = nullptr;
        link[head] = current;
        head = head->next;
        


        while (head != nullptr) {
            suivant = new Node(head->val); // head actual value
            current->next = suivant; // we give it to current
            current = current->next; // and current make a step to get in head

            link[head] = current;
            
            head = head->next; // head make a step

        }


        head = start_head;
        current = start;
        while (head != nullptr) {
            current->random = link[head->random];
            current = current->next; // and current make a step to get in head
            head = head->next; // head make a step

        }
        return start;

        
        
    }
};
