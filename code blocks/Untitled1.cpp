#include <iostream>
using namespace std;

const int H = 48;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {

		int C[H+1][H+1];
		for (int S = 0; S <= H; ++S) {
			for (int E = 0; E <= H; ++E) {
				C[S][E] = 0;
			}
		}

		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int Si, Ei, Ci;
			cin >> Si >> Ei >> Ci;
			C[Si][Ei] = max(C[Si][Ei], Ci);
		}

		int MaxC[H+1];
		MaxC[0] = 0;
		for (int E = 1; E <= H; ++E) {
			MaxC[E] = 0;
			for (int S = 0; S < E; ++S) {
				MaxC[E] = max(MaxC[E], MaxC[S] + C[S][E]);
			}
		}
		cout << MaxC[H] << endl;
	}
	return 0;
}