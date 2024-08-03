#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // unordered_map<Node*, Node*> cache;
    // Node* copyRandomList(Node* head) {
    //     if (head == nullptr) return head;
    //     if (cache.count(head)) return cache[head];
    //     else {
    //         Node* newhead = new Node(head->val);
    //         cache[head] = newhead;
    //         newhead->next = copyRandomList(head->next);
    //         newhead->random = copyRandomList(head->random);
    //         return newhead;
    //     }
    // }

    unordered_map<Node*, Node*>cache;
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        while (tmp) {
            cache[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            cache[tmp]->next = cache[tmp->next];
            cache[tmp]->random = cache[tmp->random];
            tmp = tmp->next;
        }
        return cache[head];
    }
};

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    Node* res = Solution().copyRandomList(head);
    Node* tmp = res;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}