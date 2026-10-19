#include "bits/stdc++.h"

using namespace std;

vector<int> A;
vector<int> B;

// value -> indicies
unordered_map<int, vector<size_t>> indicies;

struct Range {
    int value;
    size_t start;
    size_t end; // not inclusive
};

void dfs() {}

int main() {
    int N;

    cin >> N;

    A.reserve(N);
    B.reserve(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        indicies[x].push_back(A.size());
        A.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        B.push_back(x);
    }

    // cout << A[0] << "\n";

    size_t l = 0, r = 0;

    vector<Range> ranges;

    while (l < B.size()) {
        r = l + 1;
        int n = B[l];

        while (r < B.size() && B[r] == n) {
            r++;
        }

        // instead of adding these moves directly, store them as (start, ACTUAL
        // LOCATION, end). then solve for order seperatly, after these
        // calculations

        ranges.push_back({n, l, r});
        l = r;
    }

    return 0;
}