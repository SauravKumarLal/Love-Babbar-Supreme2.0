#include<iostream>
#include<vector>
using namespace std;

void waveOfMatrix(vector<vector<int>> mat){
    for(int j=0; j<4; j++){
        if(j%2 == 0){
            for(int i=0; i<5; i++){
                cout<<mat[i][j]<<" ";
            }
        }
        
        else{
            for(int i=4; i>=0; i--){
                cout<<mat[i][j]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int>> mat{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    waveOfMatrix(mat);
    return 0;
}