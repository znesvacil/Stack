#include <vector>
#include "main_alex.hpp"


class stack {
private:
    std::vector<int> v;
    
public:

    stack() = default;

    stack(std::vector<int> _v) {
        v = _v;
    }

    int pop() {

        int i = v.at(v.size()-1);
        v.pop_back();

        return i;
    }

    void push(int element) {
        v.push_back(element);
    }


};


int main() {
    stack v1({1,2,3});
    std::cout << v1.pop();

    auto stack1 = new stack;

    stack1->push();
    std::cout << stack1->pop();

    
    return 0;
}
