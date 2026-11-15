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

        if (movies[m].first <
            movies[cur]
                .second) // if the middle starts before the current ends ->
            l = m + 1;   // starts too early
        else
            r = m; // might be the first that starts before it
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