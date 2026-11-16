#include "bits/stdc++.h"

using namespace std;
vector<optional<int>> memo;

int longest(size_t cur, vector<pair<int, int>> &movies) {
    if (cur >= movies.size()) {
        return 0;
    }

    if (memo[cur].has_value()) {
        return memo[cur].value();
    }

    // either watch current moive and see what happens or skip.
    size_t l = cur + 1, r = movies.size();

    while (l < r) {

        size_t m = l + (r - l) / 2;

        if (movies[m].first >= movies[cur].second) {
            r = m; // possible solution
        } else {
            l = m + 1; // movie starts too early
        }
    }
    memo[cur] = max(longest(cur + 1, movies), 1 + longest(l, movies));

    return memo[cur].value();
}

int main() {
    size_t n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    memo.assign(n, nullopt);

    for (auto &[start, end] : movies) {
        cin >> start >> end;
    }

    sort(movies.begin(), movies.end(),
         [](const auto a, const auto b) { return a.first < b.first; });

    // cout << movies[0].second;
    cout << longest(0, movies) << '\n';
    return 0;
}