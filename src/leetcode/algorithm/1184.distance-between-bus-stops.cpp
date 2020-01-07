class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
			if (start == destination) {
				return 0;
			}
			int d1 = distance[start];
			int sum = distance[start];
			bool reachDestination = false;
			int i = start + 1;
 			while (i != start) {
				if (i == distance.size()) {
					i -= distance.size();
				}
				if (i == start) {
					break;
				}
				sum += distance[i];
				if (!reachDestination) {
					if (i == destination) {
						reachDestination = true;
					} else {
						d1 += distance[i];
					}
				} else {
					if (sum >= d1 + d1) {
						return d1;
					}
				}
				++i;
			}
			return min(sum - d1, d1);
		}
};
