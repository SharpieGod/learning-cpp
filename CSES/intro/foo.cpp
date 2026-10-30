#include "bits/stdc++.h"

using namespace std;

vector<pair<int, int>> moves;

void hanoi(int block, int from, int to) {
    if (block == 1) {
        moves.push_back({from, to});
        return;
    }

    int other = (6 - from - to);

    hanoi(block - 1, from, other);

    moves.push_back({from, to});

    hanoi(block - 1, other, to);
}

int main() {
    int n;
    cin >> n;

    hanoi(n, 1, 3);

    cout << moves.size() << '\n';

    for (auto [from, to] : moves) {
        // cout << from << " " << to << "\n";
    }

    return 0;
}