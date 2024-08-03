#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    unordered_map<int, bool> track;
    int maxCnt = 0, minCnt = 0;

    void addNum(int num, int i) {
        if (!maxCnt || num <= maxHeap.top().first) {
            maxHeap.emplace(num, i);
            maxCnt++;
            track[i] = true;
        }
        else {
            minHeap.emplace(num, i);
            minCnt++;
            track[i] = false;
        }
        balanceHeaps();
    }

    double getMedian(int k) {
        if (k % 2) return maxHeap.top().first;
        else return (static_cast<long long>(maxHeap.top().first) + static_cast<long long>(minHeap.top().first)) / 2.0;
    }

    void dropMax(int left) {
        while (maxHeap.size() && maxCnt && maxHeap.top().second < left) maxHeap.pop();
        while (maxHeap.size() && minCnt && minHeap.top().second < left) minHeap.pop();
    }

    void balanceHeaps() {
        if (maxCnt > minCnt + 1) {
            auto top = maxHeap.top();
            minHeap.push(top);
            maxHeap.pop();
            track[top.second] = false;
            minCnt++;
            maxCnt--;
        }
        else if (minCnt > maxCnt) {
            auto top = minHeap.top();
            maxHeap.push(top);
            minHeap.pop();
            track[top.second] = true;
            maxCnt++;
            minCnt--;
        }
    }

    void cleanHeaps(int left) {
        if (track[left-1]) maxCnt--;
        else minCnt--;
        track.erase(left-1);
        balanceHeaps();
        dropMax(left);
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return vector<double>(nums.begin(), nums.end());
        vector<double> res;
        for (int i = 0; i < k; i++) addNum(nums[i], i);
        res.push_back(getMedian(k));
        for (int i = k; i < nums.size(); i++) {
            addNum(nums[i], i);
            cleanHeaps(i - k + 1);
            res.push_back(getMedian(k));
        }
        return res;
    }
};

int main() {
    vector<int> nums = {6,5,9,5,4,9,1,7,5,5};
    int k = 4;
    vector<double> res = Solution().medianSlidingWindow(nums, k);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}