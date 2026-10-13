#include "bits/stdc++.h"

using namespace std;
string input;
vector<string> out;
unordered_map<char, int> char_count;
unordered_map<char, int> building_char_count;

void generate(string building, bool any_left) {
    // cout << building << "\n";
    if (building.size() == input.size()) {
        out.push_back(building);
        return;
    }

    // don't chose to add anything

    bool next_any_left = false;

    for (auto [ch, count] : building_char_count) {
        int remaining = char_count[ch] - count;

        next_any_left = next_any_left && remaining > 0;

        cout << remaining << " " << building << "\n";

        if (any_left) {
            generate(building, next_any_left);
        }

        for (int i = 1; i <= remaining; i++) {

            building.append(i, ch);
            building_char_count[ch] += i;

            generate(building, next_any_left);

            building_char_count[ch] -= i;
        }
    }
}

int main() {
    cin >> input;

    for (auto ch : input) {
        char_count[ch] += 1;
        building_char_count[ch] = 0;
    }

    generate("", true);

    cout << out.size() << "\n";

    for (auto s : out) {
        cout << s << "\n";
    }

    return 0;
}