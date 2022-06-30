#include <bits/stdc++.h>
using namespace std;


/* 1. 종만북 답
const int coverType[4][3][2] = {
  {{0, 0}, {1, 0}, {0, 1}},
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}}
};

bool Set(vector<vector<int>> &board, int y, int x, int type, int delta){
  bool ok = true;
  for(int i = 0; i < 3; i++){
    const int ny = y + coverType[type][i][0];
    const int nx = x + coverType[type][i][1];
    if(ny < 0 or ny >= board.size() or nx < 0 or nx >= board[0].size()){
      ok = false;
    }else if((board[ny][nx] += delta) > 1){
      ok = false;
    }
  }
  return ok;
}

int cover(vector<vector<int>>& board){
  int y = -1, x = -1;
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[i].size(); j++){
      if(board[i][j] == 0){
        y = i;
        x = j;
        break;
      }
    }
    if(y != -1) break;
  }
  if(y == -1) return 1;
  int ret = 0;
  for(int type = 0; type < 4; type++){
    if(Set(board, y, x, type, 1)) ret += cover(board);
    Set(board, y, x, type, -1);
  }
  return ret;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tc; cin >> tc;
  int n, m; 
  while(tc--){
    cin >> n >> m;
    vector<vector<int>> board;
    
    for(int i = 0; i < n; i++){
      vector<int> tmp;
      string str;
      cin >> str;
      for(int j = 0; j < m; j++){
        if(str[j] == '#') tmp.push_back(1);
        if(str[j] == '.') tmp.push_back(0);
      }
      board.push_back(tmp);
    }
    cout << cover(board) << "\n";
  }


  return 0;
}
*/