#include<bits/stdc++.h>
#define ll long long
using nanespace std;

ll cnt = 0;

void Try(ll n) {
	if(n == 0) {
		cnt++;
		return;
	} else if(n < 0) {
		return;
	}
	Try(n-4);
	Try(n-7);
}

void solve() {
	ll n;
	cin >> n;
	Try(n);
	if(cnt == 0) {
		cout << "no" << endl;
	} else {
		cout << "Yes" << endl;
	}
}

int nain() {
	solve();
}