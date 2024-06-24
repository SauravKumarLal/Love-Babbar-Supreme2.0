#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //recurssion
    int solveUsingRecurssion(int n){
        if(n == 0 || n == 1)
            return n;
        int ans = solveUsingRecurssion(n-1) + solveUsingRecurssion(n-2);
        return ans;
    }

    //DP - top down approach
    //Rec + Memoisation
    int solveUsingMem(int n, vector<int>& dp){
        //Base Case
        if(n == 0 || n == 1)
            return n;
        //Ste 3: if answer already exists then return ans
        if(dp[n] != -1)
            return dp[n];

        //Step 2: Store ans in dp array instead of answer array
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }





    int solveUsingTabulation(int n){
        //step 1: create a dp array
        vector<int> dp(n+1, -1);

        //step 2: analyse base case & fill dp array
        dp[0] = 0;
        if(n==0) return 0; 
        dp[1] = 1;

        //step 3: fill the remaining dp array
        //size = n+1
        //index: 0->n
        //index fill ho chuka hai -> 0 & 1
        //bacha konsa index = 2->n
        for(int i=2; i<=n; i++){
            //copy paste the recurssive logic
            //replace recurssive calls with dp array
            //make sure dp array is using looping variable i
            dp[i] = dp[i-1] + dp[i-2];
        }  
        return dp[n];
    }

    int fib(int n) {
        // int ans = solveUsingRecurssion(n);
        // return ans;

        //Step 1: Create dp array
        // vector<int> dp(n+1, -1);
        // return solveUsingMem(n, dp);

        int ans = solveUsingTabulation(n);
        return ans;
    }
    
};


int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solution.fib(n);
    cout << "Fibonacci number is: " << result << endl;
    return 0;
}