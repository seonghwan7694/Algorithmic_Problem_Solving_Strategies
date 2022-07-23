#include <bits/stdc++.h>
using namespace std;
int n, m;
double dp[1010][2020];

double climb(int days, int climbed){
  if(days == m) return climbed >= n ? 1 : 0;
  double& ret = dp[days][climbed];
  if(ret != -1) return ret;
  return ret = 0.75*climb(days + 1, climbed + 2) + 0.25*climb(days + 1, climbed + 1);
}

void solution(){
  cin >> n >> m;
  fill_n(dp[0], 1010*2020, -1);
  cout << climb(0, 0) << "\n";
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cout << fixed;
  cout.precision(10);
  int C;
  cin >> C;
  while(C--){
    solution();
  }
  return 0;
}