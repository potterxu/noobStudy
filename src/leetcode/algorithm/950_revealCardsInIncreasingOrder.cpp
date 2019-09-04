#include <algorithm>
#include <vector>
using namespace std;

vector<int> deckRevealedIncreasing_popLastNumToFront(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int start = deck.size() - 1;
    while (start > 1) {
        --start;
        for (int i = deck.size() - 1; i > start; --i) {
           swap(deck[i], deck[i-1]);
        }
    }
    return deck;
}

vector<int> deckRevealedIncreasing_findSpace(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    vector<int> rv(deck.size(), 0);
    int index = 0;
    for (int i : deck) {
        rv[index] = i;
        if (i == deck[deck.size() - 1]) {
            break;
        }
        bool findFirstSpace = false;
        while (true) {
            index += 1;
            if (index >= deck.size()) {
                index -= deck.size();
            }
            if (!rv[index]) {
                if (!findFirstSpace) {
                    findFirstSpace = true;
                    continue;
                }
                break;
            }
        }
    }
    return rv;
}