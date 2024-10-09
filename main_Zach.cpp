#include <vector>


using namespace std;

class stack {
private:
    vector<int> v;
    
public:
    int pop();
    void push(int element);
    stack(vector<int> _v);
};

stack::stack(vector<int> _v) {
    v = _v;
}

int stack::pop() {
    
    int i = v.at(v.size()-1);
    v.pop_back();
    
    return i;
}

void stack::push(int element) {
    v.push_back(element);
}



int main() {
    stack v1({1,2,3});
    cout << v1.pop();
    
    return 0;
}
