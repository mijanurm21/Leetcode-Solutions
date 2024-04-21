class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        for(int i = 0; i<word.size(); i++){
            if(isupper(word[i]) && mp.find(word[i]) == mp.end()) mp[word[i]] = i;
            if(islower(word[i])) mp[word[i]]=i;
        }


        int count = 0;


        for(auto it: mp){            
            if(islower(it.first)){  // agr it.first lowercase m h
               if(mp.find(toupper(it.first)) != mp.end()){   //  agr mujhe it.first ka uppercase milta h to
                    if(it.second < mp[toupper(it.first)]) count++;

               }
            } 
        }
        return count;
    }
};