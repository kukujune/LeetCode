class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[10002];
        for(int i = 0; i <= 10000; i++){
            dp[i] = 987654321;
        }
        
        dp[0] = 0;
        //for(int i = 0; i < coins.size(); i++){
        //    dp[coins[i]] = 1;
        //}
        
        for(int j = 1; j <= amount; j++){
            for(int i = 0; i < coins.size(); i++){
                int pre = j - coins[i];
                if(pre < 0) continue;
                if(j == coins[i]){ 
                    dp[j] = 1;
                    continue;
                }
                dp[j] = min(dp[j], dp[pre] + dp[coins[i]]); 
            }
        }
        //cout << "amout: " << dp[amount] << "\n";
        //if(amount == 0) dp[amount]
        if(dp[amount] == 987654321) dp[amount] = -1;
        return dp[amount];
    }
};