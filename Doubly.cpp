#include <iostream>
#include <chrono>

struct Node {
    int data;
    Node* next;
    Node* previous;
};

class LinkedList {
public:

    LinkedList() : root_(nullptr) {}
    ~LinkedList() {}


    int Length() {
        Node* tmp = root_;
        int i = 0;
        while (tmp != nullptr) {
            tmp = tmp->next;
            i++;
        }

        return i;
    }

    void Add(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        Node* last_el = get_last_element();
        if (last_el == nullptr) {
            root_ = new_node;
            new_node->previous = nullptr;
            return;
        }

        last_el->next = new_node;

        Node* current = root_;
        Node* prev = nullptr;

        for (int i = 0; i < Length() && current != nullptr; i++) {

            current->previous = prev;
            prev = current;
            current = current->next;
        }

  
    }

    void Delete(int key) {

        Node* t, * t0;
        int i = 0;
        t = root_;
        t0 = root_;

        while (t != nullptr) {
            if (i == key) {
                if (key == 0) {
                    root_ = t->next;
                    root_->previous = nullptr;
                    delete t;
                    return;
                }

                // we found it delete here
                t0->next = t->next;
                t->next->previous= t0;
                delete t;
                return;
            }
            t0 = t;
            t = t->next;
            i++;
        }

        if (i != key) {
            std::cout << "Not Found" << std::endl;
        }


    }

    Node* get_last_element() {
        Node* tmp = root_;
        while (tmp && tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return tmp;
    }

    void PrintList() {

        if (root_ == nullptr) {
            std::cout << "[Empty]" << std::endl;
            return;
        }

        Node* tmp = root_;
        int i = 0;
        while (tmp != nullptr) {
            std::cout << "[" << i << "](" << tmp->data << ")" << std::endl;
            tmp = tmp->next;
            i++;
        }
    }

    void InsertAtBeginning(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = root_;
        new_node->previous = nullptr;

        if (root_ != nullptr) {
            root_->previous = new_node;
        }
        root_ = new_node;
    }

    void InsertAtPosition(int position, int data) {

        if (position == 0) {
            InsertAtBeginning(data);
            return;
        }

        Node* new_node = new Node();
        new_node->data = data;

        Node* tmp = root_;
        int i = 0;

        while (tmp != nullptr && i < position - 1) {
            tmp = tmp->next;
            i++;
        }

        if (i == position - 1 && tmp != nullptr) {
            new_node->next = tmp->next;
            new_node->previous = tmp;
            tmp->next->previous = new_node;
            tmp->next = new_node;

            return;

        }
        else {
            delete new_node;
            return;
        }

    }

    void getPrevious(int position) {
        if (position <= 0) {
            std::cout << "[nullptr]" << std::endl;
            return;
        }


        Node* tmp = root_;
        Node* prev = root_;
        int i = 0;

        while (tmp != nullptr && i != position) {
            prev = tmp;
            tmp = tmp->next;
            i++;
        }
        if (tmp == root_) {
            std::cout << "[nullptr]" << std::endl;
        }
        else {

            std::cout << "[" << prev->data << "]" << std::endl;
        }
    }



private:
    Node* root_;
};

int main()
{

    LinkedList New;
    New.Add(1);
    New.Add(5);
    New.Add(10);
    New.Add(15);
    New.Add(20);
    New.Add(25);
    New.Add(30);
    New.Add(35);
    New.Add(40);
    New.Add(45);
    New.Add(50);
    New.InsertAtPosition(9, 60);
    New.PrintList();
    New.getPrevious(9);

}
