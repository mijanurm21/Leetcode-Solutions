class Solution {
    // int check(vector<int>& nums, int x){
    //     return ;
    // }
public:
    int findMin(vector<int>& nums) {
      int n = nums.size();

      int l = 0, h = n-1;
	    
	    while(l<h){
	        int mid = (l+h)/2;
	        
	       // if(arr[l] < arr[mid] && arr[l] < arr[h]) return 0;
	        
	        if(nums[mid] > nums[h] ) l = mid+1;
	        else h = mid;
	    }
	    return  nums[l];
    }
};