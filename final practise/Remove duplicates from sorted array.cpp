class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uni;
        int frontNum= nums[0];
        uni.push_back(frontNum);
        for(int i=1;i<nums.size();i++){
            if(frontNum!=nums[i]){
                frontNum= nums[i];
                uni.push_back(frontNum);
            }
        }
        nums.clear();
        nums= uni;
        return nums.size();
    }
};