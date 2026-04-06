#include <bits/stdc++.h>
using namespace std;
#define el '\n'

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const int ntest = 20;
const string problem = "A";
const string filename = "brute";
const string solname = "sol";

int gen(int l, int r) {
    return mt() % (r - l + 1) + l;
}

void gentest(ofstream &out, int id) {
    
}

bool comp(const string &f1, const string &f2) {
    ifstream a(f1), b(f2);

    string s1, s2;
    while (true) {
        bool ok1 = (bool)getline(a, s1);
        bool ok2 = (bool)getline(b, s2);

        if (ok1 != ok2) return false;
        if (!ok1 && !ok2) return true;

        if (s1 != s2) return false;
    }
}

int main() {
    system("mkdir Test");
    system(("mkdir Test\" + problem).c_str());

    for (int i = 1; i <= ntest; i++) {
        string id = to_string(i);
        string testdir = "Test\" + problem + "\TEST" + id;
        string input = testdir + "\" + problem + ".INP";
        string output = testdir + "\" + problem + ".ANS";
        string tout = testdir + "\" + solname + ".OUT";
        system(("mkdir " + testdir).c_str());

        ofstream inputfile(input.c_str());
        gentest(inputfile, i);
        inputfile.close();

        {
            double before = (double)clock() / (double)CLOCKS_PER_SEC;
            system((filename + ".exe < " + input + " > " + output).c_str());
            double after = (double)clock() / (double)CLOCKS_PER_SEC;
            double elapsed = after - before;
            cout << "Brute " << id << " in " << elapsed << el;
        }
        {
            double before = (double)clock() / (double)CLOCKS_PER_SEC;
            system((solname + ".exe < " + input + " > " + tout).c_str());
            double after = (double)clock() / (double)CLOCKS_PER_SEC;
            double elapsed = after - before;
            cout << "Solution " << id << " in " << elapsed << el << el;
        }

        if (!comp(output, tout)) {
            cout << "WA at test " << id << el;
            break;
        }
    }

    system("pause");
}