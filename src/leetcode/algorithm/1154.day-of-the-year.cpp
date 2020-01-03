class Solution {
public:
    int stringToInt(string &date, int start, int end) {
        int rv = 0;
        for (int i = start; i < end; ++i) {
            rv *= 10;
            rv += date[i] - '0';
        }
        return rv;
    }
    int dayOfYear(string date) {
        static int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int year = stringToInt(date, 0, 4);
        int month = stringToInt(date, 5, 7);
        int day = stringToInt(date, 8, 10);
        int rv = 0;
        for (int i = 0; i < month - 1; ++i) {
            rv += dayOfMonth[i];
        }
        if (month > 2) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    ++rv;
                }
            } else if (year % 4 == 0) {
                ++rv;
            }
        }
        return rv + day;
    }
};
