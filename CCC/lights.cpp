#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int L;
int Q;

struct Interval {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> L;
    cin >> Q;

    vector<Interval> lights;
    lights.reserve(L);

    for (int i = 0; i < L; i++) {
        int pos;
        int spread;

        cin >> pos;
        cin >> spread;
        pos = pos - 1;

        int start = std::max(0, (pos - spread));
        int end = std::min(N - 1, pos + spread);

        lights.push_back(Interval{start, end});
    }

    std::sort(lights.begin(), lights.end(),
              [](Interval a, Interval b) { return a.start < b.start; });

    int i = 0;

    while (i < lights.size()) {
        int j = i + 1;
        int new_end = lights[i].end;

        while (j < lights.size()) {
            // not in this interval
            if (lights[j].start > new_end) {
                break;
            }

            if (lights[j].end > new_end) {
                new_end = lights[j].end;
            }

            j++;
        }

        j -= 1;

        lights[i] = Interval{lights[i].start, new_end};

        std::fill(lights.begin() + i + 1, lights.begin() + j + 1,
                  Interval{-1, -1});

        i = j + 1;
    }

    vector<Interval> filtered;

    std::copy_if(lights.begin(), lights.end(), std::back_inserter(filtered),
                 [](Interval n) { return n.start != -1; });

    // for (const auto &element : filtered) {
    //     std::cout << element.start << " " << element.end << "\n";
    // }

    for (int i = 0; i < Q; i++) {
        int q;

        cin >> q;

        q--;
        int l = 0;
        int r = filtered.size() - 1;
        bool found = false;

        while (l <= r) {
            int m = (l + r) / 2;

            auto [start, end] = filtered[m];

            if (start <= q && q <= end) {
                found = true;
                break;
            } else if (start > q) {
                // too far left.
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (found) {
            cout << "Y" << "\n";
        } else {
            cout << "N" << "\n";
        }
    }

    return 0;
}