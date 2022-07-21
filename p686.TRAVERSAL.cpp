#include <bits/stdc++.h>
using namespace std;

vector<int> sslice(const vector<int>& v, int a, int b){
  return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
  const int N = preorder.size();
  if(preorder.empty()) return;
  const int root = preorder[0];

  const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
  const int R = N - 1 - L;
  printPostOrder(sslice(preorder, 1, L + 1), sslice(inorder, 0, L));
  printPostOrder(sslice(preorder, L + 1, N), sslice(inorder, L + 1, N));
  cout << root << ' ';
}

void solution(){
  vector<int> a, b;
  int N; cin >> N;
  a.resize(N); b.resize(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  for(int i = 0; i < N; i++){
    cin >> b[i];
  }
  printPostOrder(a, b);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);


  int C;
  cin >> C;
  while(C--){
    solution();
  }

  return 0;
}