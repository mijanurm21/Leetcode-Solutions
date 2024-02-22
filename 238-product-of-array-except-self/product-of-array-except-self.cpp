class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                
        vector<int> fin(n);
        vector<int> lep(n);
        vector<int> rip(n);
        lep[0]=1;
        for(int i = 1; i<n; i++){
            lep[i] = lep[i-1] * nums[i-1];
        }

        rip[n-1]=1;
        for(int i = n-2; i>=0; i--){
            rip[i] = rip[i+1] * nums[i+1];
        }

        for(int i = 0; i<n; i++){
            fin[i] = lep[i] * rip[i];
        }
        return fin;
    }
};