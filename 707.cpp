struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int val): val(val), next(nullptr) {}
    Node(int val, Node* next): val(val), next(next) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        Node* temp = head;
        while (index-- && temp) {
            temp = temp->next;
        }
        return (temp ? temp->val : -1); // 返回-1表示索引超出范围
    }
    
    void addAtHead(int val) {
        Node* addNode = new Node(val, head);
        head = addNode;
        if (tail == nullptr) { // 如果链表为空，更新tail
            tail = head;
        }
    }
    
    void addAtTail(int val) {
        Node* addNode = new Node(val);
        if (tail) {
            tail->next = addNode;
            tail = addNode;
        } else { // 如果链表为空，更新head和tail
            head = tail = addNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        while (--index && temp) {
            temp = temp->next;
        }
        if (temp) {
            Node* addNode = new Node(val, temp->next);
            temp->next = addNode;
            if (addNode->next == nullptr) { // 如果插入的是最后一个节点，更新tail
                tail = addNode;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0 && head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            if (head == nullptr) { // 如果链表变为空，更新tail
                tail = nullptr;
            }
            return;
        }
        Node* temp = head;
        while (--index && temp && temp->next) {
            temp = temp->next;
        }
        if (temp && temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next == nullptr) { // 如果删除的是最后一个节点，更新tail
                tail = temp;
            }
            delete toDelete;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    // myLinkedList.addAtIndex(1, 2);
    // myLinkedList.get(1);
    // myLinkedList.deleteAtIndex(1);
    // myLinkedList.get(1);
}