//Debug the code. Sort 0s and 1s
#include<iostream>
using namespace std;

void sort0sand1s(int arr[], int size){
	int nextZero = 0;
	for(int i=0; i<size; i++){
		if(arr[i] == 0){
			int temp = arr[nextZero];
			arr[nextZero] = arr[i];
			arr[i] = temp;
            nextZero++; 
		}
	}
}

int main(){
    int arr[7] = {1, 0, 1, 1, 0, 1, 0};
    sort0sand1s(arr, 7);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}