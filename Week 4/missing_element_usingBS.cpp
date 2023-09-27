#include<iostream>
#include<vector>
using namespace std;

int findMissingElement(vector<int>& arr, int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;
  int ans = -1;

  while(s <= e) {
    int diff = arr[mid] - mid;

    if(diff == 1) {
      //right me jao
      s = mid+1;
    }
    else {
      //ans store
      ans = mid;
      //left me jao
      e = mid - 1;
    }
     mid = s + (e-s)/2;
  }
  //HW -> How can we remove this, by modifying the above logic
  if(ans +1 == 0)
    return n+1;
  
  return ans+1;
}

int main(){
    int n;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11};
    cout<<"Missing element is: "<<findMissingElement(nums, 10);
}

