class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char , int > mp1;

        for(int i = 0;i<p.size(); i++){
            mp1[p[i]]++;
        }

        unordered_map<char , int > mp2 ;

       

        vector<int>ans;
        int n = s.size();
        int k = p.size();
       int i = 0, j = 0;

       while(j<n){
        mp2[s[j]]++;

        if(j-i+1>k){
            mp2[s[i]]--;
            if(mp2[s[i]] == 0){
                mp2.erase(s[i]);
            }
            i++;
        }


        if(j-i+1 == k && mp1 == mp2) return true;        
        j++;
       }
       return false;
    }
};