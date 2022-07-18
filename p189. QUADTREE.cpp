#include <bits/stdc++.h>
using namespace std;

const long long MAX_SIZE = 1 << 10;
char decompressed[MAX_SIZE][MAX_SIZE];
int tc;
string str;

void decompress(string::iterator& it, int x, int y, int size){
  char head = *(it++);
  if(head == 'b' or head == 'w'){
    for(int dx = 0; dx < size; dx++){
      for(int dy = 0; dy < size; dy++){
        decompressed[x + dx][y + dy] = head;
      }
    }
  }else{
    int half = size/2;
    decompress(it, x, y, half);
    decompress(it, x + half, y, half);
    decompress(it, x + half, y + half, half);
    decompress(it, x, y + half, half);
  }
}

string reverse(string::iterator& it){
  char head = *it;
  ++it;
  if(head == 'b' or head == 'w') return string(1, head);
  string upperLeft = reverse(it);
  string upperRight = reverse(it);
  string lowerLeft = reverse(it);
  string lowerRight = reverse(it);
  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
void solution(){
  cin >> str;
  string::iterator it = str.begin();
  decompress(it, 0, 0, str.length());
  it = str.begin();
  cout << reverse(it) << "\n";
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while(tc--){
    solution();
  } 

  return 0;
}