class Solution {
public:
    string defangIPaddr(string address) {
        string temp = "";
        int n = address.size();

        for(int i = 0; i<n; i++){

            if(address[i] == '.'){
                temp.push_back('[');
                temp.push_back('.');
                temp.push_back(']');
            }
            else temp.push_back(address[i]);

        }
        return temp;
    }
};