#include <iostream>
#include<algorithm>

using namespace std;


class Solution{
public:	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
//APPROACH 1
	    // for(int i=0; i<n; i++){
	    //     for(int j=i+1; j<n; j++){
	    //         if(arr[i]+arr[j] == x){
	    //             return true;
	    //         }
	    //     }
	    // }
	    // return false;

//APPROACH 2 and better one
        sort(arr, arr + n);
	    int l = 0;
        int h = n-1;
        while(l<h){
	       int sum = arr[l] + arr[h];
	       if(sum == x){
	           return true;
	       }
	       else if(sum > x){
	           h--;
	       }
	       else{
	           l++;
	       }
	   }
	   return false;
        
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends