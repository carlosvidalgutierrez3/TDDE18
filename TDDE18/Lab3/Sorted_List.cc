#include "Sorted_List.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Sorted_List::Sorted_List()
  :head(nullptr)
{}

Sorted_List::Node * Sorted_List::copy(Sorted_List::Node const *n)const
{
  if(n==nullptr){
    return nullptr;
  }
  return new Node{n->value, copy(n->next)};
}

Sorted_List::Sorted_List(Sorted_List const & other)
:head{copy(other.head)}
{}

  Sorted_List::Sorted_List(Sorted_List && other)
  :head{other.head}
  {
    other.head=nullptr;
  }

Sorted_List::~Sorted_List(){
  while(!is_empty()){
    pop();
  }
}


Sorted_List & Sorted_List::operator =(Sorted_List const & other)
{
Sorted_List tmp{other};
std::swap(head,tmp.head);
return *this;
}
Sorted_List & Sorted_List::operator=(Sorted_List && other)
{
std::swap(head,other.head);
return *this;
}

bool Sorted_List::is_empty() const{
  return head == nullptr;
}

void Sorted_List::remove(int val){
  if(is_empty())
    //Do nothing
    return;

  Node* curr{head};

  if (curr->value == val){
    Node* tmp{curr->next};
    delete head;
    head = tmp;
  }
  else{
    while(curr->next->value!=val){
      if(curr->next->next==nullptr){
        return;
      }
      curr = curr->next;
    }

    Node* tmp{curr->next->next};
    delete curr->next;
    curr->next = tmp;

  }
/*
  while(curr->value!=val){
    curr = curr->next;
  }
  if (curr!=nullptr){
    Node* tmp{curr->next};
    delete curr;
    curr = tmp;
  }
  */
}

void Sorted_List::insert(int val){

  if(is_empty()){
    head = new Node{val, head};
  }
  else{
    Node* curr{head};

    if (curr->value < val){
      head = new Node{val, head};
    }
    else if(curr->value > val){
      if (curr->next == nullptr){
        std::cout << "here" << std::endl;
        curr->next = new Node{val, curr->next};
      }
      else{
        insert(val,curr);
      }

    }
  }
}

void Sorted_List::insert(int val, Sorted_List::Node* curr){

  if (curr->next->value < val){
    curr->next = new Node{val, curr->next};
  }
  else if(curr->next->value > val){
    if (curr->next->next == nullptr){
      curr->next->next = new Node{val, curr->next->next};
    }
    else{
      curr = curr->next;
      insert(val,curr);
    }
  }
}

int Sorted_List::pop(){

  int value{head -> value};
  Node * curr{head};
  head = head -> next;
  delete curr;
  return value;

}

int Sorted_List::size(){
  int size = 0;
  Node* tmp{head};
  while(tmp!=nullptr){
    size++;
    tmp = tmp->next; //(*tmp).next
  }
  return size;
}

string Sorted_List::print_list(){
std::stringstream ss{};
  Node* tmp{head};
  while(tmp!=nullptr){
    ss<< tmp->value << "->" ;
    tmp=tmp->next; //(*tmp).next
  }
  if(!is_empty()) ss<< "end\n";
  return ss.str();
}
