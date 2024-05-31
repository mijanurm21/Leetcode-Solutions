class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hour) {
        sort(piles.begin(), piles.end());

        int n = piles.size();

        int ans = piles[n-1];

        int l = 1, h = piles[n-1];

        while(l<=h){
            int mid = l + (h-l)/2;
            long long total_time = 0;
            for(int i = 0; i<n; i++){
                long long hours = static_cast<int>(ceil(static_cast<double>(piles[i]) / mid));
                total_time += hours;
            }

            

            if(total_time > hour) l = mid+1;
            else h = mid-1;
        }
        return l;
    }
};