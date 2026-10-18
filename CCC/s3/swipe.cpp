#include "bits/stdc++.h"

using namespace std;

vector<int> A;
vector<int> B;

int main() {
    int N;

    cin >> N;

    A.reserve(N);
    B.reserve(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        B.push_back(x);
    }

    // cout << A[0] << "\n";

    size_t l = 0, r = 0;

    vector<pair<bool, pair<size_t, size_t>>> moves;

    while (l < B.size()) {
        r = l + 1;
        int n = B[l];

        while (r < B.size() && B[r] == n) {
            r++;
        }

        // cout << l << " " << r << " " << n << "\n";
        auto found = find(A.begin() + l, A.begin() + l + r, n);
        if (found == A.begin() + l + r) {
            cout << "NO\n";
            return 0;
        }

        int dist = distance(A.begin(), found);

        // we know that n exists in [l, r)

        int swipe_left = dist - l;
        int swipe_right = r - dist - 1;

        // instead of adding these moves directly, store them as (start, ACTUAL
        // LOCATION, end). then solve for order seperatly, after these
        // calculations.

        if (swipe_left > 0) {
            moves.push_back({false, {dist, dist - swipe_left}});
        }

        if (swipe_right > 0) {
            moves.push_back({true, {dist, dist + swipe_right}});
        }

        l = r;
    }

    cout << "YES\n";
    cout << moves.size() << "\n";

    for (auto [is_right, from_to] : moves) {

        auto [from, to] = from_to;

        cout << (is_right ? "R" : "L") << " " << from << " " << to << '\n';
    }

    return 0;
}