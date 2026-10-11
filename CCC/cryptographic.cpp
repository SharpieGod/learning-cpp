#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern;
    cin >> pattern;

    int n;
    cin >> n;

    vector<pair<char, int>> data;
    data.reserve(pattern.size() / 2);

    int pattern_len = 0;
    for (int i = 0; i < pattern.size() / 2 + 1; i += 2) {

        data.push_back({pattern.at(i), pattern.at(i) - '0'});
        pattern_len += (int)(pattern.at(i) - '0');
    }

    int cumulative_sum = 0;
    cout << pattern_len;
    for (auto [ch, count] : data) {
        cumulative_sum += count;

        if ((n % pattern_len) > cumulative_sum) {
            continue;
        }

        cout << ch << "\n";

        break;
    }
    return 0;
}
