#include "queue.hpp"

template <typename T> queue<T>::queue(int s) {

  size = s > 0 ? s : 10;
  base = (new T[size]);
  head = base;
  tail = base;
  count = 0;
}

template <typename T> queue_status queue<T>::queue_push(const T &pushvalue) {

  if (queue_no_error == queue_isFull) {
    return queue_full;
  }

  *head = pushvalue;
  count++;

  if (head == base + size - 1) {
    head = base;
    return queue_no_error;
  } else {
    head++;
  }
  return queue_no_error;
};
template <typename T> queue_status queue<T>::queue_pop(T &value) {

  if (!base || !head || !tail) {
    return queue_null;
  }

  if (queue_empty == queue_isEmpty()) {
    return queue_empty;
  } else {
    value = *tail;
    count--;
  }
  if (tail == base + size - 1) {
    tail = base;
  } else {
    tail++;
  }
  return queue_no_error;
};

template <typename T> queue_status queue<T>::queue_isFull() {

  if (!base || !head || !tail) {
    return queue_null;
  } else if (count >= size) {
    return queue_full;
  }
  return queue_no_error;
};

template <typename T> queue_status queue<T>::queue_isEmpty() {

  return (count == 0) ? queue_empty : queue_no_error;
};
