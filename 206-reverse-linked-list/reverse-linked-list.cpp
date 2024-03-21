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
    ListNode* rev(ListNode* head){

        if(head->next == NULL){
            return head;
        }
        ListNode* newhead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;

        return rev(head);
    }

};
