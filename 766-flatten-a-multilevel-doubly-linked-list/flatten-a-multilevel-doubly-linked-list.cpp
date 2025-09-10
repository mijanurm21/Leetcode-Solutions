/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        stack<Node*> st;
        Node* newHead = new Node(0);
        Node* p = newHead;
        st.push(head);

        while(!st.empty()){
            Node* temp = st.top();
            st.pop();

            p->next = temp;
            temp->prev = p;
            if(temp->next) st.push(temp->next);

            if(temp->child){
               st.push(temp->child);
               temp->child = NULL;
            }
            p = temp;
            
        }
        newHead->next->prev = nullptr;
        return newHead->next;
    }
};