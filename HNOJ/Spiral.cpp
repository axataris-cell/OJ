#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Duyệt hàng trên cùng từ trái sang phải
        for (int j = left; j <= right; j++)
            cout << A[top][j] << " ";
        top++;

        // Duyệt cột phải từ trên xuống
        for (int i = top; i <= bottom; i++)
            cout << A[i][right] << " ";
        right--;

        // Duyệt hàng dưới cùng từ phải sang trái (nếu còn)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << A[bottom][j] << " ";
            bottom--;
        }

        // Duyệt cột trái từ dưới lên (nếu còn)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << A[i][left] << " ";
            left++;
        }
    }

    return 0;
}
