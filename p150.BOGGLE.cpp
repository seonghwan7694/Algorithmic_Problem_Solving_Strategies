#include <bits/stdc++.h>
using namespace std;

/* 1. 나
bool flag;
char board[20][20];
int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
int dy[] = {+1, +0, -1, +1, -1, +1, +0, -1};

void find_str(string &str, int x, int y, int idx){
  if(idx == str.length() or flag){
    flag = true;
    return;
  }
  if(board[x][y] == str[idx]){
    for(int i = 0; i < 8; i++){
      find_str(str, x + dx[i], y + dy[i], idx + 1);
    }
  }
  return;
}

void solution(){
  string str; cin >> str;
  flag = false;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(str[0] == board[i][j]){
        find_str(str, i, j, 0);
        if(flag){
          cout << str << " YES" << "\n";
          return;
        }
      }
    }
  }
  cout << str << " NO" << "\n";
  return;
}

void input(){
  for(int i = 0; i < 5; i++){
    string str; cin >> str;
    for(int j = 0; j < 5; j++){
      board[i][j] = str[j];
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while(tc--){
    input();
    cin >> n;
    while(n--){
      solution();
    }
  }

  return 0;
}
*/

/* 2. 종만북
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool in_range(int x, int y){
  return (0 <= x and x < 5) and (0 <= y and y < 5);
}

bool has_word(int x, int y, const string& word){
  if(!in_range(x, y)) return false;
  if(board[x][y] != word[0]) return false;
  if(word.size() == 1) return true;
  for(int dir; dir < 8; dir++){
    if(has_word(x + dx[dir], y + dy[dir], word.substr(1))) return true;
  }
  return false;
}
*/