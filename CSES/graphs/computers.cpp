#include "bits/stdc++.h"

using namespace std;

int n;
vector<vector<int>> connections;

int main() {
    int c;
    cin >> n >> c;

    connections.assign(n, {});

    for (int i = 0; i < c; i++) {
        int from, to;

        cin >> from >> to;
        from--;
        to--;

        connections[from].push_back(to);
        connections[to].push_back(from);
    }

    vector<optional<int>> shortest(n, nullopt);
    queue<pair<int, optional<int>>> q;
    q.push({0, nullopt});

    while (!q.empty()) {
        auto [from, prev] = q.front();
        q.pop();

        if (shortest[from].has_value() || from == 0 && prev != nullopt) {
            continue;
        }

        if (prev.has_value()) {
            shortest[from] = prev.value();
        }

        if (from == n - 1) {
            break;
        }

        for (auto to : connections[from]) {
            q.push({to, from});
        }
    }

    vector<int> path;

    path.push_back(n - 1);
    int cur = n - 1;

    if (!shortest[n - 1].has_value()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (shortest[cur].has_value()) {
        int prev = shortest[cur].value();

        path.push_back(prev);
        cur = prev;
    }

    cout << path.size() << '\n';

    reverse(path.begin(), path.end());

    for (auto node : path) {
        cout << node + 1 << ' ';
    }

    cout << '\n';
}