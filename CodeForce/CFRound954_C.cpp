#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	string s1;
	cin >> s1;
	vector<int> ch(m);
	for(int i = 0; i < m; i++) {
		cin >> ch[i];
	}
	sort(ch.begin(),ch.end());
	string s2;
	cin >> s2;
	sort(s2.begin(), s2.end(), greater<char>());
	for(int i = 0; i < m; i++) {
		if(i != 0 && ch[i] == ch[i-1]) continue;
		s1[ch[i]-1] = s2[s2.size()-1];
		s2.pop_back();
	}
	cout << s1 << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}