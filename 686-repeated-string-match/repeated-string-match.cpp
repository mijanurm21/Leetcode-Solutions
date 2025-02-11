class Solution {
public:

    bool check(string a, string b){
        if(a.find(b)!=string::npos){
            return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count  = 1;
        string s = a;
        while(a.size() < b.size()){
            a+=s;
            count++;
        }
        if(check(a,b)) return count;
        if(check(a+s,b)) return count+1;
        return -1;
    }
};