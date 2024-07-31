struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int val): val(val), next(nullptr) {}
    Node(int val, Node* next): val(val), next(next) {}
};

class Skiplist {
public:
    Skiplist() {

    }
    
    bool search(int target) {

    }
    
    void add(int num) {

    }
    
    bool erase(int num) {

    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */