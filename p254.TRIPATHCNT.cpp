#include <bits/stdc++.h>
using namespace std;


int triangle[100][100], cache[100][100], countCache[100][100], n;

int path(int x, int y){
  if(x == n - 1) return triangle[x][y];
  int & ret = cache[x][y];
  if(ret != -1) return ret;
  return ret = triangle[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}

int count(int x, int y){
  if(x == n - 1) return 1;
  int &ret = countCache[x][y];
  if(ret != -1) return ret;
  ret = 0;
  if(path(x + 1, y + 1) >= path(x + 1, y)) ret += count(x + 1, y + 1);
  if(path(x+1, y+1) <= path(x+1, y)) ret += count(x+1, y);
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int c;
  cin >> c;
  while(c--){
    memset(cache, -1, sizeof cache);
    memset(countCache, -1, sizeof countCache);
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= i; j++){
        cin >> triangle[i][j];
      }
    }
    cout << count(0, 0) << "\n";
  }
}