class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(5,0);

        // b = 0, a = 1, l = 2, o = 3, n = 4,

        for(int i = 0;i<text.size(); i++){
            if(text[i] == 'b'){
                v[0]++;
            }
            else if(text[i] == 'a'){
                v[1]++;
            }
            else if(text[i] == 'l'){
                v[2]++;
            }
            else if(text[i] == 'o'){
                v[3]++;
            }
            else if(text[i] == 'n'){
                v[4]++;
            }
        }

        v[2] = v[2]/2;
        v[3] = v[3]/2;

        return *min_element(v.begin(), v.end());
    }
};