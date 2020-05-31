/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 *
 * https://leetcode.com/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (47.77%)
 * Total Accepted:    18.7K
 * Total Submissions: 39.1K
 * Testcase Example:  '"H2O"'
 *
 * Given a chemical formula (given as a string), return the count of each
 * atom.
 * 
 * An atomic element always starts with an uppercase character, then zero or
 * more lowercase letters, representing the name.
 * 
 * 1 or more digits representing the count of that element may follow if the
 * count is greater than 1.  If the count is 1, no digits will follow.  For
 * example, H2O and H2O2 are possible, but H1O2 is impossible.
 * 
 * Two formulas concatenated together produce another formula.  For example,
 * H2O2He3Mg4 is also a formula.  
 * 
 * A formula placed in parentheses, and a count (optionally added) is also a
 * formula.  For example, (H2O2) and (H2O2)3 are formulas.
 * 
 * Given a formula, output the count of all elements as a string in the
 * following form: the first name (in sorted order), followed by its count (if
 * that count is more than 1), followed by the second name (in sorted order),
 * followed by its count (if that count is more than 1), and so on.
 * 
 * Example 1:
 * 
 * Input: 
 * formula = "H2O"
 * Output: "H2O"
 * Explanation: 
 * The count of elements are {'H': 2, 'O': 1}.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * formula = "Mg(OH)2"
 * Output: "H2MgO2"
 * Explanation: 
 * The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 
 * formula = "K4(ON(SO3)2)2"
 * Output: "K4N2O14S4"
 * Explanation: 
 * The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 * 
 * 
 * 
 * Note:
 * All atom names consist of lowercase letters, except for the first character
 * which is uppercase.
 * The length of formula will be in the range [1, 1000].
 * formula will only consist of letters, digits, and round parentheses, and is
 * a valid formula as defined in the problem.
 * 
 */
class Solution {
public:
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }
    void addCountToMap(string &name, string &count, map<string, int> &m) {
        int num = 1;
        if (!count.empty()) {
            num = stoi(count);
        }
        if (!name.empty()) {
            m[name] += num;
        }
        name = "";
        count = "";
    }
    void process(string &formula, int &index, map<string,int> &m) {
        map<string, int> innerM;
        
        string name = "";
        string count = "";
        while (index < formula.size()) {
            char c = formula[index];
            if (c == ')') {
                addCountToMap(name, count, m);
                break;
            } else if (c == '(') {
                ++index;
                process(formula, index, innerM);
                for (auto &p : innerM){
                    m[p.first] += p.second;
                }
                innerM.clear();
                continue;
            } else if (isNumber(c)) {
                count.push_back(c);
            } else if (isUpper(c)) {
                if (!name.empty()) {
                    addCountToMap(name, count, m);
                }
                name.push_back(c);
            } else {
                name.push_back(c);
            }
            ++index;
        }
        addCountToMap(name, count, m);
        ++index;
        while (index < formula.size() && isNumber(formula[index])) {
            count.push_back(formula[index]);
            ++index;
        }
        if (!count.empty()) {
            int times = stoi(count);
            for (auto &p : m) {
                p.second *= times;
            }
        }
    }
    string countOfAtoms(string formula) {
        
        map<string,int> m;
        int i = 0;
        process(formula, i, m);
        string rv = "";
        for (auto &p : m) {
            rv += p.first;
            if (p.second > 1) {
                rv += to_string(p.second);
            }
        }
        return rv;
    }
};
