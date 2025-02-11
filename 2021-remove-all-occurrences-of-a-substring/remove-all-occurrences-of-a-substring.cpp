class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        if(m>n) return s;
        

        stack<char> s1, s2;
        int i = 0, j = m-1;

        while(i<n){
            s1.push(s[i]);

            if(s1.top() ==  part[m-1]){
                
                int flag = false;
                while(j>=0 && !s1.empty() && s1.top() == part[j]){
                    s2.push(s1.top());
                    s1.pop();
                    if(j == 0) {
                        flag = true;
                        break;
                    }
                    j--;
                }
                if(flag){ // mtlb part mil gya
                
                    while(!s2.empty()){                        
                        s2.pop();
                    }
                    j = m-1;
                }
                else{
                    
                    while(!s2.empty()){
                        s1.push(s2.top());
                        s2.pop();
                    }
                    j = m-1;
                }
            }
            i++;
        }

        string ans = "";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};