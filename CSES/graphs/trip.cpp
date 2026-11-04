#include "bits/stdc++.h"

using namespace std;

int n, c;
vector<vector<int>> roads;
vector<optional<int>> parent;
vector<bool> visited;

void dfs(int cur, optional<int> prev) {
    if (visited[cur] && prev.has_value()) {
        // hit a cycle in the graph, super duper cool
        vector<int> path;

        int prev_forwards = prev.value();
        int prev_backwards = cur;

        while (prev_backwards != cur) {
            path.push_back(prev_backwards);
            prev_backwards = parent[prev_backwards].value_or(-1);
        }

        reverse(path.begin(), path.end());

        while (prev_forwards != cur) {
            path.push_back(prev_forwards);
            prev_forwards = parent[prev_forwards].value_or(-1);
        }

        cout << path.size() + 2 << '\n';

        cout << cur + 1 << ' ';
        for (auto node : path) {
            cout << node + 1 << " ";
        }
        cout << cur + 1 << '\n';

        exit(0);
    }

    parent[cur] = prev;
    visited[cur] = true;

    for (auto to : roads[cur]) {
        if (to != prev)
            dfs(to, cur);
    }
}

int main() {
    cin >> n >> c;
    roads.assign(n, {});
    parent.assign(n, nullopt);
    visited.assign(n, false);

    vector<int> possible_starts;

    while (c--) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        roads[(size_t)a].push_back(b);
        roads[(size_t)b].push_back(a);

        possible_starts.push_back(a);
        possible_starts.push_back(b);
    }

    for (auto x : possible_starts) {
        if (!visited[x]) {
            parent.assign(n, nullopt);
            dfs(x, nullopt);
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}