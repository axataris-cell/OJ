#include <bits/stdc++.h>
#define el '\n'

using namespace std;

const string NAME = "BFS";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 100;           // number of tests
const string xau ="0123456789abcdefghijklmnopqrstuvxy";

mt19937_64 rd;

int gen(int lo, int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId) {
	// Creating input
    int n, m, l, r, s;
    n = gen(1, 1e5);
    m = gen(1, 1e5);
    s = gen(1, n);
    input << n << " " << m << el;
    
    for (int i = 1; i <= m; i++){
        l = gen(1, n);
        r = gen(l, n);
        input << l << " " << r << el;
    }
    
    // Custom test
//    if (testId == 1) {
//    	input << 123456789;
//    	...
//	}
}

int main(){
    rd.seed(chrono::system_clock::now().time_since_epoch().count());
    for(int i = 0; i < NTEST; i++){
        string id = to_string(i);          // id of current test
       // cerr << i << ' '  << endl;
        cout << "Making test: " << id << el;
        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR " + NAME + "\\Test" + id).c_str()),
            input  = NAME + "\\Test" + id + '\\' + NAME + ".INP",
            output = NAME + "\\Test" + id + '\\' + NAME + ".OUT";

        ofstream inputFile(input.c_str()); // pointer input

        // create input
        makeTest(inputFile, i);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}
