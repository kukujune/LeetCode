class Solution {
public:
    
    typedef pair<int,int> ii;
    typedef pair<ii, int> iii;
  
    int dx[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};  
    bool visited[101][101];
  
    int bfs(vector<vector<int>>& a){
      queue<iii> q;
      ii init = make_pair(0, 0);
      q.push({init,1});
      visited[0][0] = true;
      int ret = -1;
      int n = a.size();
      
      while(!q.empty() && a[0][0] == 0){
        int x = q.front().first.first; int y = q.front().first.second; int cnt = q.front().second;
        visited[x][y] = true;
        
        if(a[x][y] == 1) continue;
        if(x == n-1 && y == n-1){
          ret = cnt;
          //cout << x << " " << y << " " << cnt << "\n";
          return ret;
        }
        
        //cout << x << " " << y << " " << cnt << "\n";
        
        q.pop();
        
        for(int i=0; i<8; i++){
          int nx = x + dx[i]; int ny = y + dy[i]; int ncnt = cnt + 1;
          if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1) continue;
          if(visited[nx][ny]) continue;
          if(a[nx][ny] == 1) continue;
          ii naxis = make_pair(nx, ny);
          if(nx == n-1 && ny == n-1){
            ret = ncnt;
            return ret;
          }
          visited[nx][ny] = true;
          q.push({naxis, ncnt});
        }
        
      }
      
      return ret;
      
    }
  
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      return bfs(grid);
    }
};