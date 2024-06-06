class Solution {
public:
int maxi(vector<vector<int>> mat, int n, int m, int mid){
    int max_val = -1;
    int ind = -1;

    for(int i = 0; i<n; i++){
        if(mat[i][mid] > max_val){
            max_val = mat[i][mid];
            ind = i;
        }
    }
    return ind;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, h=m-1;

        while(l<=h){
            int mid = (l+h)/2;

            int ind = maxi(mat, n, m,mid);

            int left = mid-1 >=0 ? mat[ind][mid-1] : -1;
            int right = mid+1 <m ? mat[ind][mid+1] : -1;

            if(mat[ind][mid] > left && mat[ind][mid] > right){
                return {ind,mid};
            }

            else if(mat[ind][mid] < left){
                h = mid-1;
            }
            else l = mid+1;
            
        }
        return {-1,-1};
    }
};