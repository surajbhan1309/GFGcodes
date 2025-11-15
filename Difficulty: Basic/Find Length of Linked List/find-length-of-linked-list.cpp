/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        int count=1;
        Node* curr=head;
        while(curr->next){
            count++;
            curr=curr->next;
        }
        return count;
    }
};