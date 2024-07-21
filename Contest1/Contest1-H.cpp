#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_A = 1000000;

void solve() {
	int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(MAX_A + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int max_gcd = 1;
    for (int i = MAX_A; i >= 1; i--) {
        int divisors_cnt = 0;
        for (int j = i; j <= MAX_A; j += i) {
            divisors_cnt += cnt[j];
        }
        if (divisors_cnt >= 2) {
            max_gcd = i;
            break;
        }
    }

    cout << max_gcd << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
