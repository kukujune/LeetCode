class Solution {
public:
    int countVowelStrings(int n) {
      int dp[52][5];
      int ret = 0;
      
      for(int i = 0; i < 5; i++){
        dp[0][i] = 1;
        dp[1][i] = 5 - i;
        //cout << dp[1][i] << "\n";
      }
      
      for(int i = 2; i <= n; i++){
        for(int j = 0; j < 5; j++){
          int prevSum = 0;
          for(int k = j; k < 5; k++){
            prevSum += dp[i-1][k];
          }
          dp[i][j] = prevSum;
        }  
      }
      
      for(int i = 0; i < 5; i++){
        ret += dp[n - 1][i];
      }
      
      return ret;
      
    }
};