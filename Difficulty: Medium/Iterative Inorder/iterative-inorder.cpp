/*
Definition for Node class
Node {
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
    vector<int> inOrder(Node* root) {
        vector<int> result;
        Node* current = root;

        while (current != nullptr) {
            // Case 1: If there is no left child, visit this node and move right
            if (current->left == nullptr) {
                result.push_back(current->data);
                current = current->right;
            } 
            // Case 2: There is a left child
            else {
                // Find the inorder predecessor of current
                Node* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // If the temporary link doesn't exist, create it
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } 
                // If the link already exists, break it, visit the node, and move right
                else {
                    predecessor->right = nullptr;
                    result.push_back(current->data);
                    current = current->right;
                }
            }
        }
        return result;
    }
};