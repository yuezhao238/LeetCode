#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;
        list<int>arr;
        ListNode* iter = head;
        while (iter != nullptr) {
            arr.push_back(iter->val);
            iter = iter->next;
        }
        auto left = arr.begin(), right = arr.end();
        right--;
        while (left != right) {
            cout<< *left<<" "<<*right<<endl;
            if (*left != *right) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << Solution().isPalindrome(head) << endl;
}