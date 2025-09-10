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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0);
        ListNode* prev = newHead;
        int carry  = 0;

        while(l1|| l2){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = num1 + num2 + carry;

            prev->next = new ListNode(sum%10);
            prev = prev->next;
            carry = sum/10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry>0) prev->next = new ListNode(carry);
        return newHead->next;
    }
};