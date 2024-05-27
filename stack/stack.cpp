#include "stack.hpp"

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
