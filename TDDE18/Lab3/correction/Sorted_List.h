#ifndef LIST_H
#define LIST_H
#include <string>

/*
TODO:
All functions that doesnt affect the list should be const

All functions that has anything to do with Node as either return type
or parameter needs to be private because the user should not have acces
to that data type.
*/

class Sorted_List{
  private:
    struct Node
    {
      int value{};
      Node * next{};
    };
    Node * head{};
    Node * copy(Node const *n) const;
    void insert(int val, Node* curr);
  public:
    Sorted_List();
    Sorted_List(Sorted_List const & other); //copy constructor
    Sorted_List(Sorted_List && other);  //move constructor
    Sorted_List & operator =(Sorted_List const & other); //copy ass op
    Sorted_List & operator =(Sorted_List && other); //move ass op
    ~Sorted_List();

    bool is_empty() const;
    void remove(int val);
    void insert(int val);
    int pop();
    int size() const;
    std::string print_list() const;


};

#endif
