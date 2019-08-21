// Use binary search to calculate the sqrt;
int mySqrt(int x) {
    long start = 1;
    long end = x;
    long mid = 0;
    while (start <= end) {
        mid = (end + start) / 2;
        if (mid * mid > x) {
            end = mid - 1;
        } else if ((mid + 1) * (mid + 1) < x) {
            start = mid + 1;
        } else if ((mid+1) * (mid+1) == x) {
            return mid+1;
        } else {
            return mid;
        }
    }
    return mid;
}