#include "bits/stdc++.h"

using namespace std;

int m, n;
vector<bool> grid;
pair<int, int> player;
vector<pair<int, int>> monsters;

constexpr pair<int, int> DIRECTIONS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    cin >> n >> m;
    grid.assign(n * m, false);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;

            grid[r * m + c] = ch == '#';

            if (ch == 'A') {
                player = {r, c};
            }

            if (ch == 'M') {
                monsters.push_back({r, c});
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;
    queue<pair<int, int>> monster_q;
    q.push({player, -1});

    for (auto p : monsters) {
        monster_q.push(p);
    }

    vector<int> player_visited(n * m, -1);
    vector<bool> monster_visited(n * m, false);

    while (1) {
        queue<pair<int, int>> next_monster_q;

        while (!monster_q.empty()) {
            auto [r, c] = monster_q.front();
            monster_q.pop();

            if (r < 0 || r >= n || c < 0 || c >= m || grid[r * m + c] ||
                monster_visited[r * m + c]) {
                continue;
            }

            monster_visited[r * m + c] = true;

            for (int i = 0; i < 4; i++) {
                auto [dr, dc] = DIRECTIONS[i];

                next_monster_q.push({r + dr, c + dc});
            }
        }

        monster_q = next_monster_q;

        if (q.empty()) {
            cout << "NO\n";
            return 0;
        }

        queue<pair<pair<int, int>, int>> next_queue;

        while (!q.empty()) {
            auto [pos, prev] = q.front();
            q.pop();

            auto [r, c] = pos;

            if (r < 0 || r >= n || c < 0 || c >= m ||
                (r == player.first && c == player.second && prev != -1) ||
                grid[r * m + c] || player_visited[r * m + c] != -1 ||
                monster_visited[r * m + c]) {
                continue;
            }

            player_visited[r * m + c] = prev;

            if (r == 0 || c == 0 || r == n - 1 || c == m - 1) {
                // win-condition
                cout << "YES\n";

                vector<size_t> path;

                while (player_visited[r * m + c] != -1) {
                    int prev = player_visited[r * m + c];
                    path.push_back(prev);

                    auto [dr, dc] = DIRECTIONS[prev];

                    r -= dr;
                    c -= dc;
                }

                cout << path.size() << '\n';

                reverse(path.begin(), path.end());

                for (auto d : path) {
                    cout << "DURL"[d];
                }
                cout << '\n';

                return 0;
            }

            for (int i = 0; i < 4; i++) {
                auto [dr, dc] = DIRECTIONS[i];

                next_queue.push({{r + dr, c + dc}, i});
            }
        }

        q = next_queue;
    }

    return 0;
}