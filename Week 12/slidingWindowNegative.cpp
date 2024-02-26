#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void printFirstNegative(vector<int>& arr, int n, int k){
    deque<int> dq;

    //process first k elements
    for(int index=0; index<n; index++){
        int element = arr[index];
        if(element<0){
            dq.push_back(index);
        }
    }

    //process remaining window --> Addition and Removal
    for(int index=k; index<n; index++){
        //aage badhne se pehle purane window ka ans nikalo
        if(dq.empty()){
            cout<<"0 "<<endl;
        }
        else{
            cout<<arr[dq.front()]<<" ";
        }
        
        //Removal --> jo v index out of range hai usko queue se nikalo
        if(index - dq.front() >= k){
            dq.pop_front();
        }
        //Addition
        if(arr[index]<0){
            dq.push_back(index);
        }
    }

    //last window ka answer
    if(dq.empty()){
        cout<<"0 "<<endl;
    }
    else{
        cout<<arr[dq.front()]<<" ";
    }
}

int main(){
    // queue<int> q;
    // q.push(2); q.push(-5); q.push(4); q.push(-1); q.push(-2);  q.push(0);  q.push(5);
    vector<int> arr{2, -5, 4, -1, -2, 0, 5};
    int size = 7, k=3;

    printFirstNegative(arr, size, k);
    
    return 0;
}