class MedianFinder {
    priority_queue<int> smaller; // this is a max heap
    priority_queue<int, vector<int>, greater<>> larger; // this is a min heap 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller.empty() || num < smaller.top()){
            smaller.push(num);
        }
        else{
            larger.push(num);
        }

        if (smaller.size() > larger.size() + 1){
            larger.push(smaller.top());
            smaller.pop();
        }
        else if (larger.size() > smaller.size()){
            smaller.push(larger.top());
            larger.pop();

        }
        
    }
    
    double findMedian() {
        // we check for if they are not the same length 

        if (smaller.size() > larger.size()){
            return smaller.top();
        }
        else{
            int val = smaller.top() + larger.top();
            double res = val / 2.0 ;

            return res;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */