class Solution {
public:
    bool isLeapYear(int year) {
        if (year % 400 == 0) {
            return true;
        } else if (year % 100 == 0) {
            return false;
        } else if (year % 4 == 0) {
            return true;
        }
        return false;
    }
    string dayOfTheWeek(int day, int month, int year)
    {
        int daysFromStart = -1;
        for (int y = 1971; y < year; ++y) {
            daysFromStart += 365;
            if (isLeapYear(y)) {
                ++daysFromStart;
            }
        }
        static int dOm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        for (int m = 0; m < month - 1; ++m) {
            daysFromStart += dOm[m];
        }
        if (month > 2) {
            if (isLeapYear(year)) {
                ++daysFromStart;
            }
        }
        daysFromStart += day;
        static string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return week[(daysFromStart + 5) % 7];
    }
};
