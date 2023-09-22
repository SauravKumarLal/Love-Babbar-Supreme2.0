#include<iostream>
#include<vector>
using  namespace std;

//METHOD 1
/*
int findPivot(int arr[], int n){
    for(int i=0; i<n; i++){
        int lsum=0, rsum=0;
        for(int j=0; j<i; j++){
            lsum += arr[j];
        }

        for(int j=i+1; j<n; j++){
            rsum += arr[j];
        }

        if(lsum == rsum)
            return i;
    }
    return -1;
}
*/
//METHOD 2
int prefixSumApproach(vector<int>& nums){
    int n=nums.size();
    vector<int>lsum(nums.size(), 0);
    vector<int>hsum(nums.size(), 0);
    for(int i=1; i<nums.size(); i++){
        lsum[i] = lsum[i-1] + nums[i-1];
    }
    for(int i=n-2; i>=0; i--){
        hsum[i] = hsum[i+1] + nums[i+1];
    }

    for(int i=0; i<n; i++){
        if(lsum[i] == hsum[i])
            return i;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    int a;
    vector<int> nums;
    for(int i=0; i<n; i++){
        cin>>a;
        nums.push_back(a);
        // cin>>nums[i];
    }
    cout<< prefixSumApproach(nums);
    return 0;
}