#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int *arr, int n, int index){
    if(index>=n){
        return;
    }
    cout<<arr[index]<<" ";
    index++;
    printArray(arr, n, index);
}

bool searchArray(int *arr, int n, int x, int index){
    if(index>=n) return false;
    if(arr[index] == x) return true;
    // index++;
    searchArray(arr, n, x, index+1);

    return true; //remove
}

void minNoInArray(int *arr, int n, int index, int &mini){ //mini should be pass by value, cuz pass by reference mei copy banti hai
    if(index>=n) return;

    mini = min(mini, arr[index]);

    minNoInArray(arr, n, index+1, mini);
}

//insert all even elements of arr in vector
void solve(int *arr, int n, int index, vector<int> &ans){
    if(index>=n) return;
    if(arr[index]%2 == 0) ans.push_back(arr[index]);
    solve(arr, n, index+1, ans);
}

//double all ele of array
void doublee(int *arr, int n, int index){
    if(index>n) return;
    arr[index] = arr[index]*2;
    doublee(arr, n, index+1);
}

//max no in array
void maxNoInArray(int *arr, int n, int index, int &maxi){ 
    if(index>=n) return;

    maxi = max(maxi, arr[index]);

    maxNoInArray(arr, n, index+1, maxi);
}

//print index of all occurance of array
void occurance(int *arr, int n, int index, int target){
    vector<int> ans;
    if(index>=n) return;
    if(target == arr[index]){
        ans.push_back(index);
    }
    occurance(arr, n, index+1, target);
    for(auto num: ans)
        cout<<num<<" ";
}

//print all the digits of a number
void printDigits(int n, vector<int> &v){
    if(n==0) return;

    int rem = n%10;
    // n = n/10;

    printDigits(n/10, v);
    // cout<<rem<<endl;
    v.push_back(rem);

}

int main(){
    int arr[] = {1, 2, 4, 4, 5, 6};
    // cout<<searchArray(arr, 6, 9, 0);
    
    // int mini = INT_MAX;
    // minNoInArray(arr, 6, 0, mini);
    // cout<<"The minimum number in array: "<<mini;
    
    // vector<int> ans;
    // solve(arr, 6, 0, ans);
    // for(auto nums: ans){
    //     cout<<nums<<" ";
    // }

    // doublee(arr, 6, 0);
    // for(auto num: arr){
    //     cout<<num<<" ";
    // } 

    // int maxi = INT_MIN;
    // maxNoInArray(arr, 6, 0, maxi);
    // cout<<"The maximum number in array: "<<maxi;

    // occurance(arr, 6, 0, 4);
    // return 0;

    vector<int> v;
    printDigits(436201, v);         
    for(auto num: v){
        cout<<num<<endl;
    }
}


