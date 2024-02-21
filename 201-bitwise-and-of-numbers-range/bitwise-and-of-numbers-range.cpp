class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    //     int sum = 0;
            int count = 0;
    //     for(int i=m;i<=n;i++)
    //                 sum&=i;        
	// 	      return sum;
        while(m!=n){
            n>>=1;
            m>>=1;
            count++;
        }
        return m<<count;
        }
};