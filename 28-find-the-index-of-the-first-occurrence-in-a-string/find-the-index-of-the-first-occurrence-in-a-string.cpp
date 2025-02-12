class Solution {
public:
    int strStr(string s, string needle) {
        int n = s.size();
        int m = needle.size();

        // applying rabin karp method

        int target = 0;

        for(int i = 0;i<m; i++){
            target+= ((needle[i]-'a')+1);
        }

        // cout<<target<<endl;

        // till now we have target 

        int i = 0, j = 0;
        int sum = 0;


        while(j<n){
            sum+= ((s[j]-'a')+1);

            if((j-i+1) == m){
                if(sum == target){
                    // cout<<"chla"<<endl;
                    int z = 0;
                    bool flag = true;
                    for(int k = i; k<i+m; k++){   // dono ko match kr rhe h
                        if(s[k]  != needle[z]){
                            flag = false;
                            break;
                        }
                        z++;
                    }
                    if(flag) return i;
                    else{
                        sum-=((s[i]-'a')+1);
                        i++;
                    }
                }
                else{  // euqal nhi h 
                    sum-=((s[i]-'a')+1);
                    i++;
                }
            }
            j++;
        }
        return -1;
    }
};