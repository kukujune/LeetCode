class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
      vector<const char*> waiting[128];
      for(auto& w: words){
        waiting[w[0]].push_back(w.c_str());
      }
      
      for(auto c: s){
        
        auto now = waiting[c]; // vector<const char*>
        waiting[c].clear();
        
        for(auto it: now){
          waiting[*++it].push_back(it); 
        }
      }
      
        return waiting[0].size();
    }
};