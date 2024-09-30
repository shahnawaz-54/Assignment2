#pragma once
#include <stdexcept> // For exceptions like std::underflow_error, std::out_of_range

// Define the Node structure
template <typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    Node(const Item_Type& data_item, Node* next_ptr = nullptr)
        : data(data_item), next(next_ptr) {}
};

// Define the SingleLinkedList class
template <typename Item_Type>
class SingleLinkedList {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    // Constructor
    SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor
    ~SingleLinkedList() {
        while (!empty()) {
            pop_front();
        }
    }

    // Function prototypes
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    size_t size() const { return num_items; }
};

// Function definitions

template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
    head = new_node;
    if (tail == nullptr) {
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (tail != nullptr) {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr) {
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {
    if (empty()) {
        throw std::underflow_error("List is empty.");
    }
    Node<Item_Type>* old_node = head;
    head = head->next;
    delete old_node;
    num_items--;
    if (num_items == 0) {
        tail = nullptr;
    }
}

template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {
    if (empty()) {
        throw std::underflow_error("List is empty.");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<Item_Type>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() const {
    if (empty()) {
        throw std::underflow_error("List is empty.");
    }
    return head->data;
}

template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() const {
    if (empty()) {
        throw std::underflow_error("List is empty.");
    }
    return tail->data;
}

template <typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
    return head == nullptr;
}

template <typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        throw std::out_of_range("Index out of range.");
    }
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<Item_Type>* new_node = new Node<Item_Type>(item, current->next);
        current->next = new_node;
        num_items++;
    }
}

template <typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<Item_Type>* node_to_delete = current->next;
        current->next = node_to_delete->next;
        delete node_to_delete;
        if (index == num_items - 1) {
            tail = current;
        }
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
            index; 
    }
    return num_items;  // return num_items if not found
}
