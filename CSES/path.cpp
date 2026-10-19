#include "bits/stdc++.h"

using namespace std;
string directions;

int saved[48 * 64 * 8 * 48];

unordered_set<int> visited;

// if too slow, memoize
int dfs(int x, int y, size_t index) {
    if (index == directions.size()) {
        // cout << x << ' ' << y << '\n';
        return ((x == 0 && y == 6) ? 1 : 0);
    }

    if (visited.find(x * 8 + y) != visited.end()) {
        return 0;
    }

    if (saved[index * 64 + x * 8 + y] != -1) {
        return saved[index * 64 + x * 8 + y];
    }

    char instruction = directions[index];

    int s = 0;
    visited.insert(x * 8 + y);
    index++;

    for (char compare : {'U', 'D', 'L', 'R'}) {
        if (instruction != compare && instruction != '?') {
            continue;
        }

        int nx = x;
        int ny = y;

        if (compare == 'U') {
            ny--;
        }
        if (compare == 'D') {
            ny++;
        }
        if (compare == 'R') {
            nx++;
        }
        if (compare == 'L') {
            nx--;
        }

        if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7) {
            continue;
        }

        s += dfs(nx, ny, index);
    }

    index--;
    visited.erase(x * 8 + y);

    saved[index * 64 + x * 8 + y] = s;

    return s;
}

int main() {
    cin >> directions;
    fill(begin(saved), end(saved), -1);

    cout << dfs(0, 0, 0) << "\n";

    return 0;
}