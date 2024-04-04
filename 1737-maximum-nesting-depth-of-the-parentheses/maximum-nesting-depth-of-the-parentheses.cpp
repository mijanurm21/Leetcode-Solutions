class Solution {
public:
    int maxDepth(string s) {
        int depth=0, open =0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='(') open++;    // agr ( h to open++ else open-- and check which is max open or depth
            if(s[i]==')') open--;
            depth = max(depth,open);
        }
        return depth;
    }
};