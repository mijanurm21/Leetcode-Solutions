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
    ListNode* reverse(ListNode* head) {
            if(head == NULL) return NULL;
            ListNode *prev = NULL, *curr = head , *nxt = head->next;

            while(curr){
                curr->next = prev;
                prev = curr;
                curr = nxt;
                if(nxt) nxt = nxt->next;
            }
            return prev;
        }
    ListNode* kthnode(ListNode* temp, int k){
        while(k>1 && temp != NULL){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *prevnode= NULL;

        while(temp){
            ListNode *kthNode = kthnode(temp, k);

            if(kthNode == NULL){
                if(prevnode) prevnode->next = temp;
                break;
            }

            ListNode *next = kthNode->next;
            kthNode->next = NULL;

            ListNode* rev = reverse(temp);

            if(temp == head){
                head = rev;

            }
            else{
                prevnode->next = rev;
            }
            prevnode = temp;
            temp = next;

        }
        return head;
    }
};