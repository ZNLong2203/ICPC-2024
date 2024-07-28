#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int operations = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            // Number of squaring operations required
            int count = 0;
            while (a[i] < a[i - 1]) {
                if (a[i] > 1e18 / a[i] || a[i] == 1) {
                    cout << -1 << endl;
                    return;
                }
                a[i] *= a[i];
                ++count;
            }
            operations += count;
        }
    }
    
    cout << operations << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
