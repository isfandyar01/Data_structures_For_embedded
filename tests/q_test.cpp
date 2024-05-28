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