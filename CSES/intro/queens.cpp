#include "bits/stdc++.h"

using namespace std;

vector<int> reserved;
vector<int> cur_queens;
int attacked_squares[64] = {0};

pair<int, int> directions[8] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int total = 0;

void queens(int lp) {
    // cout << cur_queens.size() << ": " << lr << " " << lc << "\n";
    // std::this_thread::sleep_for(std::chrono::milliseconds(200));
    if (cur_queens.size() == 8) {
        total++;
        return;
    }

    for (int p = lp; p < 64; p++) {
        int r = p / 8;
        int c = p % 8;

        if (find(reserved.begin(), reserved.end(),
                 r * 8 + c) != // is it reserved
                reserved.end() ||
            find(cur_queens.begin(), cur_queens.end(),
                 r * 8 + c) != // is a queen already there
                cur_queens.end() ||
            attacked_squares[r * 8 + c] > 0) {
            continue;
        }

        vector<int> saved_attacks;

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            while (!(nr < 0 || nc < 0 || nr >= 8 || nc >= 8)) {
                attacked_squares[nr * 8 + nc]++;
                saved_attacks.push_back(nr * 8 + nc);

                nr += dr;
                nc += dc;
            }
        }

        cur_queens.push_back(r * 8 + c);

        queens(p);

        cur_queens.pop_back();

        for (auto sp : saved_attacks) {
            attacked_squares[sp]--;
        }
    }
}

int main() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            char ch;
            cin >> ch;

            if (ch == '*') {
                reserved.push_back(r * 8 + c);
            }
        }
    }

    queens(0);

    cout << total << "\n";

    return 0;
}