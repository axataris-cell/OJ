#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Person {
    ll t, a;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    vector<Person> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].t >> p[i].a;
        p[i].id = i;
    }

    // priority queue: lấy người có tầng cao nhất
    priority_queue<pair<ll,int>> pq; 
    vector<ll> ans(n);

    ll curTime = 0;   // thời điểm hiện tại của thang máy
    int i = 0;        // duyệt danh sách nhân viên

    while (i < n || !pq.empty()) {

        // Nếu thang máy rảnh và chưa có ai trong heap
        if (pq.empty()) {
            curTime = max(curTime, p[i].t);
        }

        // Đưa tất cả nhân viên đã gọi trước hoặc bằng curTime vào heap
        while (i < n && p[i].t <= curTime) {
            pq.push({p[i].a, i});
            i++;
        }

        // Lấy người ở tầng cao nhất để phục vụ chuyến này
        auto [maxFloor, idx] = pq.top();
        pq.pop();

        // Thang máy đi từ tầng 1 lên maxFloor
        ll reachTop = curTime + maxFloor - 1;

        // Gom những người có thể đón trên đường xuống
        vector<int> onboard;
        onboard.push_back(idx);

        while (true) {
            bool added = false;

            // Những người gọi trong lúc thang máy đang đi
            while (i < n && p[i].t <= reachTop) {
                pq.push({p[i].a, i});
                i++;
            }

            if (!pq.empty()) {
                auto [a2, idx2] = pq.top();
                // thời điểm thang máy đi qua tầng a2 khi đi xuống
                ll passTime = reachTop + (maxFloor - a2);

                if (p[idx2].t <= passTime) {
                    pq.pop();
                    onboard.push_back(idx2);
                    added = true;
                }
            }

            if (!added) break;
        }

        // Thời điểm xuống tầng 1
        ll finishTime = reachTop + (maxFloor - 1);

        for (int id2 : onboard) {
            ans[p[id2].id] = finishTime;
        }

        curTime = finishTime;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
