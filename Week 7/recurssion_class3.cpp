#include<iostream>
#include<vector>
using namespace std;

//find if the array is sorted
bool checkSorted(int arr[], int size, int index){
    if(index>=size-1)
        return true;

    if(arr[index]>arr[index-1]){
        //aage check krna padega
        return checkSorted(arr, size, index+1);
    }
    else return false;
}

//Binary Search
int binarySearch(int arr[], int s, int e, int target){
    if(s>e) return -1;
    int mid=s+(e-s)/2;

    if(arr[mid] == target) return mid;

    else if(arr[mid]>target){
        return binarySearch(arr, s, mid-1, target);
    }
    else{
        s=arr[mid+1];
        return binarySearch(arr, mid+1, e, target);
    }
}

void findSubsequence(string str, string output, int index, vector<string>& ans){
    if(index >= str.size()){
        // cout<<output<<endl;
        ans.push_back(output);
        return;
    }
    char ch = str[index];

    //exclude
    findSubsequence(str, output, index+1, ans);

    //include
    output.push_back(ch);
    findSubsequence(str, output, index+1, ans);
}
 
int main(){
    //find if the array is sorted
    // int arr[] = {10, 20, 21, 40, 50};
    // int size=5;
    // int index=0;
    // bool isSorted = checkSorted(arr, size, index);
    // if(isSorted) cout<<"The array is sorted"<<endl;
    // else cout<<"The array is not sorted"<<endl;

    //binary search
    // int s=0, e=size-1;
    // int foundIndex = binarySearch(arr, s, e, 50);
    // if(foundIndex != -1)
    //     cout<<"target found at: "<<foundIndex<<endl;
    // else
    //     cout<<"target not found!"<<endl;

    //findSubsequence
    string str = "saurav";
    string output = "";
    int index = 0;
    vector<string> ans;
    findSubsequence(str, output, index, ans);
    for(string s: ans){
        cout<<s<<endl;
    }
    return 0;
}