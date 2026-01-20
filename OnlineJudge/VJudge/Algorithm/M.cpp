#include <bits/stdc++.h>
using namespace std;

int p[10], used[10];

void testcase() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        p[1] = i; used[i] = 1;

        if (n > 1) for (int j = 1; j <= n; j++) {
            if (used[j]) continue;
            p[2] = j; used[j] = 1;

            if (n > 2) for (int k = 1; k <= n; k++) {
                if (used[k]) continue;
                p[3] = k; used[k] = 1;

                if (n > 3) for (int l = 1; l <= n; l++) {
                    if (used[l]) continue;
                    p[4] = l; used[l] = 1;

                    if (n > 4) for (int x = 1; x <= n; x++) {
                        if (used[x]) continue;
                        p[5] = x; used[x] = 1;

                        if (n > 5) for (int y = 1; y <= n; y++) {
                            if (used[y]) continue;
                            p[6] = y; used[y] = 1;

                            if (n > 6) for (int z = 1; z <= n; z++) {
                                if (used[z]) continue;
                                p[7] = z; used[z] = 1;

                                if (n > 7) for (int t = 1; t <= n; t++) {
                                    if (used[t]) continue;
                                    p[8] = t; used[t] = 1;

                                    if (n > 8) for (int f = 1; f <= n; f++) {
                                        if (used[f]) continue;
                                        p[9] = f; used[f] = 1;
                                        for (int v = 1; v <= n; v++) cout << p[v];
                                        cout << "\n";

                                        used[f] = 0;
                                    } 
                                    else {
                                        for (int v = 1; v <= n; v++) cout << p[v];
                                        cout << "\n";
                                    }

                                    used[t] = 0;
                                }
                                else {
                                    for (int v = 1; v <= n; v++) cout << p[v];
                                    cout << "\n";
                                }

                                used[z] = 0;
                            }
                            else {
                                for (int v = 1; v <= n; v++) cout << p[v];
                                cout << "\n";
                            }

                            used[y] = 0;
                        }
                        else {
                            for (int v = 1; v <= n; v++) cout << p[v];
                            cout << "\n";
                        }

                        used[x] = 0;
                    }
                    else {
                        for (int v = 1; v <= n; v++) cout << p[v];
                        cout << "\n";
                    }

                    used[l] = 0;
                }
                else {
                    for (int v = 1; v <= n; v++) cout << p[v];
                    cout << "\n";
                }

                used[k] = 0;
            }
            else {
                for (int v = 1; v <= n; v++) cout << p[v];
                cout << "\n";
            }

            used[j] = 0;
        }
        else {
            for (int v = 1; v <= n; v++) cout << p[v];
            cout << "\n";
        }

        used[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    testcase();
    return 0;
}
