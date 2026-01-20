#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

map<char, string> c1;
map<string, char> c2;

void testcase() {
	int p; cin >> p;
	string s; cin >> s;
	string t; cin >> t;
	if (p == 1) {
		c1[s[0]] = "11"; c1[s[1]] = "12"; c1[s[2]] = "13"; c1[s[3]] = "14"; c1[s[4]] = "15"; c1[s[5]] = "21"; c1[s[6]] = "22"; c1[s[7]] = "23"; c1[s[8]] = "24"; c1[s[9]] = "25"; c1[s[10]] = "31"; c1[s[11]] = "32"; c1[s[12]] = "33"; c1[s[13]] = "34"; c1[s[14]] = "35"; c1[s[15]] = "41"; c1[s[16]] = "42"; c1[s[17]] = "43"; c1[s[18]] = "44"; c1[s[19]] = "45"; c1[s[20]] = "51"; c1[s[21]] = "52"; c1[s[22]] = "53"; c1[s[23]] = "54"; c1[s[24]] = "55";
		for (char c : t) cout << c1[c];
	} else {
		c2["11"] = s[0]; c2["12"] = s[1]; c2["13"] = s[2]; c2["14"] = s[3]; c2["15"] = s[4]; c2["21"] = s[5]; c2["22"] = s[6]; c2["23"] = s[7]; c2["24"] = s[8]; c2["25"] = s[9]; c2["31"] = s[10]; c2["32"] = s[11]; c2["33"] = s[12]; c2["34"] = s[13]; c2["35"] = s[14]; c2["41"] = s[15]; c2["42"] = s[16]; c2["43"] = s[17]; c2["44"] = s[18]; c2["45"] = s[19]; c2["51"] = s[20]; c2["52"] = s[21]; c2["53"] = s[22]; c2["54"] = s[23]; c2["55"] = s[24];
		for (int i = 0; i < t.length(); i += 2) {
			cout << c2[t.substr(i, 2)];
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
