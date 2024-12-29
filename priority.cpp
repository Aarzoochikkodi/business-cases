import heapq

class PriorityQueue:
    def __init__(self):
        # Initialize an empty list to represent the priority queue
        self.queue = []
        self.counter = 0  # A counter to maintain order when priorities are equal

    def push(self, priority, task):
        """
        Adds a task to the priority queue with a given priority.
        The heapq library uses a min-heap, so we store the priority as negative to simulate a max-heap.
        """
        # The task is added with priority (negative for max-heap) and the counter for tie-breaking.
        heapq.heappush(self.queue, (-priority, self.counter, task))
        self.counter += 1

    def pop(self):
        """
        Removes and returns the task with the highest priority (the one with the smallest negative priority).
        """
        if self.queue:
            # Pop the task with the highest priority
            priority, counter, task = heapq.heappop(self.queue)
            return task
        else:
            return None

    def is_empty(self):
        """
        Returns True if the queue is empty, otherwise False.
        """
        return len(self.queue) == 0

    def peek(self):
        """
        Returns the task with the highest priority without removing it from the queue.
        """
        if self.queue:
            return self.queue[0][2]  # Return the task with the highest priority
        else:
            return None


# Example usage of the PriorityQueue class
def schedule_buses():
    pq = PriorityQueue()

    # Add bus routes with corresponding priorities (higher number = higher priority)
    pq.push(10, "Route A")  # High priority
    pq.push(5, "Route B")   # Medium priority
    pq.push(8, "Route C")   # Lower priority

    # Process buses based on priority
    while not pq.is_empty():
        bus_route = pq.pop()
        print(f"Dispatching bus: {bus_route}")

# Running the bus scheduling example
schedule_buses()
