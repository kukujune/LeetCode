class Solution {
public:
    typedef pair<int, int> ii;
  
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int board[101][101];
    int visited[101][101];  
    int m, n;
  
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      
      queue<ii> q;
     
      if(obstacleGrid[0][0] == 0){
        board[0][0] = 1;
        visited[0][0] = true;
        q.push({0,0});
      }
          
      //cout << m-1 << " " << n-1 << "\n";
      
      while(!q.empty()){
        
        int nowX = q.front().first;
        int nowY = q.front().second;
        //cout << nowX << " " << nowY << " " << board[nowX][nowY] << "\n";
        q.pop();
        
        for(int i=0; i<2; i++){
          int nextX = nowX + dx[i]; int nextY = nowY + dy[i];
          if(nextX < 0 || nextX > m-1 || nextY < 0 || nextY > n-1) continue;
          if(obstacleGrid[nextX][nextY] == 1) continue;
          if(visited[nextX][nextY]) continue;
          
          visited[nextX][nextY] = true;
          //cout << nextX << " " << nextY << "\n";
          if(0 <= nextX-1 && nextX-1 <= m-1) board[nextX][nextY] += board[nextX-1][nextY];
          if(0 <= nextY-1 && nextY-1 <= n-1) board[nextX][nextY] += board[nextX][nextY-1];
          q.push({nextX, nextY});
        }
        
      }
      
      return board[m-1][n-1];
    }
};