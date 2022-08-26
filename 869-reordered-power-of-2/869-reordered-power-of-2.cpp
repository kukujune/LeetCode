class Solution {
public:
    
    int numLength(int x){
      
      int temp = x;
      int cnt = 0;
      while(temp > 0){
        cnt++;
        temp /= 10;
      }
      return cnt;
    }
  
    void findCom(int x, int arr[]){
      
      int temp = x;
      while(temp > 0){
        
        int mod = temp % 10;
        //cout << mod << "\n";
        arr[mod] += 1;
        temp /= 10;
        
      }
    }
  
    bool chk(int arr[], int brr[]){
      
      for(int i=0; i<9; i++){
        if(arr[i] != brr[i]) return false;
      }
      return true;
    }
    
    int nows[10] = {0,};
    int nums[10] = {0,};
  
    bool reorderedPowerOf2(int n) {
      
      int nLength = numLength(n);
      for(int i=0; i<9; i++) nums[i] = 0;
      findCom(n, nums);
      
      /*cout << nLength << "\n";
      for(int i=0; i<10; i++){
        cout << nums[i] << " ";
      }cout << "\n";*/
      
      int now = 1;
      if(now == n) return true;
      
      while(1){
        
        int nowLength = numLength(now);
        if(nLength > nowLength) {
          now *= 2;
          continue;
        }
        if(nLength < nowLength) break;
        if(now > 1000000000) break;
    
        
        //cout << "now = " << now << ", nowLen " <<  nowLength << "\n";
        
        for(int i=0; i<10; i++) nows[i] = 0;
        findCom(now, nows);
        
        /*for(int i=0; i<10; i++){
          cout << nows[i] << " ";
        }cout << "\n";*/
        
        bool ans = chk(nums, nows);
        if(ans) return true;
        
        now *= 2;
        
      }
      
      
      /*cout << nLength << "\n";
      for(int i=0; i<10; i++){
        cout << nums[i] << " ";
      }
      cout << "\n";*/
      
      
      return false;
    }
};