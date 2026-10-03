/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

void build(Node* copy, Node* nodeToCopy, unordered_map<int, Node*>& nodes) {

    //cout << "copy->val = " << copy->val << "\n";
    //cout << "nodeToCopy->val = " << nodeToCopy->val << "\n";
    //cout << "copy = " << copy << "\n";
    //cout << "nodeToCopy = " << nodeToCopy << "\n";

    Node* newNode;
    for (Node* nextNode : nodeToCopy->neighbors) {
        if (!nodes.contains(nextNode->val)) {
            // the node doesn't exist, we create it 
            newNode = new Node(nextNode->val);
            nodes[nextNode->val] = newNode;

            copy->neighbors.push_back(newNode);
            build(newNode, nextNode, nodes);
                

        } else {
            newNode = nodes[nextNode->val];

            copy->neighbors.push_back(newNode);
        }

        
        
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* output = new Node(node->val);
        
        unordered_map<int, Node*> nodes;
        nodes[node->val] = output;

        build(output, node, nodes);

        return output;
        
    }
};
