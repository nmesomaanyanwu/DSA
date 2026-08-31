class MedianFinder {
    priority_queue<int , vector<int>, greater<>> minHeap; // this will contain the higher half of our median stream
    priority_queue<int> maxHeap;//this will contain the lower half 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!maxHeap.empty() && num > maxHeap.top()) {
        minHeap.push(num);
    }
    else {
        maxHeap.push(num);
    }
        
       
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size() && maxHeap.size() == minHeap.size() + 1){
            return maxHeap.top();
        }
        else if (maxHeap.size() < minHeap.size() && maxHeap.size() + 1 == minHeap.size()){
            return minHeap.top();
        }
        else if (maxHeap.size() == minHeap.size()){
            int a = maxHeap.top();
            int b = minHeap.top();

            return (a + b)/2.0;
        }
        else{
            return 0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */