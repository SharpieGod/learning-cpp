#include "bits/stdc++.h"

using namespace std;

int n, m;

using ll = long long int;

vector<bool> visited;
vector<bool> saved;

bool reaches_end(size_t from, vector<vector<size_t>> &connections) {
    if (from == n - 1) {
        return true;
    }

    if (visited[from]) {
        return saved[from];
    }

    visited[from] = true;

    bool reaches = false;

    for (auto to : connections[from]) {

        if (reaches_end(to, connections)) {
            reaches = true;
            break;
        }
    }

    saved[from] = reaches;

    return reaches;
};

int main() {
    cin >> n >> m;

    vector<vector<ll>> weight(n, vector<ll>(n, LONG_LONG_MAX));
    vector<vector<size_t>> connections(n, vector<size_t>{});

    while (m--) {
        int from, to;
        ll score;

        cin >> from >> to >> score;
        from--;
        to--;

        if (weight[from][to] == LONG_LONG_MAX) {

            connections[from].push_back(to);
        }

        // parallel edges exist: keep the best one
        weight[from][to] = min(weight[from][to], -score);
    }

    vector<ll> dist(n, LONG_LONG_MAX);
    visited.assign(n, false);
    saved.assign(n, false);

    dist[0] = 0;

    for (size_t k = 0; k < n; k++) {
        for (size_t i = 0; i < n; i++) {
            for (auto j : connections[i]) {
                auto w = weight[i][j];

                // if i is visited, and if I get to j from i, is that the best?

                if (dist[i] != LONG_LONG_MAX && dist[i] + w < dist[j]) {
                    dist[j] = dist[i] + w;
                }
            }
        }
    }

    // run it once more to see if theres an inf loop

    for (size_t i = 0; i < n; i++) {
        for (auto j : connections[i]) {
            auto w = weight[i][j];

            if (w == LONG_LONG_MAX) {
                continue;
            }

            if (dist[i] != LONG_LONG_MAX && dist[i] + w < dist[j]) {
                // possible inf loop

                // dist[j] = dist[i] + w;

                if (reaches_end(i, connections)) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << -dist[n - 1] << '\n';

    return 0;
}