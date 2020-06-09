#ifndef KIEMTHU_STACK_H
#define KIEMTHU_STACK_H
#include <vector>
#include <cassert>

template<typename T>
class Stack {
private:
    std::vector<T> elems;
    using size_type = typename std::vector<T>::size_type;
    size_type siz;
public:
    void push(T const& elem);
    void pop();
    T const& top() const;
    bool empty() const {
        return elems.empty();
    }
    size_type size() {
        return elems.size();
    }

};

template<typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
    ++siz;
}

template<typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
    --siz;
}

template<typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}

#endif //KIEMTHU_STACK_H
