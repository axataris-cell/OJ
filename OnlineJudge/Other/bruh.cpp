#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
}

void testcase() {
	ifstream fin("input.txt");
	vector<string> words;
	vector<string> lines;
	string line;
	
	while (getline(fin, line)) {
		lines.push_back(line);
	}
	fin.close();
	
	for (int i = 0; i < lines.size(); i++) {
		string temp; cin >> temp;
		words.push_back(temp);
	}
	
	for (int i = 0; i < lines.size(); i++) {
		cout << "#define " << words[i] << ' ' << lines[i] << el;
	}
	for (auto x : words) cout << x << ' ';
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
