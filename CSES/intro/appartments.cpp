#include "bits/stdc++.h"

using namespace std;

int main() {
    size_t applicant_count, appartment_count;
    int variation;

    cin >> applicant_count >> appartment_count >> variation;

    vector<int> applicants(applicant_count);
    vector<vector<size_t>> choices(applicant_count);

    for (auto &x : applicants) {
        cin >> x;
    }

    for (size_t i = 0; i < appartment_count; i++) {
        int app;
        cin >> app;

        for (size_t j = 0; j < applicant_count; j++) {
            auto wanted = applicants[j];

            if (app - variation <= wanted && wanted <= app + variation) {
                choices[j].push_back(i);
            }
        }
    }

    sort(choices.begin(), choices.end(),
         [](vector<size_t> &a, vector<size_t> &b) {
             return a.size() > b.size();
         });

    cout << choices[0].size() << "\n";

    return 0;
}