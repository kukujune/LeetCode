class Solution {
public:
    
    vector<vector<int>> ret;
    vector<int> dup;
    vector<int> now;
    int cnt[21];
    int total = 0;  
  
    void dfs(int used){
      //cout << used << " " << total << " now = ";
      //for(auto i : now){
      //  cout << i << " ";
      //}cout << "\n";
      
      
      if(now.size() == total){
        //cout << used << "\n";
        ret.push_back(now);
        return;
      }
      
      for(auto i : dup){
        if(cnt[i + 10] == 0) continue;
        now.push_back(i);
        cnt[i + 10] -= 1;
        dfs(used + 1);
        now.pop_back();
        cnt[i + 10] += 1;
      }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {

      sort(nums.begin(), nums.end());
        
      total = nums.size();
      //cout << total << "\n";
      
      for(int i = 0; i < 21; i++) cnt[i] = 0;
      
      for(int i = 0; i < nums.size(); i++){
        cnt[nums[i] + 10] += 1;
        if(i != 0 && nums[i-1] == nums[i]) continue;
        dup.push_back(nums[i]);
      }
      
      dfs(0);
    
      
      return ret;
    }
};