#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<int> cnt(M + 1, 0);

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        cnt[v]++;
    }

    int first_max = 0, second_max = 0;
    for (int i = 1; i <= M; i++) {
        if (cnt[i] > first_max) {
            second_max = first_max;
            first_max = cnt[i];
        } else if (cnt[i] > second_max && cnt[i] < first_max) {
            second_max = cnt[i];
        }
    }

    int ans = -1;
    for (int i = 1; i <= M; i++) {
        if (cnt[i] == second_max) {
            if (ans == -1 || i < ans) {
                ans = i;
            }
        }
    }
    
    if(cnt[ans] == 0 && ans != -1) ans = -1;

    if (ans == -1) {
        cout << "NONE" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
