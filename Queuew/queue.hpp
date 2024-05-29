#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

enum class queue_status { queue_no_error, queue_full, queue_empty, queue_null };

template <typename T> class queue {

private:
  T *head;     // pointer to next available location
  T *tail;     // pointer to last element in buffer
  T *base;     // pointer to first element in buffer
  T *stackptr; //
  int size;    // total size of buffer
  int count;   // number of elements in buffer
public:
  queue_status queue_push(const T &);

  queue_status queue_pop(T &);

  queue_status queue_isFull();

  queue_status queue_isEmpty();

  queue(int = 10);
  ~queue() {
    std::cout << "destroyed\n";
    delete[] base;
  };
};

template <typename T> queue<T>::queue(int s) {

  size = s > 0 ? s : 10;
  base = (new T[size]);
  head = base;
  tail = base;
  count = 0;
  stackptr = base;
}

template <typename T> queue_status queue<T>::queue_push(const T &pushvalue) {

  if (!base || !head || !tail) {

    return queue_status::queue_null;
  }
  if (queue_isFull() == queue_status::queue_full) {

    return queue_status::queue_full;
  } else {
    *head = pushvalue;
    count++;
  }

  if (head == base + size - 1) {
    head = base;
  } else {
    head++;
  }
  return queue_status::queue_no_error;
};
template <typename T> queue_status queue<T>::queue_pop(T &value) {

  if (!base || !head || !tail) {
    return queue_status::queue_null;
  }

  if (queue_status::queue_empty == queue_isEmpty()) {
    return queue_status::queue_empty;
  } else {
    value = *tail;
    count--;
  }
  if (tail == base + size - 1) {
    tail = base;
  } else {
    tail++;
  }
  return queue_status::queue_no_error;
};

template <typename T> queue_status queue<T>::queue_isFull() {

  if (!base || !head || !tail) {
    return queue_status::queue_null;
  } else if (count >= size) {
    return queue_status::queue_full;
  }
  return queue_status::queue_no_error;
};

template <typename T> queue_status queue<T>::queue_isEmpty() {

  return (count == 0) ? queue_status::queue_empty
                      : queue_status::queue_no_error;
};

#endif // __QUEUE_H__