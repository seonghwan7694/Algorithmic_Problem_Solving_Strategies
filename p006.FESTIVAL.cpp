#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int SUM(int idx, int num){
  int ans = 0;
  for(int i = idx; i < idx + num; i++){
    ans += arr[i]; 
  }
  return ans;
}
void solve(){
  int n, l; cin >> n >> l;
  fill(arr, arr + 1010, 0);
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  double MIN = 10000000000;
  while(n != l){
    for(int i = 1; i <= n - l + 1; i++){
      MIN = min(MIN, SUM(i, l)/(double)l);
    }
    l++;
  }
  MIN = min(MIN, SUM(1, n)/(double)n);
  cout << MIN << "\n";
}

int main(){
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(12);
  ios::sync_with_stdio(false);

  int test_case; cin >> test_case;
  while(test_case--){
    solve();
  }

  return 0;
}