class Solution {
public:
    int hammingWeight(uint32_t n) {
        
      int cnt = 0;
      
      while(n != 0){
        
        int temp = 1;
        temp = n & 1;
        if(temp == 1) cnt++;
                
        n = n >> 1;
        
        //cout << temp << "\n";  
        
      }
            
      return cnt;
    }
};