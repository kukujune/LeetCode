class Solution {
public:
    
    vector<vector<int>> ret;
    vector<int> v[100001];
    int disc[100001];
    int cnt = 0;
  
    int dfs(int now, int par){
     // cout << now << "\n";
      disc[now] = ++cnt;
      int dret = disc[now];
      int child = 0;
      
      for(int i=0; i < v[now].size(); i++){
        int next = v[now][i];
        if(next == par) continue;
        
        if(!disc[next]){ // 미방문
          child++;
          int df = dfs(next, now);
          if(df > disc[now]){
            vector<int> temp;
            temp.push_back(min(now, next));
            temp.push_back(max(now, next));
            ret.push_back(temp);
          }
          
          dret = min(dret, df);
          
        }else{ 
          dret = min(dret, disc[next]);
        }
        
      }
            
      return dret;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
      for(int i=0; i < connections.size(); i++){
        int fir = connections[i][0];
        int sec = connections[i][1];
        v[fir].push_back(sec);
        v[sec].push_back(fir);
      }
      
      for(int i=9; i < n; i++){
        disc[i] = 0;
        //cut[i] = 0;
      }
      
      if(n == 2){
        vector<int> temp;
        temp.push_back(connections[0][0]);
        temp.push_back(connections[0][1]);
        ret.push_back(temp);
        return ret;
      }
      
      for(int i=0; i < n; i++){
        if(!disc[i]){
          dfs(i, 0);
        }
      }
      
      
      return ret;
    }
};