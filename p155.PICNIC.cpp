#include <bits/stdc++.h>
using namespace std;



/* 1. 나 : 시간 초과 - 완전 탐색 : 이진검색트리 SET을 사용한 완전 탐색

int tc;
int arr[10];
int n, m, t1, t2;

void solution(){
  cin >> n >> m;
  set<pair<int, int>> s;
  for(int i = 0; i < m; i++){
    cin >> t1 >> t2;
    if(t1 > t2) swap(t1, t2);
    s.insert({t1, t2}); 
  }
  for(int i = 0; i < n; i++){
    arr[i] = i;
  }
  int ans = 0;
  do{
    int cnt = 0;
    for(int i = 0; i < n/2; i++){
      t1 = arr[i*2];
      t2 = arr[i*2+1];
      if(t1 > t2) swap(t1, t2);
      if(s.find({t1, t2}) != s.end()) cnt++; 
    }
    if(cnt == n/2) ans++;
  }while(next_permutation(arr, arr + n));
  if(n==2){
    cout << ans/(2*1) << "\n";
  }else if(n == 4){
    cout << ans/(2*2*2*1) << "\n";
  }else if(n == 6){
    cout << ans/(2*2*2*3*2*1) << "\n";
  }else if(n == 8){
    cout << ans/(2*2*2*2*4*3*2*1) << "\n";
  }else if(n == 10){
    cout << ans/(2*2*2*2*2*5*4*3*2*1) << "\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  while(tc--){
    solution();
  }
  return 0;
}
*/

/* 2. 종만북 : 정답 - 백트래킹
int tc, n, m;
bool tmp[10];
int countParings(bool taken[10], bool areFriends[][10]){
  int firstFree = -1;
  for(int i = 0; i < n; i++){
    if(!taken[i]){
      firstFree = i;
      break;
    }
  }
  if(firstFree == -1) return 1;
  int ret = 0;
  for(int pairWith = firstFree + 1; pairWith < n; pairWith++){
    if(!taken[pairWith] and areFriends[firstFree][pairWith]){
      taken[firstFree] = taken[pairWith] = true;
      ret += countParings(taken, areFriends);
      taken[firstFree] = taken[pairWith] = false;
    }
  }
  return ret;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> tc;
  while(tc--){
    cin >> n >> m;
    bool areFriends[10][10] = {false};
    while(m--){
      int t1, t2; cin >> t1 >> t2;
      areFriends[t1][t2] = true;
    }
    cout << countParings(tmp, areFriends) << "\n";
  }

  return 0;
}
*/