class Solution {
public:
int solve(vector<int>&arr, int pages){
    int stu = 1;
    long long pagestudent = 0;
    int n = arr.size();

    for(int i = 0; i<n;i++){
        if(pagestudent+arr[i] <= pages){
            pagestudent+=arr[i];
        }
        else{
            stu+=1;
            pagestudent =arr[i];
        }
    }
    return stu;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int l = *max_element(arr.begin(), arr.end());

    int h = accumulate(arr.begin(), arr.end(), 0);

    while(l<=h){
        int mid = (l+h)/2;

        int noofstudent = solve(arr, mid);

        if(noofstudent > m) l = mid+1;
        else h =mid-1;
    }
    return l;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};