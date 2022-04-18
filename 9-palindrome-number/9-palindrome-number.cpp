class Solution {
public:
    bool isPalindrome(int x) {
        
      if(x < 0) return false;
      if(x == 0) return true;
      
      vector<int> arr;
      while(x > 0){
        if(x < 10) { 
          arr.push_back(x);
          break;
        }
        int temp = x % 10;
        arr.push_back(temp);
        x /= 10;
        //cout << x << " " << temp << "\n";
      }
      
      int arrSize = arr.size() - 1;
      for(int i = 0; i <= arrSize / 2; i++){
        int endIndex = arrSize - i;
        if(arr[i] != arr[endIndex]){
          return false;
        }
      }
      
      
      return true;
    }
};