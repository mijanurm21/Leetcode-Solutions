class Solution {
public:
    bool solve(vector<int>& arr, int m, int k, int mid){
        int n = arr.size();

        int count = 0, kitna = 0;

        for(int i = 0; i<n; i++){
            if(arr[i] <= mid){
                count++;
            }
            else{
                kitna+=(count/k);
                count = 0;
            }
        }
        kitna+=(count/k);
        return kitna>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();

        long long val = m * 1ll * k * 1ll;

        if(val > n) return -1;

        int h = *max_element(arr.begin(), arr.end());

        int l = *min_element(arr.begin(), arr.end());;

        while(l<=h){
            int mid = (l+h)/2;

            if(solve(arr, m,k,mid)){
                // ans = mid;
                h = mid-1;
            }
            else l = mid+1;
             


        }
        return l;
    }
};