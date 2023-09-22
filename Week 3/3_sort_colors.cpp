//LEETCODE
//METHOD 1

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c1=0, c2=0, c3=0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                c1++;
            else if(nums[i] == 1)
                c2++;
            else
                c3++;
        }
        int i=0;
        while(c1--){
            nums[i] = 0;
            i++;
        }
        while(c2--){
            nums[i] = 1;
            i++;
        }
        while(c3--){
            nums[i] = 2;
            i++;
        }
    }
};

//METHOD 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0, m=0, h=n-1;
        while(m<=h){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else if(nums[m] == 2){
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};