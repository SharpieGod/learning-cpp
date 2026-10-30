#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;

    vector<int> data;
    data.reserve(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        data.push_back(x);
    }

    int cur_min = data.front();
    long long int sum = 0;

    for (int i = 1; i < n; i++) {
        // cout << cur_min << " " << data[i] << "\n";
        if (data[i] <= cur_min) {
            sum += cur_min - data[i];
        } else {
            cur_min = data[i];
        }
    }

    cout << sum << "\n";

    return 0;
}
