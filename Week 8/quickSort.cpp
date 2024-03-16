#include<iostream>
using namespace std;

void quickSort(int *arr, int start, int end){
    if(start>=end) return;
    int pivot=end;
    int i = start-1;
    int j = start;

    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    //i is the right position of pivot element
    i++;
    swap(arr[pivot], arr[i]);

    quickSort(arr, start, i-1);
    quickSort(arr, i+1, end);

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

    quickSort(arr, s, e);
    
    cout<<"After merge sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}