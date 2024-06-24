#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCutsFn(int n, int x, int y, int z, vector<int>& dp)
    {
        //Your code here
        if(n==0) return 0;
        if(n<0) return -1;
        
        if(dp[n] != INT_MIN) 
            return dp[n];

        int opt1 = 1+maximizeTheCutsFn(n-x, x, y, z, dp);
        int opt2 = 1+maximizeTheCutsFn(n-y, x, y, z, dp);
        int opt3 = 1+maximizeTheCutsFn(n-z, x, y, z, dp);

        dp[n] = max(opt3, max(opt1, opt2));

        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z){
        vector<int> dp(n+1, -1);
        int ans = maximizeTheCutsFn(n, x, y, z, dp);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;
    }
	return 0;
}