#include "bits/stdc++.h"

using namespace std;

int n, m;

vector<vector<int>> connections;
vector<bool> explored;

void explore(int from) {
    if (explored[from]) {
        return;
    }

    explored[from] = true;

    for (auto to : connections[from]) {
        explore(to);
    }

    return;
}

int main() {
    cin >> n >> m;

    connections = vector<vector<int>>(n);
    explored = vector<bool>(n, false);

    for (int i = 0; i < m; i++) {
        int from, to;

        cin >> from >> to;
        from--;
        to--;

        connections[from].push_back(to);
        connections[to].push_back(from);
    }
    // first explore all "islands" of nodes.
    // then connect one of each in a circle.

    vector<int> group_heads;

    for (int from = 0; from < n; from++) {
        if (explored[from]) {
            continue;
        }

        explore(from);
        group_heads.push_back(from);
    }

    cout << group_heads.size() - 1 << '\n';

    for (int i = 0; i < group_heads.size() - 1; i++) {
        cout << group_heads[i] + 1 << ' ' << group_heads[i + 1] + 1 << '\n';
    }

    return 0;
}