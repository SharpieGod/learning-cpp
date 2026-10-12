#include <iostream>
#include <vector>

using namespace std;

int next(int n) {
    int m = 0;
    while (n > 0) {
        m += (n % 10) * (n % 10);

        n /= 10;
    }

    return m;
}

bool in_tune(int a, int b) {
    // is there a loop of a.
    // is there a loop of b.

    // if theyre the same at any point, then theyre the same always.
    // if there is a loop in a, and a loop in b, and theyre not the same, then
    // theyre not in tune.

    // slow, fast

    int slow_a = next(a);
    int fast_a = next(slow_a);
    bool a_loops = false;

    int slow_b = next(b);
    int fast_b = next(slow_b);
    bool b_loops = false;

    while (!b_loops || !a_loops) {
        if (!a_loops) {
            slow_a = next(slow_a);
            fast_a = next(next(fast_a));
        }

        if (slow_a == fast_a) {
            a_loops = true;
        }

        if (!b_loops) {
            slow_b = next(slow_b);
            fast_b = next(next(fast_b));
        }

        if (slow_b == fast_b) {
            b_loops = true;
        }
    }

    return slow_a == slow_b;
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

        for (size_t i = 0; i < n - 1; i++) {
            for (size_t j = i + 1; j < n; j++) {
                // cout << i << " " << j << "\n";
                if (in_tune(lighthouses[i], lighthouses[j])) {
                    count += 1;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
