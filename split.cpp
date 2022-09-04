/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.

- input: input linked list, odds head and evens head
- output: none, just odds and evens list created and head pointing to correct place, with in to NULL
- Requirements: 
---- must not leak memory (use valgrind)
---- change pointers, not delete or new nodes
- Algo (thinking of): 
helper function? Definitely need to split somehow to which list is added to
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void helper(Node*& in, Node*& odds, Node*& evens, Node*& evensPrev, Node*& oddsPrev, Node*& evensHead, Node*& oddsHead);

//*& means reference to a pointer
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE

  //initialize these to null since no previous yet
  Node* evensPrev = nullptr;
  Node* oddsPrev = nullptr;
  Node* evensHead = nullptr;
  Node* oddsHead = nullptr;

  

  helper(in, odds, evens, evensPrev, oddsPrev, evensHead, oddsHead);
  odds = oddsHead;
  evens = evensHead;

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE
//need a helper function because need the previous node of each to connect to new one we add 
void helper(Node*& in, Node*& odds, Node*& evens, Node*& evensPrev, Node*& oddsPrev, Node*& evensHead, Node*& oddsHead)
{
  //base case is when list node is null, don't just return but also make sure that last value is nulled out
  if (in == nullptr)
  {
    if (evensPrev) evensPrev->next = nullptr;
    if(oddsPrev)oddsPrev->next = nullptr;
    return;
  }

  //when make evens in, we get the previous one regardless of if was even or not
  if (in->value % 2 == 0)
  {
    //makes evens pointer point to what in pointed to, so value that was in in and what in pointed to next
    evens = in;

    //next of the previous in evens now points to object that was added to evens, but check it isn't null
    //if it is null, then is first value in evens and so set as head for later
    if (evensPrev)
    {
      evensPrev->next = evens;
    }
    else
    {
      evensHead = evens;
    }

    //shift the previous of evens for the next call to the new evens value, but check it isn't null
    evensPrev = evens;
  }
  else
  {
    odds = in;
    
    if (oddsPrev)
    {
      oddsPrev->next = odds;
    }
    else
    {
      oddsHead = odds;
    }

    oddsPrev = odds;
  }
  
  //no memory leak because odds or evens from above point to what in used to, and now in points to the next one, all the way until first in points to null, while the rest are reassigned
  in = in->next;

  //calls helper again with new head of overall linked list, the next in the evens 
  helper(in, odds, evens, evensPrev, oddsPrev, evensHead, oddsHead);

  
}