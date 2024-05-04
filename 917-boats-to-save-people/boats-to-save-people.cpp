class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());
        int k = limit;

        int i = 0, j = n-1;
        int count = 0;

        while(i<=j){

            int sum = (people[i] + people[j]);
            if(sum <= limit){
                count++;
                i++;
                j--;
            }
            else{
                count++;
                j--;
            }
                     

        }
        return count;
    }
};