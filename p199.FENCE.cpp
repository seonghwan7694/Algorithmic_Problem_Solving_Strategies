#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll C, n;
vector<ll> h;

ll solve(ll left, ll right)
{
	//기저사례
	if (left == right)
		return h[left];

	ll mid = (left + right) / 2;
	ll ret = max(solve(left, mid), solve(mid + 1, right));
	ll lo = mid, hi = mid + 1;
	ll height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (lo <= left || h[lo - 1] < h[hi + 1]))
		{
			hi++;
			height = min(height, h[hi]);
		}
		else
		{
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

void solution(){
  ll tmp;
  h.clear();
  for(int i = 0; i < n; i++){
    cin >> tmp;
    h.push_back(tmp);
  }
  cout << solve(0, h.size() - 1) << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    cin >> n;
    solution();
		break;
  }


  return 0;
}