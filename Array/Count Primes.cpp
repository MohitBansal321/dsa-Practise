// brute force (TLE after some cases)
class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        for(int i=2;i<n;i++){
            int flag=1;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
// Sieve_of_Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n,true);
        for(int i=2;i*i<n;i++){
            if(!isPrime[i]) continue;
            for(int j=i*i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
        int cnt=0;a
        for(int i=2;i<n;i++){
            if(isPrime[i]) cnt++;
        }
        return cnt;
    }
};