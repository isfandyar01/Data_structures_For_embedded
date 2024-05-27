# Circular Buffer

A Circular Buffer, also known as a Ring Buffer, is a fixed-size buffer that stores data in a circular
fashion. When the buffer is full, new data overwrites the oldest data in the buffer. This makes the
Circular Buffer a great choice for applications where the most recent data is the most important. For
example, in a real-time system, the Circular Buffer can be used to store sensor data, and the latest
data will always be available.

# FIFO
    
A FIFO (First-In-First-Out) is a buffer that allows for the first data item to be inserted to be the first
one to be removed. This data structure is commonly used in applications where data needs to be
stored in a specific order. For example, in a printing system, the FIFO can be used to store the print
jobs in the order in which they are received, so that they are printed in the correct order.

# Queue

Queue is an abstract data structure, somewhat similar to Stack. In contrast to Queue, queue is opened
at both end. One end is always used to insert data (enqueue) and the other is used to remove data
(dequeue). Queue follows First-In-First-Out methodology, i.e., the data item stored first will be
accessed first.


