
 
struct TreeNode {
    bool isTerminal;
    map<char, TreeNode*> next;

    TreeNode() : isTerminal(false), next() {}
};




class PrefixTree {
private:
    TreeNode* root; 


public:
    PrefixTree() {
        // we can do a tree (wow)
        // we get a root ROOT
        // and then bellow it the first letter of every word we have
        
        // we can also store word entierly, and if we see a new word that is a prefix, we add the prefix
        // saving letter one by one would be very inneficient
        // if we see a new word that have a common prefi, we create the prefix and put both word bellow it 
        root = new TreeNode();

    }
    
    void insert(string word) {

        TreeNode* current = root;

        for (char c : word) {
            if (!current->next.contains(c)) {
                current->next[c] = new TreeNode();
                current = current->next[c];
            } else {
                current = current->next[c];
            }
        }

        current->isTerminal = true;

    }
    
    bool search(string word) {

        TreeNode* current = root;

        for (char c : word) {
            if (!current->next.contains(c)) {
                return false;
            } else {
                current = current->next[c];
            }
        }

        return current->isTerminal;
        
    }
    
    bool startsWith(string prefix) {

        TreeNode* current = root;

        for (char c : prefix) {
            if (!current->next.contains(c)) {
                return false;
            } else {
                current = current->next[c];
            }
        }

        return true;

    }
};
