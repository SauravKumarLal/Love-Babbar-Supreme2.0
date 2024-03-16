//MERGE SORT

#include<iostream>

using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    //length of both new array
    int leftLen = mid-s+1;
    int rightLen = e - mid;

    //create both array --> dynamic allocation
    int *left = new int[leftLen];
    int *right = new int[rightLen];

    //copy the element to these arrays
    int k=s;
    for(int i=0; i<leftLen; i++){
        left[i] = arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0; i<rightLen; i++){
        right[i] = arr[k];
        k++;
    }

    //actual merge logic
    //left and right array are actually sorted
    int leftIndex=0;
    int rightIndex=0;
    int mainIndex=s; //idhar mei galti hoti hai

    while(leftIndex<leftLen && rightIndex<rightLen){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainIndex] = left[leftIndex];
            leftIndex++; mainIndex++;
        }
        else{
            arr[mainIndex] = right[rightIndex];
            rightIndex++; mainIndex++;
        }
    }
    //2 more cases
    //left array exhausted, but right array mei element still there
    while(rightIndex < rightLen){
        arr[mainIndex] = right[rightIndex];
        rightIndex++; mainIndex++;
    }
    //right array exhausted, but left array mei element still there
    while(leftIndex < leftLen){
        arr[mainIndex] = left[leftIndex];
        leftIndex++; mainIndex++;
    }
    //free heap memory --> good practice
    delete[] left; delete[] right;

}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s>=e) return; 
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    //merge 2 sorted array
    merge(arr, s, e);
}

int main(){
    int arr[] = {1, 5, 3, 5, 8, 6, 9, 4, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=n-1;
    cout<<"Before merge sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, s, e);
    
    cout<<"After merge sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}