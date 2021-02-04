#ifndef LIST_H // _LIST_H_
#define LIST_H

#include <iostream>
#include <string>

//using Data = std::string;

template <typename Data>
class List
{
public:
  List();
  ~List() { delete first; }

  void insert(Data const& d);
  //template <typename T>
  //T List::sum(T d)

  List(List const&);
  List(List&&);
  List& operator=(List const&);
  List& operator=(List&&);

private:

  class Link
  {
  public:
    Link(Data const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }

    friend class List;

    static Link* clone(Link const*);

  private:

    Data data;
    Link* next;
  };

  Link* first;

public:

  using value_type = Data;

  // Suitable place to add things...

};

#include "list.tcc"
#endif
