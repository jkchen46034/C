#ifndef _HEAP_H
#define _HEAP_H

#include <vector>
#include <functional>

namespace Heap
{
// a mini heap with random access capability
template <class T>
class heap
{
typedef pair<T,int>  node_t; // <node_number, T>
private:
  std::vector<node_t> h; // a binary heap, stored in array
  std::vector<int> index; // the index array allow random access
  int bottom; 

  inline int parent(int r) {return (r-1)>>1;}
  inline int left(int r) { return (r<<1)+1;}
  inline int right(int r) {return (r<<1)+2;}

 //virtual bool compare(const T& x, const T& y) const { return x < y;};  // max heap
 virtual bool compare(const T& x, const T& y) const { return x > y;};  // min heap

public:
  heap(){};

  heap(const std::vector<T>& v) // build a heap from an array
  {
    //h = v;
    h.resize(v.size());
    for (int i=0; i<h.size(); i++)
      h[i] = std::make_pair(v.at(i), i);

    bottom = h.size();

    index.resize(h.size());
    for(int i=0; i<index.size(); i++)
        index[i]=i;

    // heapfiy
    for(int i=h.size()/2-1; i>=0 && h.size(); i--) // this stmt and the next together: O(n) operation
      heapify(i);
  }

  int getHeapSize()
  {
    return bottom;
  }
  // given a node, move  t downard to satisfy heap property
  void heapify(int r) // r, index
  {
    int heapSize = getHeapSize();

    if (!heapSize)
      return;

    if (left(r) > heapSize -1)
      return;

    int largest = r;

    if (compare(h[r].first,h[left(r)].first))
      largest = left(r);

    if (right(r) <= heapSize - 1)
      if (compare(h[largest].first,h[right(r)].first))
        largest = right(r);

    if (r!=largest)
    {
      swap(r, largest);
      heapify(largest);
    }
  }

  // retrieve the top node from the heap
  T pop()
  {
    int heapSize = getHeapSize();

    if (!heapSize)
      throw std::exception("underflow");

    swap(0,heapSize-1);
    bottom--;

    // remove the last node
    T root = h[bottom].first;

    // heapify the root node
    if (heapSize)
      heapify(0);
   
    return root;
  }

  // decrease the value on the node at index value r 
  void decrease(int r, T val)
  {
    h[r] = std::make_pair(val, h[r].second);
    int _parent = parent(r);
    while (_parent >= 0 && h[r].first < h[_parent].first)
    {
        swap(r, _parent);
        _parent = parent(_parent);
    }
    return;
  }

  // insert a node
  // insert at end, and move up stream to maintian heap property
  /*
  void insert(T t)
  {
    h.push_back(make_pair(;
    index.push_back(h.siz);

    int heapSize = bottom;

    int r = heapSize - 1;
    while (parent(r) >= 0)
    {
      if (h[r] != h[parent(r)] && !compare(h[r],h[parent(r)])) // must use strict comparision
      {
        swap(r, parent(r));
        r = parent(r);
      }
      else 
        break;
    }
  } */

  // getIndex
  // n: node n
  // returns the index of node n into the heap array
  int getIndex(int n)
  {
    return index[n];
  }

  private:
    // swap the node at heap array indexed by first and second
    void swap(int first, int second)
    {
      std::swap(h[first], h[second]);
      std::swap(index[h[first].second],index[h[second].second]); // swap the index
    }

}; // end of max heap class heap

// a min heap
template <class T> 
class minHeap: public heap<T> {
public:
  minHeap():heap(){};
  minHeap(const std::vector<T>& v):heap(v){};
private:
  virtual bool compare(const T& x, const T& y) const { return x > y;}; 
}; // end of class minHeap
} // namespace
#endif