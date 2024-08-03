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
    // priority_queue<int, vector<int>, greater<int>>q;
    // ListNode* sortList(ListNode* head) {
    //     ListNode* res = new ListNode();
    //     ListNode* tmp = head;
    //     while (tmp) {
    //         q.push(tmp->val);
    //         tmp = tmp->next;
    //     }
    //     tmp = res;
    //     while (!q.empty()) {
    //         tmp->next = new ListNode(q.top());
    //         q.pop();
    //         tmp = tmp->next;
    //     }
    //     return res->next;
    // }

    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) return (l1 == nullptr) ? l2 : l1;
        ListNode* newHead = (l1->val < l2->val) ? l1 : l2;
        newHead->next = (l1->val < l2->val) ? merge(l1->next, l2) : merge(l1, l2->next);
        return newHead;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode* res = Solution().sortList(head);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}