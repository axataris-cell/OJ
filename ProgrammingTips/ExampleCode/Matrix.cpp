using type = ll;

struct Matrix {
    vector<vector<type>> d;

    Matrix() = default;
    Matrix(int r, int c) : d(r, vector<type>(c)) {}
    Matrix(const vector<vector<type>> &_d) : d(_d) {}

    auto & operator [](int i) {return d[i];}
    const auto & operator [](int i) const {return d[i];}

    int row() const {return d.size();}
    int col() const {return d[0].size();}

    friend ostream & operator << (ostream &out, const Matrix &a) {
        for (auto x : a.d) {
            for (auto y : x) out << y << ' ';
            out << el;
        }
        return out;
    }

    static Matrix identity(ll n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        const Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int k = 0; k < a.col(); ++k)
                for (int j = 0; j < b.col(); ++j)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());

        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};