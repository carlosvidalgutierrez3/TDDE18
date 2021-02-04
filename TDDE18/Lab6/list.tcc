#include <algorithm>
#include <iostream>

#include "list.h"

template <typename Data>
void List<Data>::insert(Data const& d)
{
  first = new Link(d, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff
template <typename Data>
typename List<Data>::Link*
List<Data>::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

template <typename Data>
List<Data>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template <typename Data>
List<Data>::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template <typename Data>
List<Data>::List(List&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template <typename Data>
List<Data>& List<Data>::operator=(List const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template <typename Data>
List<Data>& List<Data>::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}
