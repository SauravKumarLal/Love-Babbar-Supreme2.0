#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void missingElement(vector<int>&nums){
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != i+1)
            cout<< i+1<<" ";
    }
}

int main(){
    int n, a;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        cin>>a;
        nums.push_back(a);
    }
    missingElement(nums);
}