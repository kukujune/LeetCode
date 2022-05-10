class Solution {
public:
    
    bool visited[11];
    int total;
    int totalNum;
    vector<vector<int>> ret;
  
    void init(){
      for(int i = 0; i < 10; i++) visited[i] = false;
    }
    
    vector<int> printVisited(){
      vector<int> vi;
      
      for(int i = 1; i < 10; i++){ 
        if(visited[i]){
          //cout << i << " ";
          vi.push_back(i);
        } 
      }
      //cout << "\n";
      return vi;
    }
  
    // 하나씩 찾음 
    void dfs(int start, int cnt, int nowSum){
      
      if(nowSum == total && cnt == totalNum){
        
        ret.push_back(printVisited());
        return;
      }
      
      if(nowSum > total) return;
      if(cnt == totalNum) return;
      
      for(int i = start + 1; i < 10; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, cnt + 1, nowSum + i);
        visited[i] = false;
      }
      
    }
  
  
    vector<vector<int>> combinationSum3(int k, int n) {
            
      total = n;
      totalNum = k;
      init();
      dfs(0, 0, 0);
      
      return ret;
      
    }
};