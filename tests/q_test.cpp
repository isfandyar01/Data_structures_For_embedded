#include "../Queuew/queue.hpp"
#include <gtest/gtest.h>

TEST(QueueTest, QueuePush) {
  queue<int> q(5);

  EXPECT_EQ(queue_status::queue_no_error, q.queue_push(1));
  EXPECT_EQ(queue_status::queue_no_error, q.queue_push(2));
  EXPECT_EQ(queue_status::queue_no_error, q.queue_push(3));
  EXPECT_EQ(queue_status::queue_no_error, q.queue_push(4));
  EXPECT_EQ(queue_status::queue_no_error, q.queue_push(5));
  EXPECT_EQ(queue_status::queue_full, q.queue_push(6));
}

TEST(QueueTest, QueuePop) {
  queue<int> q(5);
  int value;

  EXPECT_EQ(queue_status::queue_empty, q.queue_pop(value));

  q.queue_push(1);
  q.queue_push(2);

  EXPECT_EQ(queue_status::queue_no_error, q.queue_pop(value));
  EXPECT_EQ(1, value);
  EXPECT_EQ(queue_status::queue_no_error, q.queue_pop(value));
  EXPECT_EQ(2, value);
  EXPECT_EQ(queue_status::queue_empty, q.queue_pop(value));
}

TEST(QueueTest, QueueIsFull) {
  queue<int> q(5);
  EXPECT_EQ(queue_status::queue_no_error, q.queue_isFull());

  q.queue_push(1);
  q.queue_push(2);
  q.queue_push(3);
  q.queue_push(4);
  q.queue_push(5);

  EXPECT_EQ(queue_status::queue_full, q.queue_isFull());
}

TEST(QueueTest, QueueIsEmpty) {
  queue<int> q(5);
  EXPECT_EQ(queue_status::queue_empty, q.queue_isEmpty());

  q.queue_push(1);
  EXPECT_EQ(queue_status::queue_no_error, q.queue_isEmpty());

  int value;
  q.queue_pop(value);
  EXPECT_EQ(queue_status::queue_empty, q.queue_isEmpty());
}