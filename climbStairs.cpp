class Solution {
public:
    int solve(int i, int n, vector<int>& costs, vector<int>& dp){
    if(i==n-1) return 0;
        if(dp[i] !=-1) return dp[i];
    int ans = INT_MAX;
    for(int j=i+1 ; j<min(n,i+4) ; j++){
        ans = min(ans,costs[j] + (j-i)*(j-i) + solve(j, n, costs, dp));
    }
        
    return dp[i] = ans;
    }
    
    int climbStairs(int n, vector<int>& costs) {
        int ans = INT_MAX;
        vector<int> dp(n,-1);
        for(int i=0; i<min(3,n); i++){
            ans = min(ans,costs[i] + (i+1)*(i+1) + solve(i, n, costs, dp));
        }
        return ans;
    
    }
};
