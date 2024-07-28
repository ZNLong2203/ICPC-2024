#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		while(v[i] >= 1 && v[i] % 2 == 0) {
			ans++;
			v[i] /= 2;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
}