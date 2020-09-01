# Round-Robin-Scheduling-Algorithm

The Round Robin Scheduling Algorithm is designed especially for the time sharing systems. A small unit of time called a time
quantum is defined. A time quantum is generally from ten to hundred milliseconds. The ready queue is treated as a circular queue.
The CPU scheduler goes around the ready queue, allocating the CPU to each process for a time interval of up to one time quantum.

To implement the round robin scheduling, we keep the ready queue as a FIFO queue of the processes. New processes are added to
the tail of the ready queue. The CPU scheduler picks the first process from the ready queue, sets a timer to interrupt after one time
quantum in a row.
