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
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); i++) ans = mergeTwoLists(ans, lists[i]);
        return ans;
    }
};


int main() {
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));
    vector<ListNode*> input = {a, b, c};
    ListNode* res = Solution().mergeKLists(input);
    ListNode* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}