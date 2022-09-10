#ifndef ULLISTSTR_H
#define ULLISTSTR_H
#include <string>

#define ARRSIZE 10
class ULListStr {
 public:
  struct Item {
    std::string val[ARRSIZE];
    /**
     * first and last indicate the occupied/used 
     * elements of the array where first is an
     * inclusive index and last is an exclusive
     * index (i.e. first=0, last=0 indicates none
     * of the elements of the array are used and
     * first=0, last=ARRSIZE indicates the array
     * is fully occupied
     */
    size_t first, last;
    Item *prev;
    Item *next;

    /**
     * Default constructor
     */
    Item(){
      first = last = 0;
      prev = next = NULL;
    }
  };

  /**
   * Default constructor - empty list
   */
  ULListStr();

  /**
   * Destructor
   */
  ~ULListStr();

  /**
   * Returns the current number of items in the list 
   *   - MUST RUN in O(1)
   */
  size_t size() const;

  /**
   * Returns true if the list is empty, false otherwise
   *   - MUST RUN in O(1)
   */
  bool empty() const;

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void push_back(const std::string& val);

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void pop_back();
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void push_front(const std::string& val);

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void pop_front();
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & back() const;

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & front() const;
  
  /**
   * Overwrites the old value at index, pos, with val
   *   - Can run in O(n)
   */
  void set(size_t pos, const std::string& val);

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
  std::string& get(size_t pos);

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
  std::string const & get(size_t pos) const;

  /**
   * Deletes all items in the list
   */
  void clear();

  /**
   * function I added for testing purposes
   */
  size_t nodes() const;

 private:
  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* getValAtLoc(size_t loc) const
  {
    //if the location is invalid
    if (loc >= size())
    {
      return nullptr;
    }

    //go through each item in linked list and check until get to location
    Item* curr = head_;

    //counter for what index we're at
    size_t count = 0;

    //iterate while count is less than or equal to size-1, because that way only checks if is valid
    while (count < size())
    {
      //if the location int is less than the last index in this node, step in and get value
      if (loc < (count + curr->last - curr->first))
      {
        return &(curr->val[curr->first+(loc-count)]);
      }
      else //move on to next node and next indexes
      {
        count += (curr->last - curr->first);
        curr = curr->next;        
      }
    }
    return nullptr;
    
  }


  /**
   * Data members
   *  You MUST keep these members though you
   *  may add more if desired.
   */
  Item* head_;
  Item* tail_;
  size_t size_;
  //added for testing purposes
  size_t nodes_;

};

#endif
