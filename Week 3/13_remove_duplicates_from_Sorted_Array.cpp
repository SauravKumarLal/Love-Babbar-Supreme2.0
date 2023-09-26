class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        int i=0, j=1;
        while(j<nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                // i++;
                // nums[i] = nums[j];
                // j++;
                nums[++i] = nums[j++];
            }
        }
        return i+1;
    }
};