/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {

        Employee* cur = nullptr;

        for (int i = 0 ; i < employees.size() ; i++){
            if (employees[i]->id == id){
                cur = employees[i];
                break;
            }
        }

        if (cur == nullptr){
            throw runtime_error("Id cannot be found");
        }

        int total = cur->importance;

        if (!cur->subordinates.empty()){
            for (int i = 0 ; i < cur->subordinates.size() ; i++){
                total += getImportance(employees , cur->subordinates[i]);
            }
        }

        return total;
        
    }
};