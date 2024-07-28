#include<bits/stdc++.h>
using namespace std;

bool is_sorted(const vector<int>& P) {
    for (int i = 1; i < P.size(); ++i) {
        if (P[i] < P[i-1]) return false;
    }
    return true;
}

void swap1(vector<int>& P, int N) {
    for (int i = 0; i < 2 * N; i += 2) {
        swap(P[i], P[i + 1]);
    }
}

void swap2(vector<int>& P, int N) {
    for (int i = 0; i < N; ++i) {
        swap(P[i], P[i + N]);
    }
}

int min_operations(int N, vector<int> P) {
    set<vector<int>> visited;
    queue<pair<vector<int>, int>> q;
    q.push({P, 0});
    visited.insert(P);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (is_sorted(current)) {
            return steps;
        }

        vector<int> next = current;

        swap1(next, N);
        if (visited.find(next) == visited.end()) {
            q.push({next, steps + 1});
            visited.insert(next);
        }

        next = current;

        swap2(next, N);
        if (visited.find(next) == visited.end()) {
            q.push({next, steps + 1});
            visited.insert(next);
        }
    }

    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> P(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> P[i];
    }

    int result = min_operations(N, P);
    cout << result << endl;

    return 0;
}
