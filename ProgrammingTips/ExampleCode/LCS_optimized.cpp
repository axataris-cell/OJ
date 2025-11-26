#include <bits/stdc++.h>
using namespace std;

static const int AL = 26; // alphabet = lowercase

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    // next_pos[i][c] = vị trí xuất hiện đầu tiên của chữ c kể từ index i trong b
    vector<array<int, AL>> next_pos(m + 2);
    for (int c = 0; c < AL; c++) next_pos[m][c] = next_pos[m+1][c] = m;

    for (int i = m - 1; i >= 0; i--) {
        next_pos[i] = next_pos[i + 1];
        next_pos[i][b[i] - 'a'] = i;
    }

    string lcs = "";
    int pos = 0; // vị trí hiện tại trong b

    for (char ch : a) {
        int c = ch - 'a';
        if (pos >= m) break;

        int nxt = next_pos[pos][c];
        if (nxt < m) {
            lcs += ch;
            pos = nxt + 1;
        }
    }

    cout << lcs;
}
