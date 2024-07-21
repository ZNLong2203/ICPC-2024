#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n, m;
	cin >> n;
	vector<int> a(n), b(n);
	set<int> s;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	
	cin >> m;
	map<ll,ll> mp;
	for(int i = 0; i < m; i++) {
		ll x; cin >> x;
		mp[x]++;
		if(i == m-1) {
			if(s.find(x) == s.end()) {
				cout << "NO\n";
				return;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i] && !mp[b[i]]) {
			cout << "NO\n";
			return;
		} else if(a[i] != b[i] && mp[b[i]] > 0) {
			mp[b[i]]--;
		}
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}