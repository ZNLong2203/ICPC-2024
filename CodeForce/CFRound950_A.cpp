#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	ll n, m;
	map<char,ll> mp;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		mp[c]++;
	}
	ll ans = 0;
	for(char i = 'A'; i <= 'G'; i++) {
		if(mp[i] < m) ans += m - mp[i];
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}