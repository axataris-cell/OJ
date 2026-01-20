vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        // Nếu i nằm trong đoạn đang trùng
        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);

        // Mở rộng chuỗi thêm nếu có thể
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        // Nếu mở rộng xa hơn, cập nhật L, R
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}
