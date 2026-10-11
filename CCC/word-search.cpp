#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

string WORD;
int R;
int C;
vector<char> GRID;
unordered_set<int> seen;

pair<int, int> DIAGONALS[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
pair<int, int> CARDINALS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char at(int r, int c) { return GRID[r * C + c]; }

int dfs(int r, int c, int char_index, int prev_turn, bool is_cardinal,
        bool has_turned) {

    if (!(r >= 0 && r < R && c >= 0 && c < C) ||
        seen.find(r * C + c) != seen.end()) {
        // out of bounds or visited
        return 0;
    }

    char ch = at(r, c);

    if (ch != WORD.at(char_index)) {
        // wrong character present
        return 0;
    }

    if (char_index == WORD.size() - 1) {
        return 1;
    }

    seen.insert(r * C + c);

    auto &dirs = is_cardinal ? CARDINALS : DIAGONALS;

    int count = 0;

    if (has_turned) {
        auto [dr, dc] = dirs[prev_turn];

        count += dfs(r + dr, c + dc, char_index + 1, prev_turn, is_cardinal,
                     has_turned);
    } else {
        for (int i = 0; i < 4; i++) {
            auto [dr, dc] = dirs[i];

            count += dfs(r + dr, c + dc, char_index + 1, i, is_cardinal,
                         prev_turn != -1 && prev_turn != i);
        }
    }

    seen.erase(r * C + c);

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> WORD;
    cin >> R;
    cin >> C;

    GRID.resize(R * C);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> GRID[r * C + c];
        }
    }

    int count = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            count += dfs(r, c, 0, -1, false, false);

            if (WORD.size() > 1) {
                count += dfs(r, c, 0, -1, true, false);
            }
        }
    }

    cout << count << "\n";
    return 0;
}
