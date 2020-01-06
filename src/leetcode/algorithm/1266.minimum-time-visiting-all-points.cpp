class Solution {
public:
	int abs(int a) {
		if (a < 0) {
			a = -a;
		}
		return a;
	}

	int minDis(vector<int> &a, vector<int> &b) {
		return max(abs(a[0]-b[0]), abs(a[1]-b[1]));
	}

	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int rv = 0;
		for (int i = 0; i < points.size() - 1; ++i) {
			rv += minDis(points[i], points[i+1]);
		}
		return rv;
	}
};
