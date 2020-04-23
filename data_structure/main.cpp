#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <memory>
#include "StackVector.h"
#include "StackCArray.h"
#include "ListCArray.h"
#include "ListLinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "HashTable.h"
#include "Knapsack.h"
#include "tree.h"
#include "bst.h"
#include "bsttree.h"
#include "sort.h"
#include <iterator>
#include "heap.h"
#include "stl.h"
#include "algo.h"
#include "c11.h"
#include "cpp.h"
#include "Interview.h"
#include "exception.h"
//#include "thread.h"
#include "hanoi.h"
#include "graph.h"

using namespace std;

class unitTest
{
public:
  static void testSTLStack();
  static void testMyStack();
  static void testListCArray();
  static void testListLinkedList();
  static void testStackLinkedList();
  static void testQueueLinkedList();
  static void testHashTable();
  static void testKanpsack();
  static void testTree();
  static void testBSTTree();
  static void testBinarySearchTree();
  static void testSort(); // insertion, bubble, selection, quick sort, merge sort
  static void testHeapSort();
  static void testMergeSort();
  static void testSTL();
  static void testAlgo();
  static void testC11();
  static void testcpp();
  static void interview();
  static void testException();
  static void testthread();
  static void testHanoi();
  static void testGraph();
  static void testTopologicalSort();
  static void testDijkstra();
};

void unitTest::testSTLStack()
{
  // STL stack
  stack<int> iStack;
  iStack.push(1);
  iStack.push(2);
  assert(iStack.top()==2);
  iStack.pop();
  assert(iStack.top()==1);
  iStack.pop();
}

void unitTest::testMyStack()
{
  // my stack
  StackVector<int> myStack;
  myStack.push(1);
  myStack.push(2);

  assert(myStack.top()==2);
  myStack.pop();
  assert(myStack.top()==1);

  StackCArray<int> s1;
  s1.push(1);
  s1.push(2);

  StackCArray<int> s2 = s1; // copy constructor
  StackCArray<int> s3;

  s2 = s2; // self assignment

  s3 = s2; // assignment

  assert(s1.top()==2);
  s1.pop();
  assert(s1.top()==1);
  s1.pop();

  s3.push(3);
  assert(s3.top()==3);
  s3.pop();
  assert(s3.top()==2);
  s3.pop();
  assert(s3.top()==1);
  s3.pop();
}

void unitTest::testListCArray()
{
    // my list
  ListCArray<int> myList;
  assert(myList.length() == 0);
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);
  myList.insert(99,2);
  assert(myList.length() == 4);
  myList.del(1);
  assert(myList.length() == 3);

  assert(myList.retrieve(0)==1);
  assert(myList.retrieve(1)==99);
  assert(myList.retrieve(2)==3);
  assert(myList[1]==99);

  myList[1]=myList[1]*2;
  assert(myList[1] == 198);
}

void unitTest::testListLinkedList()
{
  // my list1
  ListLinkedList<int> *myList1 = new ListLinkedList<int>();
  node<int>*p = myList1->first();
  myList1->insert(1,p);
  p = myList1->first();
  assert(p->val == 1);
  myList1->insert(2,p);
  p = myList1->next(p);
  assert(p->val == 2);
  myList1->insert(3,p);
  p = myList1->next(p);
  assert(p->val == 3);
  myList1->insert(4,p);
  myList1->del(p);
  p = myList1->first();
  myList1->del(p);
  p = myList1->first();
  assert(p->val == 2);
  p = myList1->next(p);
  assert(p->val == 4);
  myList1->del(p);
  p = myList1->first();
  assert(p->val == 2);
  myList1->del(p);
  p = myList1->first();
  assert(p == 0);
  myList1->insert(1,p);
  p = myList1->first();
  assert(p->val == 1);
  delete myList1;
}

void unitTest::testStackLinkedList()
{
  StackLinkedList<int>* myList = new StackLinkedList<int>();
  myList->push_back(1);
  myList->push_back(2);
  myList->push_back(3);
  assert(myList->pop_back()==3);
  assert(myList->pop_back()==2);
  assert(myList->pop_back()==1);
}

void unitTest::testQueueLinkedList()
{
  QueueLinkedList<int>* q = new QueueLinkedList<int>();
  assert(q->isEmpty()==true);
  q->push_back(1);
  assert(q->isEmpty()==false);
  q->push_back(2);
  q->push_back(3);
  assert(q->pop_front() == 1);
  assert(q->isEmpty()==false);
  assert(q->pop_front() == 2);
  assert(q->pop_front() == 3);
  assert(q->isEmpty()==true);
}

void unitTest::testHashTable()
{
  HashTable* tbl = new HashTable();
  tbl->insert("One", 1);
  tbl->insert("Two", 2);
  tbl->insert("Three",3);
  assert(tbl->get("One") == 1);
  assert(tbl->get("Two") == 2);
  assert(tbl->get("Three") == 3);
}

void unitTest::testKanpsack()
{
  std::vector<int> v;
  v.push_back(7);
  v.push_back(5);
  v.push_back(4);
  v.push_back(4);
  v.push_back(1);
  Knapsack::doIt(v,0,10);
}

void unitTest::testTree()
{
  std::vector<int> o; // used for storing travese sequence

  /* t1:
             1
            / 
           2
          / \
         3   4
          \
           5
  */

  node<int> *n5 = new node<int>(5);
  node<int> *n4 = new node<int>(4);
  node<int> *n3 = new node<int>(3,0,n5);
  node<int> *n2 = new node<int>(2,n3,n4);
  node<int> *n1 = new node<int>(1,n2,0);
  tree<int> *t1 = new tree<int>(n1);

  // preorder
  t1->preorder(o); // 1 2 3 5 4
  assert(o.at(0)==1 && o.at(1)==2 && o.at(2)==3 && o.at(3)==5 && o.at(4)==4);

  // inorder
  o.clear();
  t1->inorder(o);  
  assert(o.at(0)==3 && o.at(1)==5 && o.at(2)==2 && o.at(3)==4 && o.at(4)==1);

  // postorder
  o.clear();
  t1->postorder(o); // 5 3 4 2 1
  assert(o.at(0)==5 && o.at(1)==3 && o.at(2)==4 && o.at(3)==2 && o.at(4)==1);

  // height
  assert(t1->height() == 3); 
  assert(t1->height(n2) == 2);
  assert(t1->height(n3) == 1);
  assert(t1->height(n4) == 0);
  assert(t1->height(n5) == 0);

  // ancestor
  assert(t1->isAncestor(n1,n5)==true);
  assert(t1->isAncestor(n1,n2)==true);
  assert(t1->isAncestor(n1,n4)==true);
  assert(t1->isAncestor(n2,n3)==true);
  assert(t1->isAncestor(n2,n4)==true);
  assert(t1->isAncestor(n3,n5)==true);
  assert(t1->isAncestor(n3,n4)==false);
  assert(t1->isAncestor(n3,n1)==false);
  assert(t1->isAncestor(n4,n5)==false);
  assert(t1->isAncestor(n5,n2)==false);
  assert(t1->isAncestor(n2,n1)==false);

  /* t2:
             1
            / 
           2
          / \
         3   4
          \
           5
  */    
  node<int> *n10 = new node<int>(5);
  node<int> *n9 = new node<int>(4);
  node<int> *n8 = new node<int>(3,0,n10);
  node<int> *n7 = new node<int>(2,n8,n9);
  node<int> *n6 = new node<int>(1,n7,0);
  tree<int> *t2 = new tree<int>(n6);

  // t2 == t1
  assert(t1->isEqual(*t2)==true);
 
  /* t3:
             1
            / 
           2
          / \
         3   4
          \
           5
          /
         0
  */  

  node<int> *n16 = new node<int>(0);
  node<int> *n15 = new node<int>(5,n16);
  node<int> *n14 = new node<int>(4);
  node<int> *n13 = new node<int>(3,0,n15);
  node<int> *n12 = new node<int>(2,n13,n14);
  node<int> *n11 = new node<int>(1,n12,0);
  tree<int> *t3 = new tree<int>(n11); 

  // t1 != t3
  assert(t1->isEqual(*t3)==false);

  // copy constructor
  tree<int> *t4 = new tree<int>(*t3);
  assert(t4->isEqual(*t3));

  // t4 inoder should be that of t3 inoder
  o.clear();
  t4->inorder(o); 
  assert(o.at(0)==3 && o.at(1)==0 && o.at(2)==5 && o.at(3)==2 && o.at(4)==4 && o.at(5)==1);
  
  // t4 self assignment should not crash
  *t4 = *t4; 
  assert(true==true);
  
  // check t4 inroder one more time
  o.clear();
  t4->inorder(o); 
  assert(o.at(0)==3 && o.at(1)==0 && o.at(2)==5 && o.at(3)==2 && o.at(4)==4 && o.at(5)==1);
  
  // assignment operator
  assert(t4->isEqual(*t2)==false);
  *t4 = *t2; 
  assert(t4->isEqual(*t2)==true);
  
  // t4 in order has changed
  o.clear();
  t4->inorder(o); // 3 5 2 4 1
  assert(o.at(0)==3 && o.at(1)==5 && o.at(2)==2 && o.at(3)==4 && o.at(4)==1);

  // find()
  assert(t4->find(0)==false);
  assert(t4->find(5)==true);

  delete t1;
  delete t2;
  delete t3;
  delete t4;
 
  return;
}

