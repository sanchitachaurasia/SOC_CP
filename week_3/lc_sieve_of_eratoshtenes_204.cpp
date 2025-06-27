class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);
        if(n==0 || n==1) return 0;
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                count++;
                for(int j=i*2;j<n;j=j+i){
                    isprime[j]=false;
                }
            }
        }
        return count;
    }
};
