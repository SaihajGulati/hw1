#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  nodes_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   *  Cases:
   * has space
   * no space
   * is empty list
   */
  void ULListStr::push_back(const std::string& val)
  {
    //case if emtpy list, add to first index of new node
    if (empty())
    {
      head_ = new Item();
      head_->val[0] = val;
      tail_ = head_;
      nodes_++;
    }
    //case if no space, which is when the last number if the array size, have to make new node after tail
    else if(tail_->last == ARRSIZE)
    {
      Item* node = new Item();
      node->val[0] = val;
      tail_->next = node;
      node->prev = tail_;
      tail_ = node;
      nodes_++;
    }
    //otherwise there is space and can just put into array right after current last (remember last is exclusive)
    else
    {
      tail_->val[tail_->last] = val;
    }

    //increase the size of the overall list
    size_++;

    //increase the last index of the tail value, starts at 0 with new node
    tail_->last++;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   * Two cases:
   * just "zero-out" a value in the head array because there's multiple
   * if take out only value, deallocate that node
   */
  void ULListStr::pop_back()
  {
    size_t tailSize = tail_->last - tail_->first;
    //if tailSize > 1, then just make the last value in the array an empty string and move the last index
    if (tailSize > 1)
    {
      tail_->val[head_->last-1] = "";
      tail_->last--;
    }

    //otherwise the tail only has one value, and so removing it means we have to deallocate the tail pointer and make it point to the next one
    else
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
      nodes_--;
    }

    size_--;

  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   * Cases:
   * has space
   * no space
   * is empty list
   */
  void ULListStr::push_front(const std::string& val)
  {
    //case if emtpy list, add to last value of new node, and set first and last accordingly
    if (empty())
    {
      head_ = new Item();
      head_->val[ARRSIZE-1] = val;
      tail_ = head_;
      head_->first = ARRSIZE-1;
      head_->last = ARRSIZE;
      nodes_++;
    }
    //case if no space, which is when the last number if the array size, have to make new node before head
    else if(head_->first == 0)
    {
      Item* node = new Item();
      node->val[ARRSIZE-1] = val;
      head_->prev = node;
      node->next = head_;
      head_ = node;
      head_->first = ARRSIZE-1; 
      head_->last = ARRSIZE;
      nodes_++;
    }
    //otherwise there is space and can just put into array before value that is first currently
    else
    {
      head_->val[head_->first-1] = val;
      head_->first -= 1;
    }

    //increase the size of the overall list
    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   * Two cases:
   * just "zero-out" a value in the head array because there's multiple
   * if take out only value, deallocate that node
   */
  void ULListStr::pop_front()
  {
    size_t headSize = head_->last - head_->first;
    //if headsize > 1, then just make the first value in the array an empty string and move the first index
    if (headSize > 1)
    {
      head_->val[head_->first] = "";
      head_->first++;
    }

    //otherwise the head only has one value, and so removing it means we have to deallocate the head pointer and make it point to the next one
    else
    {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
      nodes_--;
    }

    size_--;

  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const
  {
    //return the last value of the last node, making sure to do -1 bc last is exclusive
    return tail_->val[tail_->last-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const
  {
    //return the first value of the first node
    return head_->val[head_->first];
  }

  /**
   * function I added for testing purposes, writeup said could add member functions/variables
   */
  size_t ULListStr::nodes() const
  {
    return nodes_;
  }
