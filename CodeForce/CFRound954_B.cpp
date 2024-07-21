#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y;
    vector<vector<int>> a(x, vector<int>(y, 0)); 

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            set<int> s;
            if (i > 0) s.insert(a[i-1][j]);
            if (i < x-1) s.insert(a[i+1][j]);
            if (j > 0) s.insert(a[i][j-1]);
            if (j < y-1) s.insert(a[i][j+1]);

            if (!s.empty()) {
                int max_val = *s.rbegin();
                if (a[i][j] > max_val) {
                    a[i][j] = max_val;
                }
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
