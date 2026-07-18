const int B = ... // N / sqrt(Q) + 100 / 200

struct Query {
    int l, r;
    int id;
};

sort(all(queries), [](const &Query x, const &Query y) {
    if (x.l / B != y.l / B) {
        return x.l / B < y.l / B;
    }

    return x.r < y.r;
});

// Hilbert Heuristic for Mos

sort(all(queries), [](const &Query x, const &Query y) {
    int a = x.l / B;
    int b = y.l / B;
    if (a != b) {
        return a < b;
    }

    if (a & 1) return x.r < y.r;
    return x.r > y.r;
});

// Hilbert Curve for Mos
struct Query {
    int l, r;
    int id;
    int64_t ord;
};

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int pw = 0;
while ((1 << pw) <= n) ++pw;

queries.push_back({l, r, i, hilbertOrder(l, r, pw, 0)});

sort(all(queries), [](const &Query x, const &Query y) {
    return x.ord < y.ord;
});