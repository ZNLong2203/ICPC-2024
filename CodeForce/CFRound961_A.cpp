#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if(k == 0) {
		cout << 0 << endl;
		return;
	}
	if(n >= k) {
		cout << 1 << endl;
		return;
	} else {
		k-=n;
		ans++;
		n--;
	}
	ll cnt = 0;
	while(k > 0) {
		k -= n;
		cnt++;
		ans++;
		if(cnt == 2) {
			cnt = 0;
			n--;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}