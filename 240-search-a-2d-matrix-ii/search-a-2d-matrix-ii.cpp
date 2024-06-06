class Solution {
public:
    int bs(vector<int>&v, int m, int target){
        int l = 0, h = m-1;

        while(l<=h){
            int mid = (l+h)/2;

            if(v[mid] == target) return mid;
            else if(v[mid] > target) h = mid-1;
            else l =  mid+1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();

        int m = mat[0].size();

        for(int i = 0; i<n; i++){
            int ind = bs(mat[i], m, target);

            if(ind != -1) return true;
            else false;
        }
        return false;
    }
};