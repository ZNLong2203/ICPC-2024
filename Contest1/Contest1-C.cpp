#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int row, int n, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, int& cnt) {
    if (row == n) {
        cnt++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (!cols[col] && !d1[row - col + n - 1] && !d2[row + col]) {
            cols[col] = d1[row - col + n - 1] = d2[row + col] = true;
            solve(row + 1, n, cols, d1, d2, cnt);
            cols[col] = d1[row - col + n - 1] = d2[row + col] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<bool> cols(n, false);
    vector<bool> d1(2 * n - 1, false);
    vector<bool> d2(2 * n - 1, false);
    int cnt = 0;
    
    solve(0, n, cols, d1, d2, cnt);
    cout << cnt << endl;

    return 0;
}
