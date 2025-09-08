/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *c = &dummy;
        ListNode *n = head;

        while (n) {
            if (n->val >= x) {          
                while (n && n->val >= x) {
                    c = n;
                    n = n->next;
                }
                if (!n) break; 

          
                ListNode* tail = n;
                while (tail->next && tail->next->val < x) tail = tail->next;

  
                c->next = tail->next;
                tail->next = prev->next;
                prev->next = n;

               
                prev = tail;
                n = c->next;
            } 
            else {
                prev = n;
                c = n;
                n = n->next;
            }
        }
        return dummy.next;
    }
    
};