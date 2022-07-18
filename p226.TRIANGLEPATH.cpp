#include <bits/stdc++.h>
using namespace std;


/* 1. 내 답
int C;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> C;
  int n;
  while(C--){
    cin >> n;
    int board[101][101] = {0};
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= i; j++){
        cin >> board[i][j];
      }
    }
    int dp[101][101] = {0};
    
    // dp[x][y] : (0, 0)에서 (x, y) 까지의 최대합


    
    dp[0][0] = board[0][0];
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= i; j++){
        dp[i][j] = max(dp[i-1][j] + board[i][j], dp[i-1][j-1] + board[i][j]);
      }
    }
    cout << *max_element(dp[n - 1], dp[n - 1] + n) << "\n";
  }

  return 0;
}
*/

