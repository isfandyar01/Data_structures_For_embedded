#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

enum queue_status { queue_no_error, queue_full, queue_empty, queue_null };

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
  ~queue() { delete[] stackptr; };
};

#endif // __QUEUE_HPP__
