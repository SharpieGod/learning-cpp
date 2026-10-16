#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> all;
    vector<size_t> evens;
    vector<size_t> odds;

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;

        cin >> x;
        if (x == -1) {

            vector<vector<int>> computed = {
                {1, 1, 1, 1}, {2, 2, 2, 2}, {2, 1, 1, 1}, {1, 2, 1, 1},
                {1, 1, 2, 1}, {1, 1, 1, 2}, {2, 2, 1, 1}, {2, 1, 2, 1},
                {2, 1, 1, 2}, {1, 1, 2, 2}, {2, 2, 2, 1}, {2, 2, 1, 2},
                {2, 1, 2, 2}, {1, 2, 2, 2}, {1, 2, 1, 2}, {1, 2, 2, 1},

            };
            cout << 14 << "\n";

            for (auto cur_all : computed) {

                evens.clear();
                odds.clear();

                for (int i = 0; i < cur_all.size(); i++) {

                    if (cur_all[i] % 2 == 0) {
                        evens.emplace_back(i);
                    } else {
                        odds.emplace_back(i);
                    }
                }

                if (evens.size() >= 2) {
                    cout << "1 1\n";
                    cout << evens[0] + 1 << "\n";
                    cout << evens[1] + 1 << "\n";
                }

                else if (evens.size() == 1 && odds.size() >= 2) {
                    cout << "2 1\n";
                    cout << odds[0] + 1 << " " << odds[1] + 1 << "\n";
                    cout << evens[0] + 1 << "\n";
                } else {
                    cout << "2 2\n";

                    cout << odds[0] + 1 << " " << odds[1] + 1 << "\n";
                    cout << odds[2] + 1 << " " << odds[3] + 1 << "\n";
                }
            }
            return 0;
        }

        if (x % 2 == 0) {
            evens.emplace_back(i);
        } else {
            odds.emplace_back(i);
        }
        all.emplace_back(x);
    }

    // either
    // 1 even and 1 even
    // 1 even and 2 odds
    // 2 odds and 2 odds

    // not possible to determine if odd odd odd

    if (N >= 4) {
        cout << "YES\n";
        if (evens.size() >= 2) {
            cout << "1 1\n";
            cout << evens[0] + 1 << "\n";
            cout << evens[1] + 1 << "\n";
        }

        else if (evens.size() == 1 && odds.size() >= 2) {
            cout << "2 1\n";
            cout << odds[0] + 1 << " " << odds[1] + 1 << "\n";
            cout << evens[0] + 1 << "\n";
        } else {
            cout << "2 2\n";

            cout << odds[0] + 1 << " " << odds[1] + 1 << "\n";
            cout << odds[2] + 1 << " " << odds[3] + 1 << "\n";
        }

    } else {
        // 0 | 1
        if (all.size() >= 2 && gcd(all[0], all[1]) > 1) {
            cout << "YES\n";
            cout << "1 1\n";
            cout << "1\n";
            cout << "2\n";
        }
        // 0 | 2
        else if (all.size() >= 3 && gcd(all[0], all[2]) > 1) {
            cout << "YES\n";
            cout << "1 1\n";
            cout << "1\n";
            cout << "3\n";
        }
        // 1 | 2
        else if (all.size() >= 3 && gcd(all[1], all[2]) > 1) {
            cout << "YES\n";
            cout << "1 1\n";
            cout << "2\n";
            cout << "3\n";
        }
        // 0 1 | 2
        else if (all.size() >= 3 && gcd(all[0] + all[1], all[2]) > 1) {
            cout << "YES\n";
            cout << "2 1\n";
            cout << "1 2\n";
            cout << "3\n";
        }
        // 0 2 | 1
        else if (all.size() >= 3 && gcd(all[0] + all[2], all[1]) > 1) {
            cout << "YES\n";
            cout << "2 1\n";
            cout << "1 3\n";
            cout << "2\n";
        }
        // 1 2 | 0
        else if (all.size() >= 3 && gcd(all[1] + all[2], all[0]) > 1) {
            cout << "YES\n";
            cout << "2 1\n";
            cout << "2 3\n";
            cout << "1\n";
        } else {
            cout << "NO\n";
        }
    }
}