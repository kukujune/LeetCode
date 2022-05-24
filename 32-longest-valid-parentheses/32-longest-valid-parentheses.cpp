class Solution {
public:
    int longestValidParentheses(string s) {
      
      stack<int> st;
      int ans = 0;
      int sSize = s.size();
      st.push(-1);
      
      for(int i=0; i<sSize; i++){
        if(s[i] == '('){
          st.push(i);
          continue;
        }
        
        st.pop();
        if(st.size() == 0){
          st.push(i); 
        }else{
          ans = max(ans, i - st.top());
        }
        //cout << i << " ans= " << ans << "\n";
      }
      
      return ans;
    }
};