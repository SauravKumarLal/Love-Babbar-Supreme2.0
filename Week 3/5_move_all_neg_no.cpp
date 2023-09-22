//Method 1 is sorting
//Method 2 is Dutch National Flag Algo.
#include<iostream>
#include<vector>
using namespace std;

void moveAllNegToLeft(vector<int>&nums){
    int n=nums.size();
    int i=0, j=0;
    while(i<nums.size()){
        if(nums[i]<0){
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else{
            i++;
        }
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
    moveAllNegToLeft(nums);
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
}