/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (63.55%)
 * Likes:    1085
 * Dislikes: 85
 * Total Accepted:    81.5K
 * Total Submissions: 126.2K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are N rooms and you start in room 0.  Each room has a distinct number
 * in 0, 1, 2, ..., N-1, and each room may have some keys to access the next
 * room. 
 * 
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 * is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j]
 * = v opens the room with number v.
 * 
 * Initially, all the rooms start locked (except for room 0). 
 * 
 * You can walk back and forth between rooms freely.
 * 
 * Return true if and only if you can enter every room.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1],[2],[3],[]]
 * Output: true
 * Explanation:  
 * We start in room 0, and pick up key 1.
 * We then go to room 1, and pick up key 2.
 * We then go to room 2, and pick up key 3.
 * We then go to room 3.  Since we were able to go to every room, we return
 * true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can't enter the room with number 2.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 * The number of keys in all rooms combined is at most 3000.
 * 
 * 
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> canOpen(rooms.size(), false);
        canOpen[0] = true;
        int roomsLocked = rooms.size() - 1;
        if (roomsLocked == 0) {
            return true;
        }
        queue<int> q;
        for (int k : rooms[0]) {
            q.push(k);
        }
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (canOpen[k]) {
                continue;
            }
            canOpen[k] = true;
            --roomsLocked;
            if (roomsLocked == 0) {
                return true;
            }
            for (int key : rooms[k]) {
                q.push(key);
            }
        }
        return false;
    }
};
