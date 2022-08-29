class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      
      int dx[] = {1,-1,0,0};
      int dy[] = {0,0,1,-1};
      int ret = 0;
      bool visited[301][301];
      
      for(int i=0; i<301; i++){
        for(int j=0; j<301; j++){
          visited[i][j] = 0;
        }
      }
      
      queue<pair<int,int>> q;
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
          if(grid[i][j] == '1' && visited[i][j] == false){
            q.push({i, j});
            ret += 1;
                    
            while(!q.empty()){
              pair<int,int> now = q.front();
              q.pop();
              //if(visited[now.first][now.second]) continue;
              visited[now.first][now.second] = true;
              
              for(int k=0; k<4; k++){
                int nextX = now.first + dx[k];
                int nextY = now.second + dy[k];
                if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[i].size()) continue;
                if(visited[nextX][nextY]) continue;
                if(grid[nextX][nextY] == '0') continue;
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
              
              }
            }
          }
        }
      }
      
      
     
      return ret;
    }
};