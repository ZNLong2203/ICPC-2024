#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];
    
    vector<int> reverse_cnt(s.size() + 1, 0);
    for(int i = 0; i < n; i++) {
    	reverse_cnt[m[i] - 1]++;
	}
	
	int current_reverse = 0;
	for(int i = 0; i < s.size() / 2; i++) {
		current_reverse += reverse_cnt[i];
		if(current_reverse % 2 != 0) {
			swap(s[i], s[s.size() - i - 1]);
		}
	}
	cout << s << endl;
}

int main() {
    solve();
}
