#ifndef LINKED_LIST_H

#include <string>
#define LINKED_LIST_H

class linked_list{
public:

    //SPECIAL MEMBER FUNCTIONS

    // Constructor
    linked_list();
    //Destructor
    ~linked_list();
    // Copy constructor
    linked_list(linked_list const& other);
    // Move constructor
    linked_list(linked_list&& other);
    // Copy assignment operator
    linked_list& operator=(linked_list const& other);
    // Move assignment operator
    linked_list& operator=(linked_list&& other);

    //METHODS

    void clear_list();
    void insert(int value);
    void remove(int value);
    bool is_empty() const;
    int at(int index) const;
    std:: string print_list();

private:
    struct Node {
        int value;
        Node* next;
    };
    Node* first{};
    void insert(Node*& first, int value);
};

#endif