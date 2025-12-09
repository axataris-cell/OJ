#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> mp;
    string line;

    while (true) {
        if (!getline(cin, line)) return 0;
        if (line == "") break;

        stringstream ss(line);
        string eng, foreign;
        ss >> eng >> foreign;

        mp[foreign] = eng;
    }

    string word;
    while (getline(cin, word)) {
        if (mp.count(word)) cout << mp[word] << "\n";
        else cout << "eh\n";
    }

    return 0;
}
