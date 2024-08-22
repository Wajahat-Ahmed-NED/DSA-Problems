class Solution {
public:
    int reverse(int x) {
        // INT_MAX = 2147483647 // 2^31 - 1
        // INT_MIN = -2147483648 // -(2^31)


        int ans=0;
        while(x!=0){
            int pop = x % 10;
            x=x/10;
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && pop > 7)) {
                return 0; 
            }
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && pop < -8)) {
                return 0;  
            }
            ans=ans*10+pop;
        }

        // if(m<0) {
        //     cout<<"test"<<endl;
        //     ans=ans+;
        //     return ans;}
        return ans;

    }
};