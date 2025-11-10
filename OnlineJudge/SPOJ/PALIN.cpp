#include <bits/stdc++.h>
using namespace std;

// Increment string number (in place)
void addOne(string &s) {
    int i = s.size() - 1, carry = 1;
    while (i >= 0 && carry) {
        int d = s[i] - '0' + carry;
        s[i] = (d % 10) + '0';
        carry = d / 10;
        i--;
    }
    if (carry) s.insert(s.begin(), '1');
}

// Check if all digits are '9'
bool all9(const string &s) {
    for (char c : s)
        if (c != '9') return false;
    return true;
}

string nextPalindrome(string k) {
    int n = k.size();
    if (all9(k)) {
        string res = "1" + string(n - 1, '0') + "1";
        return res;
    }

    string left = k.substr(0, n / 2);
    string middle = (n % 2 ? string(1, k[n / 2]) : "");
    string rev_left = left;
    reverse(rev_left.begin(), rev_left.end());

    string palindrome = left + middle + rev_left;

    if (palindrome > k)
        return palindrome;

    // Need to increment middle part
    if (n % 2 == 0)
        addOne(left);
    else {
        string mid = left + middle;
        addOne(mid);
        if ((int)mid.size() == (int)(left.size() + 1))
            left = mid.substr(0, left.size());
        else
            left = mid.substr(0, left.size());
        middle = (n % 2 ? string(1, mid[mid.size() - 1]) : "");
    }

    rev_left = left;
    reverse(rev_left.begin(), rev_left.end());
    return left + middle + rev_left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string k;
        cin >> k;
        cout << nextPalindrome(k) << "\n";
    }
    return 0;
}
