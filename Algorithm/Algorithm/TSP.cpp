#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N; //number of cities
int W[17][17]; //weights of each route between cities
int DP[17][1 << 16]; //A is set of cities that have not visited. DP[i][A] is minimum sum of weights when visit cities in A only once.
					 // A is represented with bit-mask => 1: via, 0: non-via
int TSP(int i, int visited) {
	if (DP[i][visited] != 0) return DP[i][visited]; //if a value was already fixed, return the value. 
	if (visited == (1 << N) - 1) {  // (1<<N)-1 mean that we pass through all cities. 
		if (W[i][1] != 0) return W[i][1]; // if the last visited city has a route to the starting city, return weight for two cities
		return 99999999; // otherwise return infinity
	}
	int minimum = 99999999;
	for (int j = 2; j <= N; j++) {
		if ((visited & 1 << (j - 1)) || (W[i][j] == 0)) continue; //currently if we visit jth city or no route for ith city to jth city , don't do any operation. 

		int a = TSP(j, (visited | (1 << (j - 1)))) + W[i][j];
		if (minimum > a) minimum = a;

	}
	DP[i][visited] = minimum;
	return DP[i][visited];

}

int main() {

	scanf("%d", &N);



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	printf("%d", TSP(1, 1));


}