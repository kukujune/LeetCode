class Solution {
public:
    bool isAnagram(string s, string t) {
        
      int alp[27];
      for(int i=0; i<27; i++) alp[i] = 0;
      for(auto i: t){
        int temp = i - 'a';
        alp[temp] += 1;
      }
      
      for(auto i: s){
        int temp = i - 'a';
        alp[temp] -= 1;
      }
      
      for(int i=0; i<27; i++){
        if(alp[i] != 0) return false;
      }
      return true;
    }
};