#include<bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            if (minHeap.size() + 1 < maxHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};


int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
}