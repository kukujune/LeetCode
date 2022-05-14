class Solution {
public:
    
    int dist[101];
    bool visited[101];
    int INFI = 6001;  
    typedef pair<int, int> ii;
    typedef pair<int, ii> iii;
    vector<ii> vii[101]; // weight, to
  
    void initDist(){
      for(int i = 0; i < 101; i++){
        dist[i] = INFI;
        visited[i] = false;
      }
    }
  
    // i번 노드부터 시작
    int dij(int i, int n, int k){
      
      priority_queue<ii> pq;
      pq.push(make_pair(0, i));
      
      while(!pq.empty()){
        int now = pq.top().second;
        int nowWeight = pq.top().first * -1;
        visited[now] = true;
        pq.pop();
        
        //cout << now << " " << nowWeight << "\n";
        
        if(dist[now] > nowWeight){
          dist[now] = nowWeight;
        }
        
        for(int l = 0; l < vii[now].size(); l++){
          int next = vii[now][l].second;
          int nextWeight = (nowWeight + vii[now][l].first) * -1;
          if(visited[next]) continue;
          pq.push({nextWeight, next});
        }
      }
      
      int ret = 0;
      for(int l=1; l < n+1; l++){
        if(dist[l] == INFI) return -1;
        if(visited[l] == false) return -1;
        if(dist[l] > ret) ret = dist[l];
      }
      
      return ret;
    }
  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
      for(int i = 0; i < times.size(); i++){
        int from = times[i][0];
        int to = times[i][1];
        int weight = times[i][2];
        
        ii weightTo = make_pair(weight, to); 
        vii[from].push_back(weightTo);
        
        //cout << from << " " << to << " " << weight << "\n";
      }
      
      // n번 노드에서 시작해서 노달 가능 횟수     
      int ret = -1;
      initDist();
      int dijRet = dij(k, n, k);
      if(dijRet > ret) ret = dijRet;
  
      return ret;
    }
};