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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1, *b = list2;
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        while (a && b) {
            cout << a->val << ' ' << b->val << endl;
            if (a->val <= b->val) {
                tmp->next = a;
                a = a->next;
            }
            else {
                tmp->next = b;
                b = b->next;
            }
            tmp = tmp->next;
        }
        tmp->next = (a == nullptr) ? b : a;
        return res->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    ListNode* res = Solution().mergeTwoLists(head1, head2);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}