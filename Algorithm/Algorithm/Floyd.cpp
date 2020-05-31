#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; // number of cities
	cin >> m; // number of routes
	vector<vector<int>> D(n + 1, vector<int>(n + 1, 10000001)); // D[i][j] is a minimum cost routes from i to j, 10000001 is infinity(no routes)
	for (int k = 0; k < m; k++) {
		int i, j, cost;
		cin >> i >> j >> cost; // input for the start node i and destination node j , cost is a weight
		if (D[i][j] > cost) D[i][j] = cost;  // updating to low cost for overlaping route
	}
	for (int i = 1; i <= n; i++) {
		D[i][i] = 0; // If the start node and destination node are the same, reset to 0
	}
	for (int k = 1; k <= n; k++) { // via k node
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (k == i) break;
				if (k != j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);// updating to min of the via k node and non-via k node 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (D[i][j] == 10000001) cout << 0 << " ";
			else cout << D[i][j] << " ";
		}
		cout << "\n";
	}

}