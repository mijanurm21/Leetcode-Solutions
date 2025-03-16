class Solution {
public:
    bool check(vector<int> ranks, int cars, long long mid){
        long long count = 0;
        // cout<<"yes"<<endl;
        for(int i = 0; i<ranks.size(); i++){
            int can = sqrt(mid/ranks[i]);
            count+=can;
        }

        return count>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long maxi = *max_element(ranks.begin(), ranks.end());
        long long mini = *min_element(ranks.begin(), ranks.end());

        long long l = 0, h = maxi * (1LL * cars * cars);
       
        long long ans = 0;

        while(l<=h){
            long long mid = (l+h)/2;
            cout<<mid<<endl;
            if(check(ranks,cars, mid)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};