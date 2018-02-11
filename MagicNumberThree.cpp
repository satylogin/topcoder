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

class MagicNumberThree {
	public:

	int dp[100][10][2];

	int get(string s, int i, int m, int f) {
		if (i == s.size()) {
			return (m == 0 && f == 1);
		}
		if (dp[i][m][f] != -1) return dp[i][m][f];
		int ret = 0;
		ret = get(s, i+1, m, f);
		ret += get(s, i+1, (m + s[i] - '0') % 3, 1);
		ret %= MOD;
		return dp[i][m][f] = ret;
	}

	int countSubsequences(string s) {
		memset(dp, -1, sizeof(dp));
		return get(s, 0, 0, 0);
	}
};
