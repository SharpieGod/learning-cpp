#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    int M;

    cin >> M >> N;

    int cx, cy, r;
    cin >> cx >> cy >> r;

    vector<pair<double, double>> mouses;
    vector<pair<double, double>> hairties;

    for (int i = 0; i < N; i++) {
        int x, y;

        cin >> x >> y;

        mouses.emplace_back((double)x, (double)y);
    }

    for (int i = 0; i < M; i++) {
        int x, y;

        cin >> x >> y;

        hairties.emplace_back((double)x, (double)y);
    }

    int count = 0;

    for (auto [xm, ym] : mouses) {
        for (auto [xh, yh] : hairties) {
            // y0 = ym
            // y1 = yh
            double m = (yh - ym) / (xh - xm);
            double b = ym - xm * m;
            double u = b - cy;

            double a = m * m + 1;
            double p = 2 * m * u - 2 * cx;
            double q = u * u + cx * cx - r * r;

            if ((p * p - 4 * a * q) < 0 || a == 0) {
                continue;
            }

            count += 1;
        }
    }

    cout << count << "\n";
}