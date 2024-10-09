#include <iostream>

template <typename T>
class stack {

    T* m_data = nullptr;
    size_t cd_capacity;             // size of container
    size_t m_length;                // length of container

public:

    stack () { m_length = 0; cd_capacity =0;} = default;

    void push(T push_with ) {

        size_t pw_size = sizeof(push_with);

        if (pw_size > sizeof(m_data)) m_alloc();         // alloc size of pw_with size

        m_length = m_length + 1;
    }

    void m_alloc (size_t n_size) {                  // get size in terms bytes

        cd_data = new T [1];

        cd_data =  new[T];

        memcpy();


        memcpy(*m_data,cd_data,(sizeof(T) * ))


    }

    const T pop () {

        return m_data[i];
        delete m_data[i];
    }

};