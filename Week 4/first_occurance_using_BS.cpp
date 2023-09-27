#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int> &nums, int n, int target){
    int s=0, e=n-1;
    int index=0;
    while(s<=e){
        // int mid = (s+e)/2;
        int mid = s+ (e-s)/2;  //INTEGER WON'T overflow!
        if(target == nums[mid]){
            index = mid;
            e=mid-1; 
            // s=mid+1; -- only change for last occurance
        }
        else if(target>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return index;
}

int main(){
    int n;
    vector<int> nums = {10, 20, 20, 30, 30, 30, 30, 40, 40, 50};
    cout<<"First Occurance is at index: "<<firstOccur(nums, 10, 30);
}