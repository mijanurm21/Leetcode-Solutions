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
    void solve(ListNode* head, vector<int> &v){
        while(head){
            v.push_back(head->val);
            head = head->next;
            }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> vec;
        solve(head, vec);

        for (int start = 0; start < vec.size(); start++) {
            int sum = 0;
            for (int end = start; end < vec.size(); end++) {
                sum += vec[end]; // using sliding window to find the subarray with sum as zero
                if (sum == 0) {
                    for (int i = start; i <= end; i++) {
                        vec[i] = 0; // making all the values in the range (start,end) to zero 
                    }
                    break;
                }
            }
        }

        ListNode ans(0);
        ListNode* a = &ans;

        for(int i = 0; i<vec.size(); i++){
            if(vec[i] != 0){
                a->next = new ListNode(vec[i]);
                a = a->next;
            }
        }
        a->next = nullptr;
        return ans.next;
    }
};