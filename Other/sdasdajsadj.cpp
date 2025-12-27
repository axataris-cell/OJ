#include <bits/stdc++.h>
using namespace std;
bool colasonguyento(long long n)
{
    if (n == 2 || n == 3)
        return true;
    if (n < 3 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool sochuso (long long n){
    int Countchan = 0;
    int Countle = 0;
    while (n > 0){
        if ((n % 10) % 2 == 0){
            Countchan++;
        }else {
            Countle++;
        }
        n /= 10;
    }
    if (Countchan != Countle) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	long long mang[n];
	int Count = 0;
	for (int i = 0; i < n; i++){
	    cin >> mang[i];
	}
	for (int i = 0; i < n; i++){
	    if (colasonguyento(mang[i]) && sochuso(mang[i])){
	        Count++;
	    }
	}
    cout << Count;
}