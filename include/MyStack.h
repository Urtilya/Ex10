// Copyright 2020 Urtyukov Ilya
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack {
 private:
    unsigned length;
    unsigned index;
    T *data;

 public:
    MyStack() {
        length = 0;
        index = -1;
        data = nullptr;
    }
    explicit MyStack(unsigned x) {
        data = new T[x];
        index = -1;
        length = x;
    }
    MyStack(const MyStack& my_stc) {
        unsigned x = my_stc.length;
        unsigned y = my_stc.index;
        data = new T[x];
        length = x;
        index = y;
        for (unsigned i = 0; i < x; ++i)
            data[i] = my_stc.data[i];
    }
    ~MyStack() {
        delete[] data;
    }
    bool isFull() const {
        if (index == (length-1))
          return true;
        else
          return false;
    }
    bool isEmpty() const {
        if (index == -1)
          return true;
        else
          return false;
    }
    T get() const {
        return data[index];
    }
    T pop() {
        index -= 1;
        return data[index + 1];
    }
    int push(T a) {
        index += 1;
        if (index < length) {
          data[index] = a;
          return 0;
          } else {
          return -1;
          }
    }
};

#endif  // INCLUDE_MYSTACK_H_
