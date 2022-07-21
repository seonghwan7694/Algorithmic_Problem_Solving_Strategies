#include <bits/stdc++.h>
using namespace std;

int dp[101];
const int MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= 100; i++){
    dp[i] = (dp[i-1] + dp[i-2])%MOD;
  }

  int C;
  cin >> C;
  while(C--){
    int n; cin >> n;
    cout << dp[n] << "\n";
  }

  return 0;
}