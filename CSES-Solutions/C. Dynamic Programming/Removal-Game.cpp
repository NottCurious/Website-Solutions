#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e3;

int n, x[mxN + 1];
ll p[mxN + 1], dp[mxN + 1][mxN + 1];

ll sum(int l, int r){
	return p[r] - p[l - 1];
}

ll solve(int l, int r){
	if(dp[l][r])	return dp[l][r];
	if(l == r)		return x[l];
	return dp[l][r] = max(x[l] + sum(l + 1, r) - solve(l + 1, r), x[r] + sum(l,r - 1) - solve(l, r - 1));
}

int main(){
  cin >> n;
	for(int i = 1; i <= n; i++){
    cin >> x[i];
		p[i] = p[i - 1] + x[i];
	}
  cout << solve(1, n);
}
