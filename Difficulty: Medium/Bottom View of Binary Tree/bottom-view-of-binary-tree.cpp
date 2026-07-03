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
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        if(!root) return ans;
        while(!q.empty()){
            auto [node,hd]=q.front();
            q.pop();
            
            mp[hd]=node->data;
            
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        for(auto &x:mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};