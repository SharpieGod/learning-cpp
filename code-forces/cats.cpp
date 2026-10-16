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
            double u = ym - cy - m * xm;
            double a = m * m + 1;
            double b = 2 * m * u - 2 * cx;
            double c = u * u + cx * cx - r * r;

            double descriminant = b * b - 4 * a * c;
            if (descriminant < 0) {
                continue;
            }

            double x_pos = (-b + sqrt(descriminant)) / (2 * a);
            double x_neg = (-b - sqrt(descriminant)) / (2 * a);

            if (!(xm <= xh && (xm <= x_pos && x_pos <= xh) ||
                  xh <= xm && (xh <= x_pos && x_pos <= xm))

            ) {
                continue;
            }

            count += 1;
        }
    }

    cout << count << "\n";
}