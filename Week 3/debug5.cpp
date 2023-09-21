#include<iostream>
using namespace std;

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<=i+1; j++){
			if(input[i] + input[j] == x) pairs++;
		}
	}
	return pairs;
}

int main(){
    int arr[7] = {1, 2, 1, 3, 0, 3, 0};
    cout<<pairSumToX(arr, 7, 3);
    return 0;
}