#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

pair<vector<i64>, vector<i64>> split(i64 n) {
    i64 target = (n + 1) * n / 2 / 2;
    vector<i64> first;
    vector<i64> second;

    while (n > 0) {
        if (target - n >= 0) {
            first.push_back(n);
            target -= n;
        } else {
            second.push_back(n);
        }

        n -= 1;
    }

    return {first, second};
}

int main() {

    i64 n;
    cin >> n;

    if ((n + 1) % 4 == 0 || n % 4 == 0) {
        auto [first, second] = split(n);

        cout << "YES\n";

        cout << first.size() << "\n";

        for (size_t i = 0; i < first.size(); i++) {
            cout << first[i];
            if (i < first.size() - 1)
                cout << " ";
        }
        cout << "\n";
        cout << second.size() << "\n";

        for (size_t i = 0; i < second.size(); i++) {
            cout << second[i];

            if (i < second.size() - 1)
                cout << " ";
        }
        cout << "\n";

    } else {
        cout << "NO\n";
    }

    return 0;
}