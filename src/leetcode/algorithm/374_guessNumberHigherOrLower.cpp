//int guessNumber(int n) {
//    int start = 1;
//    int end = n;
//    long mid;
//    do {
//        mid = (long(start) + end) / 2;
//        int ok = guess(mid);
//        if (ok == 0) {
//            return mid;
//        } else if (ok > 0) {
//            start = mid + 1;
//        } else {
//            end = mid - 1;
//        }
//    } while (1);
//    return mid;
//}