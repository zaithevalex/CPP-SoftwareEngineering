#include <iostream>

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
            first = last=  newNode;

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

int main() {
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "List: ";
    list.show();

    std::cout << "Middle element: " << list.get() << std::endl;

    list.push_front(0);
    std::cout << "After push_front(0): ";
    list.show();

    list.pop_back();
    std::cout << "After pop_back(): ";
    list.show();

    list.pop_front();
    std::cout << "After pop_front(): ";
    list.show();

    return 0;
}

