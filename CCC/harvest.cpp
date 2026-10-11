#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int R;
int C;
vector<char> grid;

pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R;
    cin >> C;

    grid.resize(R * C);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r * C + c];
        }
    }

    int r, c;

    cin >> r;
    cin >> c;

    queue<int> q;
    unordered_set<int> visited;
    q.push(r * C + c);

    int score = 0;

    while (!q.empty()) {
        int p = q.front();
        q.pop();

        if (grid[p] == '*') {
            continue;
        }

        if (visited.find(p) != visited.end()) {
            continue;
        }

        visited.insert(p);

        if (grid[p] == 'S')
            score += 1;
        else if (grid[p] == 'M')
            score += 5;
        else if (grid[p] == 'L')
            score += 10;

        int r = p / C;
        int c = p % C;
        // cout << "at " << r << ", " << c << " " << grid[p] << "\n";

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            q.push(nr * C + nc);

            // q.push((r + dr) * C + c + dc);
        }
    }

    cout << score << "\n";

    return 0;
}