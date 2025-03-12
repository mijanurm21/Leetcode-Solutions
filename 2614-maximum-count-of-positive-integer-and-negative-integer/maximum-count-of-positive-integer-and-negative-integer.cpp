class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h= n-1;

        if(n == 1 && nums[0] < 0) return 1; 
        if(n == 1 && nums[0] > 0) return 1; 
        if(n == 1 && nums[0] == 0) return 0; 

        int ans;

        while(l<=h){
            int mid= (l+h)/2;

            if(nums[mid] >=0) {
                h = mid-1;
            }
            else l = mid+1;
        }

        int negative = l;
        int positive = 0;
        int i = l;

        if(nums[l] == 0){
            for(; i<n; i++){
                if(nums[i] == 0) continue;
                else break;
            }
        }
        positive = n-i;            

        // cout<<negative << " "<<positive<<endl;

        return max(negative, positive);
    }
};