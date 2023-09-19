#include<iostream> 
using namespace std; 

class Solution
{
public:
    int setKthBit(int n, int k)
    {
        // Write Your Code here
        int val = 1<<k;
        return (val | n);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
