#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	ll n, f, k;
	cin >> n >> f >> k;
	k--, f--;
	int a[100000] = {0};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll tmp = a[f];
	sort(a, a+n, greater<int>());
	if(tmp >= a[k] && tmp != a[k+1]) {
		cout << "YES\n";
	} else if(tmp >= a[k] && tmp == a[k+1]) {
		cout << "MAYBE\n";
	} else {
		cout << "NO\n";
	}
}
	
int main() {
	int t;
	cin >> t;
	while(t--) solve();
}