/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (27.09%)
 * Likes:    646
 * Dislikes: 1534
 * Total Accepted:    133.2K
 * Total Submissions: 490.3K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void prepareRow(vector<string>& words, int spaces, int start, int end, vector<string> &rv) {
        string str = "";
        if (start == end) {
            str = words[start];
            for (int i = 0; i < spaces; ++i) {
                str.push_back(' ');
            }
        } else {
            int slots = end - start;
            int spaceInEachSlot = spaces / slots;
            int slotsNeedExtraOneSpace = spaces % slots;
            while (start < end) {
                str += words[start];
                for (int i = 0; i < spaceInEachSlot; ++i) {
                    str.push_back(' ');
                }
                if (slotsNeedExtraOneSpace > 0) {
                    str.push_back(' ');
                    --slotsNeedExtraOneSpace;
                }
                ++start;
            }
            str += words[end];
        }
        rv.push_back(str);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rv;
        int rowStart = 0;
        int rowEnd = 0;
        int rowLength = words[0].size();
        for (int i = 1; i < words.size(); ++i) {
            if (rowLength + words[i].size() + 1 <= maxWidth) {
                ++rowEnd;
                rowLength += words[i].size();
                ++rowLength;
            } else {
                int spacesNeed = maxWidth-rowLength+rowEnd-rowStart;
                prepareRow(words, spacesNeed, rowStart, rowEnd, rv);
                rowStart = i;
                rowEnd = i;
                rowLength = words[i].size();
            }
        }
        string str = words[rowStart];
        for (int i = rowStart+1; i <= rowEnd; ++i){
            str.push_back(' ');
            str += words[i];
        }
        for (int i = 0; i < maxWidth - rowLength; ++i) {
            str.push_back(' ');
        }
        rv.push_back(str);
        return rv;
    }
};
// @lc code=end
