// Find solution in  https://leetcode-cn.com/problems/airplane-seat-assignment-probability/solution/shu-xue-jie-fa-by-potterxu/

double nthPersonGetsNthSeat(int n) {
    if (n == 1) {
        return 1.0;
    }
    return 0.5;
}