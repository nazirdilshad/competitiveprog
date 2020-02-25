typedef long ll;
int Solution::candy(vector<int> &arr) {
    int n = arr.size();
    ll dp[n+1];
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]&& dp[i]<=dp[i+1]){
            dp[i]=1+dp[i+1];
        }
        else{
            continue;
        }
    }
    ll sum = dp[0];
    for(int i=1;i<n;i++){
        sum+=dp[i];
    }
    return sum;
}
