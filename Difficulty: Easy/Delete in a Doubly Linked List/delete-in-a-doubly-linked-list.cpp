/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
public:
    Node* delPos(Node* head, int x) {
        if (!head) return NULL;   // empty list
        
        Node* curr = head;

        // If deleting the first node (head)
        if (x == 1) {
            head = head->next;
            if (head) head->prev = NULL;
            delete curr;
            return head;
        }

        // Move to the x-th node
        int count = 1;
        while (curr && count < x) {
            curr = curr->next;
            count++;
        }

        // If position is invalid
        if (!curr) return head;

        // Delete the node
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;

        delete curr;
        return head;
    }
};
