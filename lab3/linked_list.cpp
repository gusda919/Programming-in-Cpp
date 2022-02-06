 
    #include "linked_list.h"
    #include <stdexcept>
    #include <iostream>
    #include <string>
   

    using namespace std;

    //SPECIAL MEMBER FUNCTIONS

    // Constructor
    linked_list::linked_list(): first{nullptr}
    {
    }

    // Destructor
    linked_list::~linked_list() {
        Node* current{first};

        while (current != nullptr){
            Node* tmp{current->next};
            delete current;
            current = tmp;
        }
    }

    // Copy constructor 
    linked_list::linked_list(linked_list const& other) {
        Node* current = other.first;

        while (current != nullptr) {
            insert(current->value);
            current = current->next;
        }
    }

    // Move constructor
    linked_list::linked_list(linked_list&& other) : first{other.first} {
        other.first = nullptr;
    }

    // Copy assignment operator
    linked_list& linked_list::operator=(linked_list const& other){
        linked_list tmp(other);
        std::swap(tmp.first, this->first);
        return *this;
    }


    // Move assignment
    linked_list& linked_list::operator=(linked_list&& other) {
        linked_list tmp{};
        std::swap(tmp.first, first);
        std::swap(first, other.first);
        return *this;
    }


    //METHODS

     // Destructor
    void linked_list::clear_list() {
        Node* current{first};

        while (current != nullptr){
            Node* tmp{current->next};
            delete current;
            current = tmp;
        }
    }


    //Insert, recursive function

    void linked_list::insert(int value) {
        insert(first, value);
    }

    void linked_list::insert(Node*& first, int value) {

    if (first ==NULL){
        first = new Node{value, nullptr};
        return;
    }
    
    else if (first->value > value) {
        first = new Node{value, first};
    }
   
    else if (first->next == NULL) {
        first->next = new Node{value, nullptr};
    }
    
    else {
        insert(first->next, value);
    }
    
}

//Remove function

void linked_list::remove (int value) {

    Node* current{first};
    Node* temp;

    if (first == NULL) {
        return;
    }

    if (first->value == value) {
        Node* new_first{first};
        first = first->next;
        delete new_first;
        return;
    }

    while (current->value != value) {
        temp=current;
        current = current->next;
    }

    temp -> next = current -> next;
    delete current; 
}

//At function

int linked_list:: at (int index) const {
    Node* tmp{first};



    for (int i = 0; i < index; i++) {
       tmp-> next;
    }
    
    if ( tmp == NULL) {

        return 0;
    }

    return tmp->value;

}

bool linked_list::is_empty() const{

   
    return (first == nullptr);
}


//print list function

string linked_list:: print_list() {
    Node* node{first};
    
    std::string str{"{ "};
 
  while (node != NULL) {
        str += std::to_string(node -> value) + (" ");
        node = node-> next;
    }

    str += "}";
    return str;
}