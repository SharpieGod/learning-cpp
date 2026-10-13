#include "bits/stdc++.h"

using namespace std;
vector<int> apples;

int main() {
    int n;
    cin >> n;

    int diff = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        apples.push_back(a);
    }

    sort(apples.begin(), apples.end(), greater<int>());

    while (!apples.empty()) {
        int top = apples.back();
        apples.pop_back();
    }
}