class myQueue {
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    myQueue(int n) {
        capacity = n;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    void enqueue(int x) {
        if (!isFull()) {
            rearIndex = (rearIndex + 1) % capacity;
            arr[rearIndex] = x;
            currentSize++;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex = (frontIndex + 1) % capacity;
            currentSize--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[frontIndex];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rearIndex];
    }
};
