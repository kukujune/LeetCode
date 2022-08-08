class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
      vector<int> ret;
      
      for(auto i: nums){
        //cout << "nums = " << i << " findIdx = ";
        
        int findIdx=ret.size();
        for(int j=0; j<ret.size(); j++){
          
          if(ret[j] >= i){
            findIdx = j;
            break;
          }
        }
        
        
        //cout << findIdx << " " << " size = " << ret.size() << "\n";
        if(ret.size() == 0 || findIdx == ret.size()) ret.push_back(i);
        else{
          ret[findIdx] = i;
        }
        
        //for(auto k: ret) cout << k << " ";
        //cout << "\n";
        
      }
      
      
      return ret.size();
    }
};