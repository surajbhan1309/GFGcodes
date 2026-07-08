/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node *successor = nullptr;
        
        while (root != nullptr) {
            if (k->data >= root->data) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        // Return the successor's data, or -1 if no successor exists
        return (successor != nullptr) ? successor->data : -1;
    }
};
