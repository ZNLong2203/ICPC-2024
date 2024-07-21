#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	ll ax, bx, cx;
	ax = abs(a-b) + abs(a-c);
	bx = abs(b-a) + abs(b-c);
	cx = abs(c-a) + abs(c-b);
	cout << min(ax, min(bx, cx)) << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}