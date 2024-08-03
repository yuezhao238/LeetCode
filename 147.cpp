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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr) {
            if (lastSorted->val <= curr->val) lastSorted = lastSorted->next;
            else {
                ListNode* prev = dummyHead;
                while (prev->next->val <= curr->val) prev = prev->next;
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode* res = Solution().insertionSortList(head);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}