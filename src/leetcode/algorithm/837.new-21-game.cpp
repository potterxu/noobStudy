class Solution {
public:
double new21Game(int N, int K, int W) {
    if (K+W-1 <= N) {
        return 1.0;
    }
    if (K == 0) {
        return 1.0;
    }
    vector<double> a(W);
    double sum = 0.0;
    for (int i = 0; i < W; ++i) {
        if (K + i <= N) {
            a[i] = 1.0;
        } else {
            a[i] = 0.0;
        }
        sum += a[i];
    }
    int pointer = W - 1;
    for (int i = K-1; K >= 0; --i) {
        double newProb = sum / W;
        sum -= a[pointer];
        sum += newProb;
        a[pointer] = newProb;
        if (i == 0) {
            break;
        }
        --pointer;
        if (pointer < 0) {
            pointer = W - 1;
        }
    }
    return a[pointer];
}
























};