//LEETCODE
//Approach 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j])
                    return nums[i];
            }
        }
        return -1;
    }
};

//Approach 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0, j=1;
        sort(nums.begin(), nums.end());
        while(i<nums.size()){
            if(nums[i] == nums[j])
                return nums[i];
            else{
                i++;
                j++;
            }
        }
        return -1;
    }
};