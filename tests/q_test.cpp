#include "../Queuew/queue.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("QueuePush", "[Queue]") {
  queue<int> q(5);

  REQUIRE(q.queue_push(1) == queue_status::queue_no_error);
  REQUIRE(q.queue_push(2) == queue_status::queue_no_error);
  REQUIRE(q.queue_push(3) == queue_status::queue_no_error);
  REQUIRE(q.queue_push(4) == queue_status::queue_no_error);
  REQUIRE(q.queue_push(5) == queue_status::queue_no_error);
  REQUIRE(q.queue_push(6) == queue_status::queue_full);
}

TEST_CASE("QueuePop", "[Queue]") {
  queue<int> q(5);
  int value;

  REQUIRE(q.queue_pop(value) == queue_status::queue_empty);

  q.queue_push(1);
  q.queue_push(2);

  REQUIRE(q.queue_pop(value) == queue_status::queue_no_error);
  REQUIRE(value == 1);
  REQUIRE(q.queue_pop(value) == queue_status::queue_no_error);
  REQUIRE(value == 2);
  REQUIRE(q.queue_pop(value) == queue_status::queue_empty);
}

TEST_CASE("QueueIsFull", "[Queue]") {
  queue<int> q(5);
  REQUIRE(q.queue_isFull() == queue_status::queue_no_error);

  q.queue_push(1);
  q.queue_push(2);
  q.queue_push(3);
  q.queue_push(4);
  q.queue_push(5);

  REQUIRE(q.queue_isFull() == queue_status::queue_full);
}

TEST_CASE("QueueIsEmpty", "[Queue]") {
  queue<int> q(5);
  REQUIRE(q.queue_isEmpty() == queue_status::queue_empty);

  q.queue_push(1);
  REQUIRE(q.queue_isEmpty() == queue_status::queue_no_error);

  int value;
  q.queue_pop(value);
  REQUIRE(q.queue_isEmpty() == queue_status::queue_empty);
}