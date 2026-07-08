/* Definition for Node class
Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int findMaxFork(Node* root, int k) {
        int floor_val = -1;
        
        while (root != nullptr) {
            if (root->data == k) {
                return root->data;
            }
            
            if (root->data > k) {
                root = root->left;
            } 
            
            else {
                floor_val = root->data;
                root = root->right;
            }
        }
        
        return floor_val;
    }
};
