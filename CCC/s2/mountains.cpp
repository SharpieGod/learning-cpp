#include "bits/stdc++.h"

using namespace std;

vector<int> mountains;
int asymetries[5000 * 5005];

int calc_asymetry(int l, int r) {
    // cout << l << " " << r << "\n";
    if (asymetries[l * mountains.size() + r] != -1) {
        return asymetries[l * mountains.size() + r];
    }

    if (l >= r) {
        return 0;
    }

    int saved = abs(mountains[l] - mountains[r]) + calc_asymetry(l + 1, r - 1);
    asymetries[l * mountains.size() + r] = saved;

    // cout << mountains[l] << " " << mountains[r] << "\n";
    return saved;
}

int least_asymetry_value(int keep) {
    int l = 0;
    int r = keep;

    int minimum = INT_MAX;

    while (r < mountains.size()) {
        minimum = min(minimum, calc_asymetry(l, r));

        l++;
        r++;
    }

    return minimum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(begin(asymetries), end(asymetries), -1);

    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        mountains.push_back(x);
    }

    for (int i = 0; i < mountains.size(); i++) {
        cout << least_asymetry_value(i) << " ";
    }
    cout << "\n";
}