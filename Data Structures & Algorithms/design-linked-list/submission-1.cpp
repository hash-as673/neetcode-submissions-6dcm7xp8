class MyLinkedList {
private:
    struct Node {
        int val{0};
        Node* prev{nullptr};
        Node* next{nullptr};
    };

    Node* head{new Node{}};
    Node* tail{new Node{}};
    int size{0};

    [[nodiscard]] Node* getNode(int index) const {
        Node* curr{nullptr};
        if (index < size / 2) {
            curr = head->next;
            for (int i{0}; i < index; ++i) {
                curr = curr->next;
            }
        } else {
            curr = tail->prev;
            for (int i{size - 1}; i > index; --i) {
                curr = curr->prev;
            }
        }
        return curr;
    }

    void insertBefore(Node* succ, int val) {
        Node* pred{succ->prev};
        Node* newNode{new Node{.val{val}, .prev{pred}, .next{succ}}};
        pred->next = newNode;
        succ->prev = newNode;
        ++size;
    }

public:
    MyLinkedList() {
        head->next = tail;
        tail->prev = head;
    }

    ~MyLinkedList() {
        Node* curr{head};
        while (curr != nullptr) {
            Node* nextNode{curr->next};
            delete curr;
            curr = nextNode;
        }
    }

    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;

    [[nodiscard]] int get(int index) const {
        if (index < 0 || index >= size) {
            return -1;
        }
        return getNode(index)->val;
    }

    void addAtHead(int val) {
        insertBefore(head->next, val);
    }

    void addAtTail(int val) {
        insertBefore(tail, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        insertBefore(getNode(index), val);
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* target{getNode(index)};
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
        --size;
    }
};