#include <vector>
#include <algorithm>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    auto it = find_if(employees.begin(), employees.end(), [id](Employee *e){
        return e->id == id;
    });
    int rv = (*it)->importance;
    for (auto subId : (*it)->subordinates) {
        rv += getImportance(employees, subId);
    }
    return rv;
}