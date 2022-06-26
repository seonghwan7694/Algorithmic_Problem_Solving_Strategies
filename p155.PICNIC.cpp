#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m, a, b, tmp;

int get_combination(){

}
void solution(){
  int ans = 0;
  cin >> n >> m;
  set<pair<int, int>> s;
  vector<int> v;
  
  for(int i = 0; i < n; i++){
    v.push_back(i);
  }
  while(m--){
    cin >> a >> b;
    s.insert({a, b});
    s.insert({b, a});
  }
  do{
    tmp = 0;
    for(int i = 0; i < v.size(); i+=2){
      if(s.find({v[i], v[i+1]}) != s.end()) tmp++;
    }
    if(tmp == v.size()/2) ans++;
  }while(next_permutation(v.begin(), v.end()));
  cout << ans/get_combination() << "\n";

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