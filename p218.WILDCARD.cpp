#include <bits/stdc++.h>
using namespace std;

int TC, n;
int cache[101][101];
string W, S;
vector<string> ans;

bool matchMemoiszed(int w, int s){
  int &ret = cache[w][s];
  if(ret != -1) return ret;
  while(s < S.size() and w < W.size() and (W[w] == '?' or W[w] == S[s])){
    ++w;
    ++s;
  }
  if(w == W.size()) return ret = (s == S.size());
  if(W[w] == '*'){
    for(int skip = 0; skip + s <= S.size(); skip++){
      if(matchMemoiszed(w + 1, s + skip)){
        return ret = 1;
      }
    }
  }
  return ret = 0;
}

void solution(){
  cin >> W;
  cin >> n;
  while(n--){
    cin >> S;
    memset(cache, -1, sizeof(cache));
    if(matchMemoiszed(0, 0)){
      ans.push_back(S);
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);


  cin >> TC;
  while(TC--){
    solution();
  }
  sort(ans.begin(), ans.end());
  for(auto s : ans) cout << s << "\n";

  return 0;
}