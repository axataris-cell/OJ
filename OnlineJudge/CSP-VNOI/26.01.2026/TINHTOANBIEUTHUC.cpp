#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<ll> val;
    stack<string> func;

    for (int i = 0; i < (int)s.size(); ) {
        if (isdigit(s[i])) {
            ll x = 0;
            while (i < (int)s.size() && isdigit(s[i])) {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            val.push(x);
        }
        else if (isalpha(s[i])) {
            string f;
            while (isalpha(s[i])) {
                f.push_back(s[i]);
                i++;
            }
            func.push(f);
        }
        else if (s[i] == ')') {
            ll b = val.top(); val.pop();
            ll a = val.top(); val.pop();
            string f = func.top(); func.pop();

            if (f == "SUM") val.push(a + b);
            else if (f == "DIF") val.push(a - b);
            else if (f == "MAX") val.push(max(a, b));
            else if (f == "MIN") val.push(min(a, b));
            else if (f == "GCD") val.push(std::gcd(llabs(a), llabs(b)));

            i++;
        }
        else {
            i++; // b? qua '(' ho?c ','
        }
    }

    cout << val.top();
    return 0;
}
