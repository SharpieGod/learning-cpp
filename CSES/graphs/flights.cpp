#include "bits/stdc++.h"

using namespace std;

int n, m;
using ll = unsigned long int;
const ll INF = ULONG_MAX;

template <typename T> using min_q = priority_queue<T, vector<T>, greater<T>>;

int main() {
    cin >> n >> m;
    vector<vector<pair<size_t, ll>>> flight(n, vector<pair<size_t, ll>>{});
    while (m--) {
        size_t a, b;
        ll c;

        cin >> a >> b >> c;
        a--;
        b--;

        flight[a].push_back({b, c});
    }

    min_q<pair<ll, pair<size_t, bool>>> q;
    vector<vector<ll>> least(2, vector<ll>(n, INF));

    // least[0][0] = 0;
    least[1][0] = 0;

    q.push({0, {0, true}});

    while (!q.empty()) {
        auto [price, c_d] = q.top();
        auto [cur, has_discount] = c_d;

        q.pop();

        if (price > least[(size_t)has_discount][cur]) {
            continue;
        }

        for (auto [to, c] : flight[cur]) {
            // dont use discount!
            if (price + c < least[(size_t)has_discount][to]) {
                least[(size_t)has_discount][to] = price + c;
                q.push({price + c, {to, has_discount}});
            }

            // if you have discoutn use it?
            if (has_discount && price + c / 2 < least[0][to]) {
                least[0][to] = price + c / 2;
                q.push({price + c / 2, {to, false}});
            }
        }
    }

    cout << least[false][n - 1] << '\n';

    return 0;
}