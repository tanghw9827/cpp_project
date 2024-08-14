class MyLinkedList {
public:
    struct LinkNode {
        LinkNode* next;
        int val;
        LinkNode() : val(0), next(nullptr) {}
        LinkNode(int x) : val(x), next(nullptr) {}
        LinkNode(int x, LinkNode* next) : val(x), next(next) {}
    };
    MyLinkedList() {
        size = 0;
        dummy_head = new LinkNode(0);
    }

    int get(int index) {
        if (index > size - 1 || index < 0) {
            return -1;
        }
        LinkNode* cur = dummy_head;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkNode* temp = dummy_head->next;
        LinkNode* node = new LinkNode(val, temp);
        dummy_head->next = node;
        size++;
    }

    void addAtTail(int val) {
        LinkNode* cur = dummy_head;
        for (int i = 0; i <= size -1; i++) {
            cur = cur->next;
        }
        LinkNode* node = new LinkNode(val);
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }
        LinkNode* cur = dummy_head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        LinkNode* temp = cur->next;
        LinkNode* node = new LinkNode(val, temp);
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index > size - 1 || index < 0) {
            return;
        }
        LinkNode* cur = dummy_head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        LinkNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
private:
    LinkNode* dummy_head;
    int size;
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