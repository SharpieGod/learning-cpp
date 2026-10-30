#include "bits/stdc++.h"

using namespace std;
int n, m;

vector<bool> grid;
constexpr pair<int, int> DIRECTIONS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
constexpr char DIRECTIONS_OUT[4] = {'D', 'U', 'R', 'L'};

pair<int, int> A, B;
vector<optional<pair<int, size_t>>> shortest;

int main() {
    cin >> n >> m;

    grid.resize(n * m);
    shortest = vector<optional<pair<int, size_t>>>(n * m, nullopt);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char chr;
            cin >> chr;

            grid[r * m + c] = chr == '#';

            if (chr == 'A') {
                A = {r, c};
            }

            if (chr == 'B') {
                B = {r, c};
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, optional<size_t>>>> q;
    q.emplace(A, pair{0, nullopt});

    while (!q.empty()) {
        auto [pos, d_p] = q.front();
        auto [r, c] = pos;
        auto [d, prev] = d_p;

        q.pop();

        if (r < 0 || r >= n || c < 0 || c >= m || grid[r * m + c] ||
            (pos == A && prev.has_value()) ||
            (shortest[r * m + c].has_value() &&
             shortest[r * m + c].value().first <= d)) {
            continue;
        }

        if (prev.has_value()) {
            shortest[r * m + c] = {d, prev.value()};
        }

        for (int i = 0; i < 4; i++) {
            auto [dr, dc] = DIRECTIONS[i];
            q.emplace(pair{r + dr, c + dc}, pair{d + 1, i});
        }
    }

    // cout << shortest[B.first * m + B.second]->first << '\n';

    if (shortest[B.first * m + B.second].has_value()) {
        cout << "YES\n";

        vector<size_t> path;

        auto [r, c] = B;

        while (shortest[r * m + c].has_value()) {
            auto [_, prev] = shortest[r * m + c].value();

            auto [dr, dc] = DIRECTIONS[prev];
            dr *= -1;
            dc *= -1;

            path.push_back(prev);

            r += dr;
            c += dc;
        }

        cout << path.size() << '\n';

        reverse(path.begin(), path.end());

        for (auto d : path) {
            cout << DIRECTIONS_OUT[d];
        }

        cout << '\n';

    } else {
        cout << "NO\n";
    }

    return 0;
}