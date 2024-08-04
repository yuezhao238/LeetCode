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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     while (curr) {
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
    // ListNode* addTwo(ListNode* l1, ListNode* l2, int carry) {
    //     if (l1 == nullptr && l2 == nullptr) return carry ? new ListNode(carry) : nullptr;
    //     if (l1 == nullptr) swap(l1, l2);
    //     carry += l1->val + (l2 ? l2->val : 0);
    //     l1->val = carry % 10;
    //     l1->next = addTwo(l1->next, (l2 ? l2->next : nullptr), carry / 10);
    //     return l1;
    // }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     l1 = reverseList(l1);
    //     l2 = reverseList(l2);
    //     auto l3 = addTwo(l1, l2, 0);
    //     return reverseList(l3);
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry /= 10;
            auto curnode = new ListNode(cur % 10);
            curnode->next = ans;
            ans = curnode;
        }
        return ans;
    }
};

int main() {
    ListNode* head1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode* head2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* res = Solution().addTwoNumbers(head1, head2);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}