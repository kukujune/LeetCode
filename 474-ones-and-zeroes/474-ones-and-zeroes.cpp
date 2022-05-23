class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      
      int strsSize = strs.size();
      int arr, brr;

      for(int i=0; i < strsSize; i++){
        
        arr = brr = 0;
        for(int j=0; j < strs[i].size(); j++){
          if(strs[i][j] == '0') arr++;
          else brr++;
        }
        
        for(int j=m; j >= arr; j--){
         for(int k=n; k >= brr; k--){
           dp[j][k] = max(dp[j][k], dp[j-arr][k-brr] + 1);
         } 
        }
      }
      
      return dp[m][n];
    }
};