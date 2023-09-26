class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //TLE
        // int sum1=INT_MIN;
        // int size=nums.size();
        // for(int i=0; i<=size-k; i++){
        //     int sum=0;
        //     for(int j=i; j<i+k; j++){
        //         sum += nums[j];
        //     }
        //     if(sum>sum1){
        //         sum1 = sum;
        //     }
        // }
        // return (double)sum1/k;

        //SLIDING WINDOW METHOD
        int size = nums.size();
        double sum=0;
        for(int i=0; i<k; i++){
            sum = sum+nums[i];
        }
        double sum1 = sum;
        int i=0, j=k;
        while(j<size){
            sum=sum+nums[j]-nums[i];
            i++; 
            j++;
            if(sum>=sum1){
                sum1 = sum;
            }
        }

        return (double)sum1/k;
    }
};