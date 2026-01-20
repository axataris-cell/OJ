#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void testcase() {
    string s = "As long as I can make them laugh, it doesn't matter how, I'll be alright. If I succeed in that, the human beings probably won't mind it too much if I remain outside their lives. The one thing I must avoid is becoming offensive in their eyes: I shall be nothing, the wind, the sky.";

    for (char c : s) {
        if (c == ' ') {
            cout << c << flush;
            continue;
        }

        if (isupper(c)) {
            for (char i = 'A'; i <= 'Z'; i++) {
                cout << i << flush;
                delay(1);
                if (i == c) break;
                cout << '\b' << flush;
            }
        }
        else if (islower(c)) {
            for (char i = 'a'; i <= 'z'; i++) {
                cout << i << flush;
                delay(1);
                if (i == c) break;
                cout << '\b' << flush;
            }
        }
        else {
            cout << c << flush;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
