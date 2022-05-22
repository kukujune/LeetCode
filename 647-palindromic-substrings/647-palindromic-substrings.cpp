class Solution {
public:
    
    int ans = 0;
    void pallin(string str, int left, int right, int size, int& ans){
      while(left >= 0 && right < size && str[left] == str[right]){
        ans++;
        left--;
        right++;
      }
    }
  
    int countSubstrings(string s) {
      
      int sSize = s.size();
      
      for(int i=0; i<sSize; i++){
        pallin(s, i, i, sSize, ans);
        pallin(s, i, i+1, sSize, ans);
        
      }
      
      return ans;
    }
};