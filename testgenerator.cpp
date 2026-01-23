#include <bits/stdc++.h>
using namespace std;

const string NAME = "hieu1";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 10;           // number of tests
const string xau ="0123456789abcdefghijklmnopqrstuvxy";

mt19937_64 rd;

int Rand(int lo,int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    int n,m,L,R;
    n=Rand(1,100);
    m=Rand(1,100);
    input<<n<<" "<<m<<endl;
    for (int i=1; i<=n; i++){
        L=Rand(1,m);
        R=Rand(L,m);
        input<<L<<" "<<R<<endl;
    }



/*if (testId==0){
        input<<42;
    }
    else
    if (testId==1){
        input<<848;
    }
    else//4 test các so deu khac 0
    if (testId==2){
        input<<686;
    }
    else
    if (testId==3){
        input<<246824682;
    }
    else
    if (testId==4){
        input<<2424242424;
    }
    if (testId==5){
        input<<24246424;
    }
    else//4 test cuoi thoai mai
    if (testId==6){
        input<<868686868686868;
    }
    else
    if (testId==7){
        input<<868686868686864;
    }
    else
    if (testId==8){
        input<<8686868686868;
    }
    else
    if (testId==9){
        input<<282828282828282;
    }
    */

}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();

    rd.seed(randomSeed);
    for(int _ = 0; _ < NTEST; _++){
        string id;          // id of current test
        stringstream ss;
        ss << _;
        ss >> id;
       // cerr << _ << ' '  << endl;
        cout << "Making test: " << id << endl;
        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR " + NAME + "\\Test" + id).c_str()),
            input  = NAME+"\\Test" + id + '\\' + NAME + ".INP",
            output = NAME+"\\Test" + id + '\\' + NAME + ".OUT";


        ofstream inputFile(input.c_str());

        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}