void unitTest::testBSTTree()
{
  std::vector<int> o; // storing traversing sequence

  /* t1:  (10,5,14,7,12,18, 6, 8, 15)

              10
            /   \
           5    14
            \   / \
            7  12  18
           / \     /
          6   8   15
  */

  bst<int> *t1 = new bst<int>();
  int arr[] = {10,5,14,7,12,18,6,8,15};
  std::vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
  t1->insert(v);

  // t1 inorder
  t1->inorder(o);
  assert(o.at(0)==5&& o.at(1)==6 && o.at(2)==7 &&o.at(3)==8 && o.at(4)==10 && o.at(5)==12 && o.at(6)==14 && o.at(7)==15 && o.at(8)==18);

  // find()
  assert(t1->find(0) == false);
  assert(t1->find(18) == true);
  assert(t1->find(7) == true);

  // delete();

  // delete a node with no children
  bool deleted = false;
  t1->del(6);
  assert(t1->find(6)==false);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==5 &&o.at(1)==7 && o.at(2)==8 && o.at(3)==10 && o.at(4)==12 && o.at(5)==14 && o.at(6)==15 && o.at(7)==18);

  // delete a node with just one chid, which is a right child
  t1->del(5);
  assert(t1->find(5)==false);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 && o.at(1)==8 && o.at(2)==10 && o.at(3)==12 && o.at(4)==14 && o.at(5)==15 && o.at(6)==18);

  // delete a node with just one child, which is a left child
  t1->del(18);
  assert(t1->find(18)==false);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 &&o.at(1)==8 && o.at(2)==10 && o.at(3)==12 && o.at(4)==14 && o.at(5)==15);
  
  // delete a node with two children
  t1->del(10);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 &&o.at(1)==8 && o.at(2)==12 && o.at(3)==14 && o.at(4)==15);

  t1->del(12);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 &&o.at(1)==8 && o.at(2)==14 && o.at(3)==15);

  t1->del(14);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 &&o.at(1)==8 && o.at(2)==15);

  t1->del(15);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==7 &&o.at(1)==8);

  t1->del(7);
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==8);

  t1->del(8);
  o.clear();
  t1->inorder(o);
  assert(o.size()==0);

  delete t1;
}

void unitTest::testBinarySearchTree()
{
  std::vector<int> o; // storing traversing sequence

  /* t1:  (10,5,14,7,12,18, 6, 8, 15)

              10
            /   \
           5    14
            \   / \
            7  12  18
           / \     /
          6   8   15
  */
  BinarySearchTree<int> *t1 = new BinarySearchTree<int>();
  t1->insert(10);
  t1->insert(5);
  t1->insert(14);
  t1->insert(7);
  t1->insert(12);
  t1->insert(18);
  t1->insert(6);
  t1->insert(8);  
  t1->insert(15);

  // t1 inorder
  o.clear();
  t1->inorder(o);
  assert(o.at(0)==5&& o.at(1)==6 && o.at(2)==7 &&o.at(3)==8 && o.at(4)==10 && o.at(5)==12 && o.at(6)==14 && o.at(7)==15 && o.at(8)==18);
  
  // delete
  t1->delete_data(15);
  t1->delete_data(5);
  t1->delete_data(14);
  t1->delete_data(10);

  o.clear();
  t1->inorder(o);
  assert(o.at(0)==6&& o.at(1)==7 && o.at(2)==8 && o.at(3)==12 && o.at(4)==18);
}

void unitTest::testSort()
{
  int arr[] = {1,5,4,7,2,8,6,8,-1};
  std::vector<int> v(arr,arr+sizeof(arr)/sizeof(int));

  // bubble sort
  std::vector<int> v1 = v;
  sort1::bubbleSort<int>(v1);
  assert(std::is_sorted(v1.begin(), v1.end())==true);

  // insertion sort
  v1 = v;
  sort1::insertionSort(v1);
  assert(std::is_sorted(v1.begin(), v1.end())==true);

  // selection sort
  v1 = v;
  sort1::selectionSort(v1);
  assert(std::is_sorted(v1.begin(), v1.end())==true);

  // quick sort (non distinct)
  v1 = v;
  sort1::quickSort(v1,0,v1.size()-1);
  assert(std::is_sorted(v1.begin(), v1.end())==true);

  // quick sort (distinct)
  int arr2[] = {6,10,13,5,8,3,2,11};
  v1.clear();
  std::copy(&arr2[0], &arr2[sizeof(arr2)/sizeof(int)], std::back_inserter(v1));
  sort1::quickSort(v1,0,v1.size()-1);
  assert(std::is_sorted(v1.begin(), v1.end())==true);

  // merge sort
  v1 = v;
  std::vector<int> v2 = sort1::mergeSort(v1);
  assert(std::is_sorted(v2.begin(), v2.end())==true);
}

void unitTest::testHeapSort()
{
  int arr[] = {20, 40, 11, 70, 80,30};
  std::vector<int> v(arr,arr+sizeof(arr)/sizeof(int));

  int o[] = {80,70,40,30,20,11};
  int n = v.size();
  
  int ins[] = {10,30,20,40,50,90,80,60,70,0};
  std::vector<int> output;
  /*
  // a max heap
  std::shared_ptr<Heap::heap<int>> 
    h(new Heap::heap<int>(v));

  // check the max heap
  for (int i=0; i<n; i++)
    assert(h->extractTop() == o[i]);

  // insert into a max heap
  h.reset(new Heap::heap<int>(v));
  for(int i=0; i<10; i++)
    h->insert(ins[i]);

  // check the max heap
  for (int i=0; i<16; i++)
    output.push_back(h->extractTop());
  assert(std::is_sorted(output.begin(), output.end(), std::greater<int>()) == true);
  output.clear();

  // start with an empty heap, and insert
  v.clear();
  h.reset(new Heap::heap<int>(v));
  for (int i=0; i<10; i++)
    h->insert(80);

  // check (note the impementation of insert() should maintian stable order
  for (int i=0; i<10; i++)
    assert(h->extractTop() == 80);
  */
  // a min heap
  v.assign(arr,arr+sizeof(arr)/sizeof(int));
  std::shared_ptr<Heap::heap<int>> h1(new Heap::heap<int>(v));

  // check the min heap
  for (int i=0; i<n; i++)
    assert(h1->pop() == o[n-1-i]);
  /*
  // insert into a min heap
  h1.reset(new Heap::heap<int>(v));
  for(int i=0; i<10; i++)
    h1->insert(ins[i]);

  // check the min heap
  for (int i=0; i<16; i++)
    output.push_back(h1->pop());
  assert(std::is_sorted(output.begin(), output.end(), std::less<int>()) == true);
  output.clear();
  */
}

void unitTest::testSTL()
{
  //stl::test_array();
  stl::test_vector();
  stl::test_unordered_map();
  stl::test_priority_queue();
  stl::test_heap();
}

void unitTest::testAlgo()
{
  assert(algo::fib(0) == 0);
  assert(algo::fib(1) == 1);
  assert(algo::fib(8) == 21);
  assert(algo::fib(10)==55);
  assert(algo::fib(20)==6765);
  assert(algo::fib(30)==832040);
  //assert(algo::fib(40)==102334155); // exponential time 
  //assert(algo::fib(54)==701408733); // exponnetial time

  int s = sizeof(int);
  s = sizeof(long long);
  assert(algo::fib_bottomup(0)==0);
  assert(algo::fib_bottomup(1)==1);
  assert(algo::fib_bottomup(8)==21);
  assert(algo::fib_bottomup(10)==55);
  assert(algo::fib_bottomup(20)==6765);
  assert(algo::fib_bottomup(30)==832040);
  assert(algo::fib_bottomup(40)==102334155);
  assert(algo::fib_bottomup(54)==86267571272);
}

void unitTest::testC11()
{
  // auto
  C11::testAuto();
  // smart pointers
  C11::testUniquePointer();
  C11::testWeakPointer();
  C11::testSharedPointer();
  C11::testSharedPointerCycleReference();
  C11::test_sharedPointer_BreakCycleWithWeakPtr();
  //C11::testRangeBaseLoop();
  C11:: testNullPointer();
}

void unitTest::testcpp()
{
  cpp::test_mutable();
  cpp::test_friend();
  cpp::test_static_cast();
  cpp::test_dynamic_cast();
  cpp::test_reinterpret_cast();
  cpp::test_ctor_throw();
}

