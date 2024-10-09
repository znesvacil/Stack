#include <iostream>

template <typename T>
class dynamic_container {

    T* m_data = nullptr;

    size_t m_length;                                // length of used

    size_t m_capacity;                              // length of capacity


    void m_alloc (T to_append_with) {                   // alloc memory

        m_capacity = m_length+1;

        T* block_mem = (T*)::operator new (m_capacity* sizeof(T));     // overload new, allocate contiguous memory

        for (size_t i = 0; i < m_length; i++)  {block_mem[i] = std::move(m_data[i]);}      // increment container size

        block_mem[m_capacity] = to_append_with;                           // assign element

        m_data = block_mem;
    }

    void d_alloc (size_t length) {

        for (size_t i = 0; i < length; i++)  {m_data[m_length-i].~T();}       // for deleting container

        T::operator delete (m_length, m_capacity * sizeof(T));            // delete operator overload

        delete[] m_data;                                               // index deleting
    }



public:

    dynamic_container () {m_length = 0; m_capacity =0;}

    T operator[] (size_t index) {return m_data[index % m_length];}

    void append (T element) {                                             // append with element

        if (m_capacity < m_length +1) m_alloc(element);

        m_length++;
        m_capacity++;
    }

    const T pop_back () {

        d_alloc(1);

        return m_data[m_length];
    }

    const T peek () {

        return m_data[m_length];
    }



};

int main () {

    dynamic_container<int> temp;

    temp.append(5);

    std::cout << temp.peek();

    std::cout << temp.pop_back();


}