#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string pat;
    cin >> pat;

    int max;

    int l = 0;
    int r;

    while (l < pat.size()) {
        char ch = pat.at(l);
        r = l + 1;

        while (r < pat.size() && pat.at(r) == ch) {
            r += 1;
        }

        max = std::max(max, r - l);

        l = r;
    }

    cout << max << '\n';

    return 0;
}
