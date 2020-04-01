long long dp[51000];
long long y = INT_MIN;
class Solution {
public:
    int sum(vector<int>& nums,int idx,int csum, int tsum){
        int xx;
        if(csum<0){
             xx = (idx*1003)+csum+20000;
        }
        else{
            xx = (idx*1003)+csum;
        }
        if(idx==nums.size()){
            return csum==tsum?1:0;
        }
        
        if(dp[xx]!=y){
            return dp[xx];
        }
        int x = 0 , z = 0;
        x = sum(nums,idx+1,csum-nums[idx],tsum);
        z =sum(nums,idx+1,csum+nums[idx],tsum);
        

        
        return dp[xx] = x+z;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
       for(int i= 0; i<51000;i++){
           dp[i] = y;
                
       }
    
        
        return sum(nums,0,0,S);
    }
};