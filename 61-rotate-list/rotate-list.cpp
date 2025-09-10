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
    int solve(ListNode* head){
        int count = 0;

        while(head){
            count++;
            head= head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) return head;

        int count = solve(head);      // got the count;
        k = k % count;             
        if (k == 0) return head; 


      
        ListNode* temp = head;

        for (int i = 1; i < count - k; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* tail = newHead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = head;
        return newHead;
    }
};