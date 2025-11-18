/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* newnode=new Node(x);
        if(!head) return newnode;
        
        Node* curr=head;
        int count=0;
        
        while(curr && count<p){
            curr=curr->next;
            count++;
        }
        if(!curr) return head;
        
        newnode->next=curr->next;
        newnode->prev=curr;
        if(curr->next) curr->next->prev=newnode;
        curr->next=newnode;
        
        return head;
    }
};