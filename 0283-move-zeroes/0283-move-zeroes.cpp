class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] !=0){
                nums[idx]=nums[i];
                idx++;
            }else{
                c++;
            }
        }
        idx=nums.size()-1;
        while(c--){
            nums[idx]=0;
            idx--;
        }
    }
};