//You must solve it in O(log(arr.length)) time complexity means binary search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0, e=arr.size()-1;
        while(s<e){
            int mid = s + (e-s)/2;
            if(arr[mid]<arr[mid+1]){
                //on line A
                s=mid+1;
            }
            else{
                //on line B
                e = mid;
            }
        }
        return s;
    }
};