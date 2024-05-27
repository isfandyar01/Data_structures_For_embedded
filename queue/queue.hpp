#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

enum class queue_status { queue_no_error, queue_full, queue_empty, queue_null };

template <typename T> class queue {

private:
  int head;
  int tail;
  int base;
  T *stackptr;
  int size;

public:
  queue_status queue_push();

  queue_status queue_pop();

  queue_status queue_isFull();

  queue_status queue_isEmpty();
};

#endif // __QUEUE_HPP__
