#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int N, ST, EN, u, d;
    cin >> N >> ST >> EN >> u >> d;

    if (ST == EN) {
        cout << 0 << endl;
        return;
    }

    vector<int> visited(N + 1, -1);
    queue<int> q;

    q.push(ST);
    visited[ST] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int next_up = current + u;
        int next_down = current - d;

        if (next_up <= N && visited[next_up] == -1) {
            visited[next_up] = visited[current] + 1;
            q.push(next_up);
            if (next_up == EN) {
                cout << visited[next_up] << endl;
                return;
            }
        }

        if (next_down >= 1 && visited[next_down] == -1) {
            visited[next_down] = visited[current] + 1;
            q.push(next_down);
            if (next_down == EN) {
                cout << visited[next_down] << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    solve();
    return 0;
}