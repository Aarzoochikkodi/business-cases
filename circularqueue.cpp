class CircularQueue:
    def __init__(self, size):
        """
        Initialize the Circular Queue with a given size.
        """
        self.size = size
        self.queue = [None] * size  # List to hold queue elements
        self.front = -1  # Pointer to the front of the queue
        self.rear = -1   # Pointer to the rear of the queue

    def is_empty(self):
        """
        Check if the queue is empty.
        """
        return self.front == -1

    def is_full(self):
        """
        Check if the queue is full.
        """
        return (self.rear + 1) % self.size == self.front

    def enqueue(self, item):
        """
        Add an item to the queue.
        """
        if self.is_full():
            print("Queue is full! Cannot enqueue.")
        else:
            if self.front == -1:  # Queue is empty
                self.front = 0
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = item
            print(f"Enqueued: {item}")

    def dequeue(self):
        """
        Remove and return an item from the queue.
        """
        if self.is_empty():
            print("Queue is empty! Cannot dequeue.")
            return None
        else:
            item = self.queue[self.front]
            if self.front == self.rear:  # Only one element in the queue
                self.front = self.rear = -1  # Reset the queue
            else:
                self.front = (self.front + 1) % self.size
            return item

    def peek(self):
        """
        Return the front item of the queue without removing it.
        """
        if self.is_empty():
            print("Queue is empty!")
            return None
        else:
            return self.queue[self.front]

    def display(self):
        """
        Display the elements in the queue.
        """
        if self.is_empty():
            print("Queue is empty!")
        else:
            i = self.front
            while i != self.rear:
                print(self.queue[i], end=" <- ")
                i = (i + 1) % self.size
            print(self.queue[self.rear])

# Example usage of the CircularQueue class
def bus_schedule():
    cq = CircularQueue(5)  # Create a Circular Queue of size 5

    # Enqueue buses into the queue
    cq.enqueue("Bus 1")
    cq.enqueue("Bus 2")
    cq.enqueue("Bus 3")
    cq.enqueue("Bus 4")
    cq.enqueue("Bus 5")
    
    # Display the queue
    print("Current queue:")
    cq.display()

    # Dequeue buses from the queue
    print(f"Dequeued: {cq.dequeue()}")
    print(f"Dequeued: {cq.dequeue()}")
    
    # Display the queue after dequeue
    print("Queue after dequeue:")
    cq.display()

    # Enqueue one more bus to demonstrate circular nature
    cq.enqueue("Bus 6")
    print("Queue after enqueuing Bus 6:")
    cq.display()

# Running the bus schedule example
bus_schedule()
