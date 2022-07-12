#include <bits/stdc++.h>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x..",
};

int tc;

bool areAligned(const vector<int>& clocks){
  for(auto x : clocks){
    if(x != 12){
      return false;
    }
  }
  return true;
}

void push(vector<int>& clocks, int swtch){
  for(int clock = 0; clock < CLOCKS; ++clock){
    if(linked[swtch][clock] == 'x'){
      clocks[clock] += 3;
      if(clocks[clock] == 15) clocks[clock] = 3;
    }
  }
}

int solve(vector<int> &clocks, int swtch){
  if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
  int ret = INF;
  for(int cnt = 0; cnt < 4; cnt++){
    ret = min(ret, cnt + solve(clocks, swtch + 1));
    push(clocks, swtch);
  }
  return ret;
}
void solution(){
  vector<int> clocks; 
  for(int i = 0, tmp; i < 16; i++){
    cin >> tmp;
    clocks.push_back(tmp);
  }
  cout << solve(clocks, 0) << "\n";
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