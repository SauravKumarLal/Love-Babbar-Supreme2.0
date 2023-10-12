//NAIVE APPROACH

// class Solution {
// public:

//     bool isPrime(int n){
//         if(n == 0 || n==1) 
//             return false;
//         for(int i=2; i<n; i++){
//             if(n%i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }

//     int countPrimes(int n) {
//         int count=0;
//         for(int i=0; i<n; i++){
//             if(isPrime(i))
//                 count++;
//         }
//         return count;
//     }
// };

//sqrt APPROACH

// class Solution {
// public:

//     bool isPrime(int n){
//         if(n == 0 || n==1) 
//             return false;
//         for(int i=2; i<=sqrt(n); i++){
//             if(n%i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }

//     int countPrimes(int n) {
//         int count=0;
//         for(int i=0; i<n; i++){
//             if(isPrime(i))
//                 count++;
//         }
//         return count;
//     }
// };


// SIEVE OF ERATOTHENES

class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1)
            return 0;
        vector<bool> prime (n,true);
        prime[0] = prime[1] = false;

        int count=0;

        for(int i=2; i<n; i++){
            if(prime[i]){
                count++;
                int j=2*i;
                while(j<n){
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return count;
    }
};