#include <stdio.h>
#include <unordered_map>

using namespace std;

#define MOD 1000000007
#define NMAX 131072

struct IntervalInfo {
	int sfib, sfibm1, sfibp1;
	int l, r;
};

struct IntervalInfo segtree[2 * NMAX];

void CombineIntervalInfo(const struct IntervalInfo& left, const struct IntervalInfo& right, struct IntervalInfo* combined) {
	// F(left+right)=F(left)*F(right+1)+F(left-1)*F(right)
	// F(left+right-1)=F(left)*F(right)+F(left-1)*F(right-1)
	// F(left+1+right)=F(left+1)*F(right+1)+F(left)*F(right)
	combined->sfib = ((long long) left.sfib * (long long) right.sfibp1 + (long long) left.sfibm1 * (long long) right.sfib) % MOD;
	combined->sfibm1 = ((long long) left.sfib * (long long) right.sfib + (long long) left.sfibm1 * (long long) right.sfibm1) % MOD;
	combined->sfibp1 = ((long long) left.sfibp1 * (long long) right.sfibp1 + (long long) left.sfib * (long long) right.sfib) % MOD;
	combined->sfib = ((long long) combined->sfib + (long long) left.sfib + (long long) right.sfib) % MOD;
	combined->sfibm1 = ((long long) combined->sfibm1 + (long long) left.sfibm1 + (long long) right.sfibm1) % MOD;
	combined->sfibp1 = ((long long) combined->sfibp1 + (long long) left.sfibp1 + (long long) right.sfibp1) % MOD;
}

unordered_map<int, int> fibo_cache;
unordered_map<int, int>::const_iterator fibo_cache_it;

int Fibo(int n) {
	if (n <= 0) return 0;
	if (n <= 2) return 1;
	fibo_cache_it = fibo_cache.find(n);
	if (fibo_cache_it != fibo_cache.end()) return fibo_cache_it->second;
	int f, right, left;
	right = (n >> 1); left = n - right;
	f = ((long long) Fibo(left) * (long long) Fibo(right + 1) + (long long) Fibo(left - 1) * (long long) Fibo(right)) % MOD;
	return fibo_cache[n] = f;
}

int A[NMAX];
int M, N;

void ReadInput() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = N; i < NMAX; i++) A[i] = 0;
}

void InitSegTree() {
	for (int i = 0; i < N; i++) {
		segtree[NMAX + i].sfib = Fibo(A[i]);
		segtree[NMAX + i].sfibm1 = Fibo(A[i] - 1);
		segtree[NMAX + i].sfibp1 = Fibo(A[i] + 1);
		segtree[NMAX + i].l = segtree[NMAX + i].r = i + 1;
	}
	for (int i = N; i < NMAX; i++) {
		segtree[NMAX + i].sfib = segtree[NMAX + i].sfibm1 = segtree[NMAX + i].sfibp1 = 0;
		segtree[NMAX + i].l = segtree[NMAX + i].r = i + 1;
	}
	for (int i = NMAX - 1; i >= 1; i--) {
		int left = i << 1;
		int right = left + 1;
		segtree[i].l = segtree[left].l;
		segtree[i].r = segtree[right].r;
		CombineIntervalInfo(segtree[left], segtree[right], &segtree[i]);
	}
}

void UpdateSegTree(int X, int Y) {
	X += NMAX - 1;
	segtree[X].sfib = Fibo(Y);
	segtree[X].sfibm1 = Fibo(Y - 1);
	segtree[X].sfibp1 = Fibo(Y + 1);
	X >>= 1;
	while (X >= 1) {
		int left = X << 1;
		int right = left + 1;
		CombineIntervalInfo(segtree[left], segtree[right], &segtree[X]);
		X >>= 1;
	}
}

struct IntervalInfo QANS, QTMP;
int QA, QB;

void QuerySegTree(int node) {
	if (QA <= segtree[node].l && segtree[node].r <= QB) {
		CombineIntervalInfo(QANS, segtree[node], &QTMP);
		QANS.sfib = QTMP.sfib;
		QANS.sfibm1 = QTMP.sfibm1;
		QANS.sfibp1 = QTMP.sfibp1;
		return;
	}
	int left = node << 1;
	int right = left + 1;
	if (QA <= segtree[left].r) QuerySegTree(left);
	if (QB >= segtree[right].l) QuerySegTree(right);
}

void ProcessOps() {
	char ch;
	while (M--) {
		scanf(" %c", &ch);
		if (ch == 'Q') {
			scanf("%d %d", &QA, &QB);
			QANS.sfib = QANS.sfibm1 = QANS.sfibp1 = 0;
			QuerySegTree(1);
			printf("%d\n", QANS.sfib);
		} else {
			int X, Y;
			scanf("%d %d", &X, &Y);
			UpdateSegTree(X, Y);
		}
	}
}

int main() {
	ReadInput();
	InitSegTree();
	ProcessOps();
	return 0;
}

