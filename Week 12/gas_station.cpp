//GAS STATION - LEETCODE

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit=0;
        int balance=0;

        //index from where we r starting the movement
        int start=0;

        //check every index if ut's the ans 
        for(int i=0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];

            if(balance<0){
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }
        if(balance-deficit>=0) return start;
        else return -1;
    }
}; 