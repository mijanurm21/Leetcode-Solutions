class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> fin;
        for(int i =0 ;i<nums.size();i++){
            int x = nums[i];
            fin.push_back(square(x));
        }
        sort(fin.begin(),fin.end());
        return fin;
    }

    int square(int x){
        int sq = x*x;
        return sq;
    }
};