#include <bits/stdc++.h>
#define el '\n'

using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const int NTEST = 20;
const string PROBLEM = "BAI1";
const string BRUTE = "Brute";
const string SOL = "Sol";

int gen(int l, int r) {
    // assert(l < r); 
    return mt() % (r - l + 1) + l; // sinh so ngau nhien tu l -> r
}

void gentest(ofstream &out, int id) {
    int n = gen(1, 50);
    out << n << el;
    for (int i = 1; i <= n; i++) {
        out << gen(1, 1e3) << ' ';
    }
}

bool comp(const string &_a, const string &_b) {
    ifstream a(_a), b(_b);
    string s1, s2;
    while (true) {
        bool c1 = (bool)getline(a, s1);
        bool c2 = (bool)getline(b, s2);

        if (c1 != c2) return false;
        if (!c1 && !c2) return true;

        if (s1 != s2) return false;
    }
}
 
int main() {
    system("mkdir Test");
    system(("mkdir Test\\" + PROBLEM).c_str());
    for (int i = 1; i <= NTEST; i++) {
        string id = to_string(i);
        string testdir = "Test\\" + PROBLEM + "\\TEST" + id;
        system(("mkdir " + testdir).c_str());
        string input = testdir + "\\" + PROBLEM + ".INP"; // input sinh ra
        string output = testdir + "\\" + PROBLEM + ".ANS"; // dap an dung
        string solution = testdir + "\\" + PROBLEM + ".OUT"; // dap an can so sanh

        ofstream out(input); // output file
        gentest(out, i);
        out.close();

        {
            double bf = (double)clock() / (double)CLOCKS_PER_SEC;
            system((BRUTE + ".exe < " + input + " > " + output).c_str());
            double af = (double)clock() / (double)CLOCKS_PER_SEC;
            cout << "Test " << id << " made in " << af - bf << " seconds" << el;
        }

        {
            double bf = (double)clock() / (double)CLOCKS_PER_SEC;
            system((SOL + ".exe < " + input + " > " + solution).c_str());
            double af = (double)clock() / (double)CLOCKS_PER_SEC;
            cout << "Test " << id << " made in " << af - bf << " seconds" << el;
        }

        if (!comp(output, solution)) {
            cout << "WA at test " << id << el;
            return 0;
        }
    }
}