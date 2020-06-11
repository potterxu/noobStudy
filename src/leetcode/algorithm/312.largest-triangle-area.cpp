class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double rv = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    auto &a = points[i];
                    auto &b = points[j];
                    auto &c = points[k];
                    if ((b[1] - a[1]) * (c[0] - b[0]) == (b[0] - a[0]) * (c[1] - b[1])) {
                        continue;
                    }
                    double ab = sqrt(pow(a[1]-b[1], 2)+pow(a[0]-b[0], 2));
                    double ac = sqrt(pow(a[1]-c[1], 2)+pow(a[0]-c[0], 2));
                    double bc = sqrt(pow(c[1]-b[1], 2)+pow(c[0]-b[0], 2));
                    double p = (ab + ac + bc) / 2;
                    double size = sqrt(p * (p-ab) * (p-ac) * (p-bc));
                    rv = max(rv, size);
                }
            }
        }
        return rv;
    }
};
