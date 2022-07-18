#include <bits/stdc++.h>
using namespace std;

/* 1. BFS로 직접 구현
int TC, N;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void solution(){
  int board[101][101];
  bool visited[101][101] = {false};


  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = true;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    if(cur.first == N - 1 and cur.second == N - 1){
      cout << "YES" << "\n";
      return;
    }
    for(int dir = 0; dir < 2; dir++){
      int nx = cur.first + dx[dir] * board[cur.first][cur.second];
      int ny = cur.second + dy[dir] * board[cur.first][cur.second];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N or visited[nx][ny]) continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
  cout << "NO" << "\n";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> TC;
  while(TC--){
    solution();
  }

  return 0;
}
*/

int n, board[100][100];
int dp[100][100];

bool jump(int x, int y){
  if(x >= n or y >= n) return 0;
  if(y == n - 1 and x == n - 1) return -1;
  if(dp[x][y] != -1){
    return dp[x][y];
  }
  return dp[x][y] = jump(x, y + board[x][y]) or jump(x + board[x][y], y);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int TC; cin >> TC;
  while(TC--){
    cin >> n;
    for(int i = 0; i < n; i++){
      fill(dp[i], dp[i] + n, -1);
      for(int j = 0; j < n; j++){
        cin >> board[i][j];
      }
    }
    if(jump(0, 0)){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }

  return 0;
}