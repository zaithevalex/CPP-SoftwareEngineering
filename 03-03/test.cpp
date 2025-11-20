#include <cassert>
#include <iostream>
#include <sstream>

class List {
private:
    struct Node {
        int value;
        Node* next;

        Node(int val) : value(val), next(nullptr) {}
    };

    Node* first;
    Node* last;

public:
    List() : first(nullptr), last(nullptr) {}

    ~List() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

    bool empty() const {
        return first == nullptr;
    }

    void show() const {
        Node* current = first;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            newNode->next = first;
            first = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void pop_front() {
        if (first == nullptr) {
            return;
        }
        Node* temp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (first == nullptr) {
            return;
        }
        if (first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        Node* current = first;
        while (current->next != last) {
            current = current->next;
        }
        delete last;
        last = current;
        last->next = nullptr;
    }

    int get() const {
        if (first == nullptr) {
            return 0;
        }
        Node* slow = first;
        Node* fast = first;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->value;
    }
};

void testEmpty() {
    List list;
    assert(list.empty() == true);
    
    list.push_back(1);
    assert(list.empty() == false);
    
    list.pop_back();
    assert(list.empty() == true);
}

void testPushBack() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.empty() == false);
}

void testPushFront() {
    List list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    assert(list.empty() == false);
}

void testPopFront() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    assert(list.empty() == false);
    
    list.pop_front();
    assert(list.empty() == true);
}

void testPopBack() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    assert(list.empty() == false);
    
    list.pop_back();
    assert(list.empty() == true);
}

void testGet() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.get() == 2);
    
    list.push_back(4);
    assert(list.get() == 2);
    
    list.push_back(5);
    assert(list.get() == 3);
}

void testCombined() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    assert(list.get() == 1);
    
    list.pop_back();
    assert(list.get() == 0);
    
    list.pop_front();
    assert(list.get() == 1);
}

int main() {
    testEmpty();
    testPushBack();
    testPushFront();
    testPopFront();
    testPopBack();
    testGet();
    testCombined();
    return 0;
}
