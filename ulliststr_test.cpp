/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;

void pushBackTest();
void pushFrontTest();
void popFrontTest();
void popBackTest();
void everything();
void printList(ULListStr* list);

int main(int argc, char* argv[])
{
  pushBackTest();
  pushFrontTest();
  popFrontTest();
  popBackTest();
  everything();

  return 0;

}

//function to print a given list
void printList(ULListStr* list)
{
  for (size_t i = 0; i < list->size(); i++)
  {
    cout << list->get(i) << " ";
  }
  cout << endl;

}

//tesing push_front
void pushBackTest()
{
  ULListStr* list = new ULListStr();
  cout << endl;
  cout << "########### Testing Pushing Back##########" << endl << endl;
  
  cout << "Case 1: pushing back 4 to empty list" << endl;
  list->push_back("4");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 2: pushing back 5 to list with one value already in it" << endl;
  list->push_back("5");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 3: pushing back 5 to list until node full, then push back 6 so have to make new node" << endl;
  for (int i = 0; i < ARRSIZE-2; i++)
  {
    list->push_back("5");
  }
  list->push_back("6");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 4: pushing back 7 to list with two node and one value in new node already in it" << endl;
  list->push_back("7");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 5: pushing back 8 until have to add another node with value 9" << endl;
  for (int i = 0; i < ARRSIZE-2; i++)
  {
    list->push_back("8");
  }
  list->push_back("9");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout<< endl;

  cout << "Case 6: pushing back 10 to list with three nodes and one value in third node" << endl;
  list->push_back("10");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  list->clear();
  delete list;

}

//testing push_front
void pushFrontTest()
{
  ULListStr* list = new ULListStr();
  cout << endl;
  cout << "########### Testing Pushing Front ##########" << endl << endl;
  
  cout << "Case 1: pushing 4 to front of empty list" << endl;
  list->push_front("4");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 2: pushing 5 to front of list with one value already in it" << endl;
  list->push_front("5");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 3: pushing 5s front to list until node full, then push front 6 so have to get new node" << endl;
  for (int i = 0; i < ARRSIZE-2; i++)
  {
    list->push_front("5");
  }
  list->push_front("6");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 4: pushing front 7 to list with two node and one value in new node already in it" << endl;
  list->push_front("7");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 5: pushing front 8 until have to add another node with value 9" << endl;
  for (int i = 0; i < ARRSIZE-2; i++)
  {
    list->push_front("8");
  }
  list->push_front("9");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout<< endl;

  cout << "Case 6: pushing front 10 to list with three nodes and one value in first node" << endl;
  list->push_front("10");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  list->clear();
  delete list;
}

//testing pop_front
void popFrontTest()
{
  ULListStr* list = new ULListStr();
  cout << endl;
  cout << "########### Testing Popping Front ##########" << endl << endl;

  cout << "Case 1: Remove first of two values from list" << endl;
  list->push_front("5");
  list->push_front("6");
  cout << "List Before: "; 
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  list->pop_front();
  cout << "List After: ";
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  cout << "front: " << list->front() << " back: " << list->back() << endl << endl;

  cout << "Case 2: Remove only value in head, and delete node" << endl;
  list->push_back("6");
  list->push_back("7");
  cout << "List Before: "; 
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  list->pop_front();
  cout << "List After: ";
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  cout << "front: " << list->front() << " back: " << list->back() << endl << endl;

  list->clear();
  delete list;
}

//testing pop_back
void popBackTest()
{
  ULListStr* list = new ULListStr();
  cout << endl;
  cout << "########### Testing Popping Back ##########" << endl << endl;

  cout << "Case 1: Remove last of two values from list" << endl;
  list->push_front("5");
  list->push_front("6");
  cout << "List Before: "; 
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  list->pop_back();
  cout << "List After: ";
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  cout << "front: " << list->front() << " back: " << list->back() << endl << endl;

  cout << "Case 2: Remove only value in tail, and delete node" << endl;
  list->push_back("7");
  list->push_back("8");
  cout << "List Before: "; 
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  list->pop_back();
  cout << "List After: ";
  printList(list);
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  cout << "front: " << list->front() << " back: " << list->back() << endl << endl;
  cout << endl;

  list->clear();
  delete list;


}

//testing every operation together
void everything()
{
  cout << endl;
  cout << "########## Testing everything ###########" << endl << endl;

  ULListStr* list = new ULListStr();


  cout << "Case 1: Push back 13-10 times and then 14-3; should have two nodes with 10 and 3 values respectively" << endl;
  for (int i = 0; i < 10; i++)
  {
    list->push_back("13");
  }
  for (int i = 0; i < 3; i++)
  {
    list->push_back("14");
  }
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;


  cout << "Case 2: Pop front 3 times; should leave 7 values in first node and 3 values in second node" << endl;
  for (int i = 0; i < 3; i++)
  {
    list->pop_front();
  } 
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 3: Push front 5 three times; should fill first node" << endl;
  for (int i = 0; i < 3; i++)
  {
    list->push_front("5");

  }
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 4: Push front 6 twice; should add new head node with 2 values" << endl;
  for (int i = 0; i < 2; i++)
  {
    list->push_front("6");

  } 
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 5: Pop back 3 times; should get rid of third node" << endl;
  for (int i = 0; i < 3; i++)
  {
    list->pop_back();

  }  
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 6: Pop back 3 times; should get rid of three back values in second node" << endl;
  for (int i = 0; i < 3; i++)
  {
    list->pop_back();

  }  
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;


  cout << "Case 7: Push back three 3s; should fill second node" << endl;
  for (int i = 0; i < 3; i++)
  {
    list->push_back("3");

  }  
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 8: Push back a 1; should create third node" << endl;
  list->push_back("1");
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 9: Pop front the first value; should not affect number of nodes" << endl;
  list->pop_front();
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  cout << "Case 10: Pop front the first value; should delete old head node" << endl;
  list->pop_front();
  cout << "size: " << list->size() << endl;
  cout << "nodes: " <<list->nodes() << endl;
  printList(list);
  cout << "front: " << list->front() << " back: " << list->back() << endl;
  cout << endl;

  list->clear();
  delete list;
}
