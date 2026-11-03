class MyCircularQueue {
    vector<int> buffer;
    int head = 0; // this is for the dequee pos
    int tail = 0; // this is for the enqueue
    int count = 0;
    int N;
    
public:
    MyCircularQueue(int k): buffer(k, -1){
        N = k;
    }
    
    bool enQueue(int value) {
        int index = tail % N; // this will give us the index of our next enque 
        if (count == N  || buffer[index] != -1){
            // we cant enqueue if the buffer is full 
           return false;
        }
        count++;
        buffer[index] =value;
        tail++;
        return true;
        
    }
    
    bool deQueue() {
        int index = head % N;

        if (count == 0 || buffer[index] == -1){
            return false;
        }
        count--;
        buffer[index] = -1;
        head++;
        return true;
    }
    
    int Front() {
        if (count == 0) return -1;
        return buffer[head % N];
    }    
    
    int Rear() {
        int i = (tail - 1) % N ; // this is meant to be the next position for enqueue 
        if (i >= 0 && buffer[i] != -1) return buffer[i];
        else return -1;
        
    }
    
    bool isEmpty() {
       
       return count == 0;

    }
    
    bool isFull() {
        return count == N;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */