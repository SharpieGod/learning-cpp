#include "bits/stdc++.h"

using namespace std;
int n, m;
vector<bool> grid;
constexpr pair<int, int> DIRECTIONS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void explore(int r, int c) {
    priority_queue<pair<int, int>> q;
    q.emplace(r, c);

    while (!q.empty()) {
        auto [r, c] = q.top();
        q.pop();

        if (grid[r * m + c]) {
            continue;
        }

        grid[r * m + c] = true;

        for (auto [dr, dc] : DIRECTIONS) {
            int nr = r + dr, nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            q.emplace(nr, nc);
        }
    }
}

int main() {

    cin >> n >> m;

    grid.resize(n * m);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char chr;
            cin >> chr;

            grid[r * m + c] = chr == '#';
        }
    }

    int counter = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (!grid[r * m + c]) {
                explore(r, c);
                counter++;
            }
        }
    }
    cout << counter << '\n';

    return 0;
}