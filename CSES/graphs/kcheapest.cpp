#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

priority_queue<ll, vector<ll>, greater<ll>> paths;
bool visited[100001];

size_t n, m;
int k;

void dfs(size_t cur, ll cost, vector<vector<pair<size_t, ll>>> &flights) {

    if (cur == n - 1) {
        paths.push(cost);
        return;
    }

    if (visited[cur]) {
        return;
    }

    visited[cur] = true;

    for (auto [to, c] : flights[cur]) {
        dfs(to, cost + c, flights);
    }

    visited[cur] = false;
}

int main() {
    cin >> n >> m >> k;

    vector<vector<pair<size_t, ll>>> flights(n, vector<pair<size_t, ll>>());

    while (m--) {
        size_t from, to;
        ll c;

        cin >> from >> to >> c;

        from--;
        to--;

        flights[from].push_back({to, c});
    }

    dfs(0, 0, flights);

    while (k--) {
        cout << paths.top() << " ";
        paths.pop();
    }

    cout << '\n';
}