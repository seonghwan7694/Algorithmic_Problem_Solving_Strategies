#include <bits/stdc++.h>
using namespace std;

int TC;
int N, a[505], dp[505]; // dp[i] : 0 부터 i까지 a의 증가 부분 수열의 최대 길이

void solution(){
  fill(a, a + 505, 0);
  fill(dp, dp + 505, 0);
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= N; i++){
    dp[i] = 1;
    for(int j = 1; j <= i; j++){
      if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  cout << *max_element(dp, dp + 505) << "\n";
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