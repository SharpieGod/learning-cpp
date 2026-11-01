#include "bits/stdc++.h"

using namespace std;

int n, q;
vector<int> numbers;

vector<int> mins;

int min_in_range(int a, int b) {
    if (a > b) {
        return INT_MAX;
    }

    if (a == b) {
        return numbers[a];
    }

    if (mins[a * n + b] != -1) {
        return mins[a * n + b];
    }

    int m = min(numbers[a], min(numbers[b], min_in_range(a + 1, b - 1)));
    mins[a * n + b] = m;

    return m;
}

int main() {
    cin >> n >> q;
    numbers.assign(n, 0);
    mins.assign(n * n + n, -1);

    for (auto &n : numbers) {
        cin >> n;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << min_in_range(a, b) << '\n';
    }

    return 0;
}