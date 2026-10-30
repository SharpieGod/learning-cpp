#include <iostream>

using namespace std;

pair<int, int> knight_steps[4] = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int invalid_spaces(int x, int y, int k) {
    if (x >= k / 2)
        x = k - x - 1;

    if (y >= k / 2)
        y = k - y - 1;
    if (x == 0 && y == 0) {
        return 2;
    }

    if (x == 1 && y == 0 || x == 0 && y == 1) {
        return 3;
    }

    if (y == 0 && x >= 2 || x == 0 && y >= 2 || x == 1 && y == 1) {
        return 4;
    }

    if (y == 1 && x >= 2 || x == 1 && y >= 2) {
        return 6;
    }

    if (x >= 2 && y >= 2) {
        // cout << y << " ";
        return 8;
    }

    return -1;
}

int correct_invalid_spaces(int x, int y, int k) {
    int count = 0;

    for (auto [dx, dy] : knight_steps) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx >= k || ny < 0 || ny >= k) {
            continue;
        }

        count += 1;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (unsigned long long int k = 1; k < n + 1; k++) {

        unsigned long long int s = k * k * (k * k - 1) / 2;

        s -= 4 * (k - 1) * (k - 2);
        cout << s << '\n';
    }

    return 0;
}