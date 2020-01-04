class Solution {
public:
	double new21Game(int N, int K, int W) {
		if (N-K >= W) {
			return 1;
		}
		auto m = vector<double>(K+W, 0.0); // The probability to win if we already get x points
		for (int i = K; i <= N; ++i) {
			m[i] = 1.0;
		}
		double s = N-K+1;
		for (int i = K - 1; i >= 0; --i) {
			m[i] = s/W;
			s += m[i] - m[i+W];
		}
		return m[0];
	}
};
