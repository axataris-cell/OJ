// Author: Axataris
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Giả định ban đầu tất cả các đỉnh đều màu Trắng (0)
    vector<int> color(N, 0);

    long long B = 0;       // Tổng đỉnh đen
    long long B0 = 0;      // Đỉnh đen ở vị trí chẵn
    long long B1 = 0;      // Đỉnh đen ở vị trí lẻ
    long long O = 0;       // Số cặp đen đối diện (chỉ dùng khi N chẵn)

    long long E_mono = 0;  // Số tam giác đều đơn sắc
    vector<int> eq_black_count;

    if (N % 3 == 0) {
        eq_black_count.assign(N / 3, 0);
        // Ban đầu tất cả màu trắng nên toàn bộ N/3 tam giác đều là đơn sắc
        E_mono = N / 3; 
    }

    // Hàm O(1) tính kết quả
    auto get_ans = [&]() -> long long {
        long long T_mono_ab = 0;
        if (N % 2 != 0) {
            T_mono_ab = (1LL * N * (N - 1) / 2) - 
                        3LL * ((N - 1) / 2) * B + 
                        3LL * B * (B - 1) / 2;
        } else {
            T_mono_ab = (1LL * N * (N - 2) / 2) - 
                        3LL * ((N - 2) / 2) * B + 
                        2LL * B * B - 2LL * B - 2LL * B0 * B1 - 2LL * O;
        }
        
        long long ans = T_mono_ab;
        if (N % 3 == 0) {
            ans -= 2LL * E_mono;
        }
        return ans;
    };

    // Xử lý các thao tác lật màu
    for (int i = 0; i < M; ++i) {
        int u;
        cin >> u;
        u--; // Đổi về 0-indexed

        // 1. Cập nhật tam giác đều (nếu có)
        if (N % 3 == 0) {
            int eq_idx = u % (N / 3);
            if (eq_black_count[eq_idx] == 0 || eq_black_count[eq_idx] == 3) E_mono--;
            
            if (color[u] == 0) eq_black_count[eq_idx]++;
            else eq_black_count[eq_idx]--;
            
            if (eq_black_count[eq_idx] == 0 || eq_black_count[eq_idx] == 3) E_mono++;
        }

        // 2. Cập nhật các biến trạng thái Black
        if (color[u] == 0) {
            // Lật từ Trắng -> Đen
            B++;
            if (N % 2 == 0) {
                if (u % 2 == 0) B0++;
                else B1++;
                int v = (u + N / 2) % N;
                if (color[v] == 1) O++; // Nếu đối đỉnh cũng đang Đen -> tạo thành 1 cặp O
            }
            color[u] = 1;
        } else {
            // Lật từ Đen -> Trắng
            B--;
            if (N % 2 == 0) {
                if (u % 2 == 0) B0--;
                else B1--;
                int v = (u + N / 2) % N;
                if (color[v] == 1) O--; // Phá vỡ 1 cặp đối đỉnh Đen
            }
            color[u] = 0;
        }

        // In kết quả sau mỗi thao tác
        cout << get_ans() << "\n";
    }

    return 0;
}