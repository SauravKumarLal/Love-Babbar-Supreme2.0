#include<iostream>
using namespace std;

int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			for(int k=j+1; k<size; k++){
				if(input[i] + input[j] + input[k] == x) triplets++;
			}
		}
	}
	return triplets;
}

int main(){
    int arr[7] = {1, 2, 1, 3, 0, 3, 0};
    cout<<tripletSumToX(arr, 7, 4);
    return 0;
}