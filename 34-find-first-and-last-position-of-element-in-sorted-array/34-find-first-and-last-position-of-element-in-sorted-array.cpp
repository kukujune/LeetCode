class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
      vector<int> ret;
      if(nums.size() == 0){
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
      }
      
      vector<int>::iterator chk1, chk2;
      //vector<int> ret; 
      chk1 = lower_bound(nums.begin(), nums.end(), target);
      chk2 = upper_bound(nums.begin(), nums.end(), target);
      
      int num1 = chk1 - nums.begin();
      int num2 = chk2 - nums.begin();
      num2 -= 1;
      
      if(num1 >= nums.size()){
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
      }
      
      //cout << num1 << " " << num2 << "\n";
      if(num1 >= 0 && nums[num1] == target) ret.push_back(num1);
      else ret.push_back(-1);
      
      //cout << ret.size() << "\n";
      
      if(ret[0] == -1){
        ret.push_back(-1);
        return ret;
      }
      
      if(num2 >= 0 && nums[num2] == target) ret.push_back(num2);
      else ret.push_back(-1);
      
     // cout << chk1 - nums.begin() << " " << chk2 - nums.begin() << "\n";
      return ret;
    }
};