#include "bits/stdc++.h"

using namespace std;

int main() {
    size_t n;
    cin >> n;

    vector<int> starts(n);
    vector<int> ends(n);

    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;

        starts[i] = a;
        ends[i] = b;
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    size_t s = 0, e = 0;

    int mx = 0;
    int c = 0;

    while (s < n && e < n) {
        if (starts[s] < ends[e]) {
            s++;
            c++;
        } else {
            e++;
            c--;
        }

        mx = max(mx, c);
    }

    cout << mx << '\n';
}