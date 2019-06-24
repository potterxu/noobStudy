#include <initializer_list>

using namespace std;

template <class T>
T average_list(initializer_list<T> li)
{
    T sum = T(0);
    for (auto i : li) {
        sum += i;
    }
    return sum / li.size();
}
