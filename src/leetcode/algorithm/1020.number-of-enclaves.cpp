class Solution {
public:
	void dfs(vector<vector<int>>& A, int i, int j) {
		// -1 means a land that can finally walk off the boundary
		if (A[i][j] == 0 || A[i][j] == -1) {
			return;
		}
		A[i][j] = -1;
		if (i > 0) {
			dfs(A, i-1, j);
		}
		if (j > 0) {
			dfs(A, i, j-1);
		}
		if (i < A.size()-1) {
			dfs(A, i+1, j);
		}
		if (j < A[0].size()-1) {
			dfs(A, i, j+1);
		}
	}

	int numEnclaves(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); ++i) {
			if (A[i][0] == 1) {
				dfs(A, i, 0);
			}
			if (A[i][A[0].size()-1] == 1) {
				dfs(A, i, A[0].size()-1);
			}
		}
		for (int i = 0; i < A[0].size(); ++i) {
			if (A[0][i] == 1) {
				dfs(A, 0, i);
			}
			if (A[A.size()-1][i] == 1) {
				dfs(A, A.size()-1, i);
			}
		}
		int rv = 0;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A[0].size(); ++j) {
				if (A[i][j] == 1) {
					++rv;
				}
			}
		}
		return rv;
	}
};
