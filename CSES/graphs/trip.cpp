#include "bits/stdc++.h"

using namespace std;

int n, c;
vector<vector<int>> roads;

int main() {
    cin >> n >> c;
    roads.assign(n, {});

    while (c--) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        roads[(size_t)a].push_back(b);
        roads[(size_t)b].push_back(a);
    }
}