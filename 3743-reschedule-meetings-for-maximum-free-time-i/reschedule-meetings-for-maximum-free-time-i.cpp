class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gap(1, startTime[0]);

        for(int i = 1; i<n; i++){
            gap.push_back(startTime[i] - endTime[i-1]);
        }
        gap.push_back(eventTime-endTime[n-1]);

        int maxi = 0;
        int sum = 0;
        for(int i = 0; i<gap.size(); i++){
            sum+=gap[i] ;
            if(i>=k+1) sum -= gap[i-(k+1)];
            maxi = max(maxi, sum);
        }
        return maxi;


    }
};