#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cal(const string& s) {
    int time = 2; 
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) time += 1;
        else time += 2; 
    }
    return time;
}

void solve() {
    string s;
    cin >> s;
    int max_time = 0;
    string ans = "";

    for (int pos = 0; pos <= s.size(); pos++) { 
        for (char c = 'a'; c <= 'z'; c++) { 
            string new_s = s.substr(0, pos) + c + s.substr(pos);
            int time = cal(new_s);
            if (time > max_time) {
                max_time = time;
                ans = new_s;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}
