#include "bits/stdc++.h"

using namespace std;

int n;

vector<bool> current;
vector<vector<bool>> all;
int ones;

void build() {
    if (current.size() == n) {
        all.push_back(current);
        return;
    }

    if (ones % 2 == 0) {
        current.push_back(false);
        build();
        current.pop_back();

        current.push_back(true);
        ones += 1;
        build();
        ones -= 1;
        current.pop_back();
    } else {
        current.push_back(true);
        ones += 1;
        build();
        ones -= 1;
        current.pop_back();

        current.push_back(false);
        build();
        current.pop_back();
    }
}

int main() {
    cin >> n;

    // 0
    // 1

    // 000
    // 001
    // 011
    // 010
    // 110
    // 111
    // 101
    // 100

    build();

    for (auto v : all) {
        for (bool b : v) {
            cout << (b ? "1" : "0");
        }
        cout << "\n";
    }

    return 0;
}