#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

const int NTEST = 1;

const string PROBLEM = "makima";
const string BRUTE = "brute";
const string SOLUTION = "sol";

const string directory = "D:\\OJ\\Other\\LAB001";
const string BRUTEDIR = "D:\\OJ\\Other\\LAB001\\brute.exe";
const string SOLDIR = "D:\\OJ\\Other\\LAB001\\sol.exe";

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int gen(int l, int r) {
	return mt() % (r - l + 1) + l;
}

void gentest(ofstream &out, int id) {
	int n = gen(1, 20);
	out << n << el;
	for (int i = 1; i <= n; i++) {
		out << gen(1, 10) << ' ';
	}
}

int32_t main() {
//	system("D:");
//	system(("cd " + directory).c_str());
	string testdir = directory + "\\TEST\\" + PROBLEM;
	system(("mkdir " + testdir).c_str());
	for (int _ = 1; _ <= NTEST; _++) {
		string curtest = testdir + "\\TEST" + to_string(_);
		system(("mkdir " + curtest).c_str());
		string inp = curtest + "\\" + PROBLEM + ".INP";
		string out = curtest + "\\" + PROBLEM + ".OUT";
		string ans = curtest + "\\" + PROBLEM + ".ANS";
		{
			ofstream of(inp);
			gentest(of, _);
		}
		system(( BRUTEDIR + " < " + inp + " > " + out).c_str());
		system(( SOLDIR + " < " + inp + " > " + ans).c_str());
	}
}

