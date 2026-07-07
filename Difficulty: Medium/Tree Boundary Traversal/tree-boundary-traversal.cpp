/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> res;

    bool isLeaf(Node* node) {
        return node && !node->left && !node->right;
    }

    void addLeft(Node* root) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur))
                res.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addLeaves(Node* root) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left);
        addLeaves(root->right);
    }

    void addRight(Node* root) {
        Node* cur = root->right;
        vector<int> temp;
        while (cur) {
            if (!isLeaf(cur))
                temp.push_back(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            res.push_back(temp[i]);
    }

    vector<int> boundaryTraversal(Node* root) {
        res.clear();
        if (!root) return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeft(root);
        addLeaves(root);
        addRight(root);

        return res;
    }
};