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

template <typename T> stack<T>::stack(int s) {
  top = -1;
  size = s > 0 ? s : 10;
  stackptr = (new T[size]);
}

template <typename T> bool stack<T>::push(const T &pushvalue) {

  if (!isFull()) {
    stackptr[++top] = pushvalue;
    return true;
  }
  return false;
}

template <typename T> bool stack<T>::pop(T &value) {
  if (!isEmpty()) {
    value = stackptr[top--];
    return true;
  }
  return false;
}

#endif // __STACK_H__
