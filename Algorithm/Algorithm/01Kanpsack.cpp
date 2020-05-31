#include<vector>
#include<algorithm>

using namespace std;

int n, W;
vector<vector<int>>DP;
vector<int> p;
vector<int> w;

/////Recursive solution//////
/*int maxValue( int i , int j) {
	if (j == 0||(i == 1 && w[1] > j)) return 0;
	else if (i == 1 && w[1] <= j) return p[1];
	if (w[i] > j) DP[i][j] = maxValue(i - 1, j);
	else DP[i][j] = max(maxValue(i - 1, j), maxValue(i - 1, j - w[i]) + p[i]);
	return DP[i][j];
}*/

int main() {

	;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &w[i], &p[i]);
	}
	for (int i = w[1]; i <= W; i++) {
		DP[1][i] = p[1];
	}
	int j = W;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (w[i] > j) DP[i][j] = DP[i - 1][j];
			else DP[i][j] = max(DP[i - 1][j], p[i] + DP[i - 1][j - w[i]]);
		}
	}
	printf("%d", DP[n][W]);
}