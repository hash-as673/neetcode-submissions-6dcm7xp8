class BrowserHistory {

private:
    struct Node{
        string url;
        Node* prev;
        Node* next;
        Node (string val) : url(val), prev(nullptr), next(nullptr) {}
    };

    Node* curr;

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* nextNode = curr->next;
        while(nextNode!=nullptr){
            Node* temp = nextNode -> next;
            delete nextNode;
            nextNode = temp;
        }

        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        while (curr->prev != nullptr && steps > 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
   string forward(int steps) {
        while (curr->next != nullptr && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */