class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
      vector<vector<int>> ret;
      vector<int> prev, now;
      
      for(int i=1; i<=numRows; i++){
        now.clear();
        for(int j=0; j<i; j++){
          if(j==0 || j==i-1){
            now.push_back(1);
            continue;
          }
           
          now.push_back(prev[j-1] + prev[j]);
          
        }
        ret.push_back(now);
        prev.clear();
        prev = now;
        
        /*for(int k=0; k<prev.size();k++){
          cout << prev[k] << " ";
        }cout << "\n";*/
      }
      
      return ret;
      
    }
};