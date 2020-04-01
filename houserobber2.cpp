class Solution {
public:
    int rob(vector<int>& nums) {
       
        int dp[nums.size()],dp2[nums.size()];
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[1],nums[0]);
        }
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        dp2[0]= nums[1];
        dp2[1]=max(dp2[0],nums[2]);
        for(int i=2;i<nums.size()-1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i+1]);
        }
        return max(dp[nums.size()-2],dp2[nums.size()-2]);
    }
};