class Solution {
public:
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
      vector<string> ret;
      map<char, char> m;
      bool chk[27];
      
      for(auto i: words){
        m.clear();
        for(int j=0; j<27; j++){
          chk[j] = false;
        }
        
        //cout << i << "\n";
        for(int j=0; j<i.size(); j++){
           
          int idx = i[j] - 'a';
          if(m.count(pattern[j]) == 0 && chk[idx] == false){
            m[pattern[j]] = i[j];
            chk[idx] = true;
          }
          
          //cout << idx << " " << pattern[j] << " " <<  m[pattern[j]] << " " << i[j] << "\n";
          if(m[pattern[j]] != i[j]) break;
        
          if(j == i.size()-1){
            ret.push_back(i); 
          }
        }
      }
      
      
      return ret;
    }
};