void unitTest::interview()
{
  interview::test_printodd();
  //interview::test_addfive_to_9();
  interview::reverse_linkedlist();
  assert(interview::test_linkedlist_cycle1() == false); // no cycled
  assert(interview::test_linkedlist_cycle2() == true); // yes cycled
  interview::test_vbase();
  interview::test_operators();
  interview::test_constructors();
  interview::test_delete();
  interview::test_delete_null();
  interview::test_const();
  interview::test_const_cast();
}

void unitTest::testException()
{
  jk::exceptin_in_constructor();
  jk::exceptin_in_destructor();
}

void unitTest::testHanoi()
{
  algo::hanoi hanoi;
  std::vector<int> v_in;
  for (int i=4; i>=1; i--)
    v_in.push_back(i);
  hanoi.set(v_in);
  hanoi.move(v_in.rbegin(), v_in.rend(), 0, 2); // move all elements from pole 0 to pole 2
}

void unitTest::testGraph()
{
  graph::G g;
  g.bfs(0); // output 0 1 3 4; distance 0 1 1 2
  g.dfs(0); // output: 0 1 4 3; distance 0 1 2 1
}

void unitTest::testTopologicalSort()
{
  /*
          0
        /   \
       3     2
      / \   / \
     1   4  5  6

     output: 0 3 1 4 2 5 6 (distance 0 1 2 2 1 2 2)
  */

  std::vector<std::vector<graph::edge>> v; // adjacency list

  std::vector<graph::edge> adjacentList;
  // adjacent list for node 0
  adjacentList.push_back(graph::edge(0,3,1));
  adjacentList.push_back(graph::edge(0,2,1));
  v.push_back(adjacentList);

  // adjacent list for node 1
  adjacentList.clear();
  v.push_back(adjacentList);

  // adjacent list for node 2
  adjacentList.clear();
  adjacentList.push_back(graph::edge(2,5,1));
  adjacentList.push_back(graph::edge(2,6,1));
  v.push_back(adjacentList);

  // adjacent list for node 3
  adjacentList.clear();
  adjacentList.push_back(graph::edge(3,1,1));
  adjacentList.push_back(graph::edge(3,4,1));
  v.push_back(adjacentList);

  // adjacent list for node 4
  adjacentList.clear();
  v.push_back(adjacentList);

  // adjacent list for node 5
  adjacentList.clear();
  v.push_back(adjacentList);

  // adjacent list for node 6
  adjacentList.clear();
  v.push_back(adjacentList);
  assert(v.size() == 7);

  graph::G g(v);
  g.dfs(0);
}


void unitTest::testDijkstra()
{
  /*
               0
            /      \
      (0,1,10)       (0,4,100)
        /        \
    1         (0,3,30)  4
     \                   \   (3,4,60)
     (1,2,50) /(2,4,10) 
       2   (3,2,20) -    3

  */

  std::vector<std::vector<graph::edge>> v; // adjacency list

  std::vector<graph::edge> adjacentList;

  // adjacent list for node 0
  adjacentList.push_back(graph::edge(0,1,10));
  adjacentList.push_back(graph::edge(0,3,30));
  adjacentList.push_back(graph::edge(0,4,100));
  v.push_back(adjacentList);

  // adjacent list for node 1
  adjacentList.clear();
  adjacentList.push_back(graph::edge(1,2,50));
  v.push_back(adjacentList);

  // adjacent list for node 2
  adjacentList.clear();
  adjacentList.push_back(graph::edge(2,4,10));
  v.push_back(adjacentList);

  // adjacent list for node 3
  adjacentList.clear();
  adjacentList.push_back(graph::edge(3,2,20));
  adjacentList.push_back(graph::edge(3,4,60));
  v.push_back(adjacentList);

  // adjacent list for node 4
  adjacentList.clear();
  v.push_back(adjacentList);

  assert(v.size() == 5);

  graph::G g(v); 
  g.dijkstra(0); // start node: 0
}
int main(int argc, char**argv)
{
  unitTest::testSTLStack();
  unitTest::testMyStack();
  unitTest::testListCArray();
  unitTest::testListLinkedList();
  unitTest::testStackLinkedList();
  unitTest::testQueueLinkedList();
  unitTest::testHashTable();
  //unitTest::testKanpsack();
  unitTest::testTree();
  unitTest::testBSTTree();
  unitTest::testBinarySearchTree();
  unitTest::testSort();
  unitTest::testHeapSort();
  unitTest::testSTL();
  unitTest::testAlgo();
  unitTest::testC11();
  unitTest::testcpp();
  unitTest::interview();
  unitTest::testException();
  //unitTest::testthread();
  unitTest::testHanoi();

  // graph
  unitTest::testGraph();
  unitTest::testTopologicalSort();
  unitTest::testDijkstra();
  return 1;
};