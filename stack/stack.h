#ifndef __STACK_H__
#define __STACK_H__

template <typename T> class stack {
private:
  int top;
  T *stackptr;
  int size;

public:
  stack(/* args */);

  bool isFull() { return top == size - 1; }
  bool isEmpty() {
    if (top == -1) {
      return true;
    }
    return false;
  }
  bool push(const T &);
  bool pop(T &);

  ~stack() { delete[] stackptr; }
  stack(int = 10);
};

#endif // __STACK_H__
