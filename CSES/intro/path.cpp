#include "bits/stdc++.h"

using namespace std;
string directions;

bool visited[7][7];

int dfs(int x, int y, size_t index) {
    if (x == 0 && y == 6) {
        // cout << x << ' ' << y << '\n';
        return ((index == 48) ? 1 : 0);
    }

    if (visited[x][y]) {
        return 0;
    }

    char instruction = directions[index];

    int s = 0;
    visited[x][y] = true;
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
    visited[x][y] = false;

    return s;
}

int main() {
    cin >> directions;

    cout << dfs(0, 0, 0) << "\n";

    return 0;
}