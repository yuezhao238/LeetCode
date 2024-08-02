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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        ListNode* one = l1, *two = l2;
        int prev_add = 0;
        while (one || two) {
            int sum = prev_add;
            if (one != nullptr) sum += one->val;
            if (two != nullptr) sum += two->val;
            int cur = sum % 10, add = sum / 10;
            tmp->next = new ListNode(cur);
            tmp = tmp->next;
            prev_add = add;
            one = (one != nullptr) ? one->next : one;
            two = (two != nullptr) ? two->next : two;
        }
        if (prev_add) tmp->next = new ListNode(1);
        return res->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    // head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    ListNode* res = Solution().addTwoNumbers(head1, head2);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
}