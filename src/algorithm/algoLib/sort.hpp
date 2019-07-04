#include <vector>

namespace pxu {
void selectionSort(std::vector<int> &vec);

/*
 * Compare two nearby elements and move the smaller one to the fron, starting
 * from the end of the vector
 */
void bubbleSort(std::vector<int> &vec);

/*
 * Starting from the second element, insert it into proper location in the sub
 * vector before it
 */
void insertSort(std::vector<int> &vec);
}