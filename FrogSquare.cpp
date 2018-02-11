#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

class FrogSquare {
	public:
		 int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
			if (sx == tx && sy == ty) return 0;
			int tmp = (sx - tx) * (sx - tx) + (sy - ty) * (sy - ty);
			if (tmp >= d*d) return 1;
			queue <pair<pii, int> > q;
			int M[20000];
			memset(M, -1, sizeof(M));
			vector<pii > v;
			v.pb(mkp(sx, sy));
			for (int i = 0; i < n; ++i) v.pb(mkp(0, i)), v.pb(mkp(n-1, i)), v.pb(mkp(i, 0)), v.pb(mkp(i, n-1));
			v.pb(mkp(tx, ty));
			
			q.push(mkp(mkp(sx, sy), 0));
			M[0] = 0;
			while (!q.empty()) {
				int x = q.front().fi.fi;
				int y = q.front().fi.sc;
				int tmp = q.front().sc;
				q.pop();
				for (int i = 0; i < v.size(); ++i) {
					if (M[i] != -1) continue;
					int a = v[i].fi;
					int b = v[i].sc;
					int dist = (x - a) * (x - a) + (y - b) * (y - b);
					if (dist >= d*d) {
						M[i] = tmp + 1;
						q.push(mkp(mkp(a, b), M[i]));
					}
				}
			}
			
			return M[v.size()-1];
		 }
};
