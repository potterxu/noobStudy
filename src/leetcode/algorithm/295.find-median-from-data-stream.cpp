/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (43.02%)
 * Likes:    2852
 * Dislikes: 54
 * Total Accepted:    218.5K
 * Total Submissions: 490.7K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (!minQ.empty() && num > minQ.top()) {
            minQ.push(num);
        } else {
            maxQ.push(num);
        }
        if (maxQ.size() > minQ.size() + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
        } else if (maxQ.size() < minQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
        // printf("%d, %d\n", maxQ.size(), minQ.size());
    }
    
    double findMedian() {
        if (minQ.size() != maxQ.size()) {
            return maxQ.top();
        }
        return maxQ.top() + (minQ.top() - maxQ.top()) / 2.0;
    }

    priority_queue<int, vector<int>, less<int>> maxQ; // fisrt half numbers
    priority_queue<int, vector<int>, greater<int>> minQ; // second half numbers
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
