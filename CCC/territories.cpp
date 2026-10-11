#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int R;
int C;
int M;
int val_at(int x, int y) { return (y * C + x) % (M) + 1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R;
    cin >> C;
    cin >> M;
    int prev[C] = {0};
    int cur[C] = {0};

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            int min = prev[x];

            if (x > 0) {
                min = std::min(prev[x - 1], min);
            }

            if (x < C - 1) {
                min = std::min(prev[x + 1], min);
            }

            cur[x] = min + val_at(x, y);
        }

        for (int i = 0; i < C; i++) {
            // cout << cur[i] << " ";
            prev[i] = cur[i];
        }

        std::memset(cur, 0, C);

        // cout << "\n";
    }

    cout << *std::min_element(prev, prev + C) << "\n";

    return 0;
}
