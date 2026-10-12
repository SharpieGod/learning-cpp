#include <iostream>
#include <vector>

using namespace std;

int apply_rule(int n) {
    int m = 0;
    while (n > 0) {
        m += (n % 10) * (n % 10);

        n /= 10;
    }

    return m;
}

bool in_tune(int a, int b) {
    vector<int> past_a;

    while (1) {
        past_a.push_back(a);

        a = apply_rule(a);
    }
}

int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int _k = 0; _k < t; _k++) {
        int n;
        cin >> n;

        vector<int> lighthouses;
        lighthouses.reserve(n);

        for (int _m = 0; _m < n; _m++) {
            int l;
            cin >> l;

            lighthouses.push_back(l);
        }

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << i << " " << j << "\n";
                if (in_tune(lighthouses[i], lighthouses[j])) {
                    count += 1;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
