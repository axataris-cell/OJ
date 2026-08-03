#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;

int spf[MAXA + 1];
int appear[MAXA + 1];
int visited[MAXA + 1];

struct PairInfo {
    int p, q;
    int common;
};

void sieve() {
    for (int i = 2; i <= MAXA; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] != i) continue;

        for (int j = i * i; j <= MAXA; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
}

vector<int> factorize(int x) {
    vector<int> primes;

    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);

        while (x % p == 0)
            x /= p;
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;

    vector<int> allPrimes;
    vector<pair<int, int>> allPairs;

    allPairs.reserve(20LL * n);

    // Đọc dữ liệu
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<int> primes = factorize(x);

        // Đếm số lần xuất hiện của từng số nguyên tố
        for (int p : primes) {
            if (appear[p] == 0)
                allPrimes.push_back(p);

            appear[p]++;
        }

        // Sinh mọi cặp nguyên tố
        for (int i = 0; i < (int)primes.size(); i++)
            for (int j = i + 1; j < (int)primes.size(); j++)
                allPairs.push_back({primes[i], primes[j]});
    }

    // Gom các cặp giống nhau
    sort(allPairs.begin(), allPairs.end());

    vector<PairInfo> pairInfo;

    for (int i = 0; i < (int)allPairs.size();) {
        int j = i;

        while (j < (int)allPairs.size() &&
               allPairs[j] == allPairs[i])
            j++;

        pairInfo.push_back({
            allPairs[i].first,
            allPairs[i].second,
            j - i
        });

        i = j;
    }

    int best = 0;
    int ansP = 2;
    int ansQ = 3;

    if (!allPrimes.empty()) {
        best = appear[allPrimes[0]];
        ansP = allPrimes[0];
        ansQ = (ansP == 2 ? 3 : 2);
    }

    // graph[p] chứa các q sao cho tồn tại số chia hết cho cả p và q
    vector<vector<int>> graph(MAXA + 1);

    // TH1: p và q từng cùng xuất hiện
    for (auto cur : pairInfo) {
        int p = cur.p;
        int q = cur.q;

        int value = appear[p] + appear[q] - cur.common;

        if (value > best) {
            best = value;
            ansP = p;
            ansQ = q;
        }

        graph[p].push_back(q);
        graph[q].push_back(p);
    }

    // Sắp xếp theo số lần xuất hiện giảm dần
    sort(allPrimes.begin(), allPrimes.end(),
         [&](int a, int b) {
             return appear[a] > appear[b];
         });

    int timer = 0;

    // TH2: p và q chưa từng cùng xuất hiện
    for (int i = 0; i < (int)allPrimes.size(); i++) {

        int p = allPrimes[i];

        // Cắt nhánh
        if (appear[p] + appear[allPrimes[0]] <= best)
            break;

        timer++;

        for (int q : graph[p])
            visited[q] = timer;

        for (int j = 0; j < (int)allPrimes.size(); j++) {

            int q = allPrimes[j];

            if (p == q)
                continue;

            if (visited[q] == timer)
                continue;

            int value = appear[p] + appear[q];

            if (value > best) {
                best = value;
                ansP = p;
                ansQ = q;
            }

            // q đầu tiên là tốt nhất vì đã sort giảm dần
            break;
        }
    }

    cout << "So phan tu toi da chon duoc: " << best << '\n';
    cout << "Hai so nguyen to p, q: " << ansP << ' ' << ansQ << '\n';

    return 0;
}