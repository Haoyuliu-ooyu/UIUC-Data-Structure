/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    length_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode * temp;
  while (head_) {
    temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if (length_ == 0) {
    head_ = newNode;
    tail_ = newNode;
  } else {
    head_ -> prev = newNode;
    newNode -> next = head_;
    head_ = newNode;
  }

  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if (length_ == 0) {
    head_ = newNode;
    tail_ = newNode;
  } else {
    tail_ -> next = newNode;
    newNode -> prev = tail_;
    tail_ = newNode;
  }
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  if (length_ == 0) {
    return NULL;
  } else if (splitPoint == 0) {
    return start;
  }

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
      return curr;
  }

  return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  ListNode* currt_ = head_;
  for (int i = 0; i + 2 < length_ && currt_ != NULL; i += 3) {
    if (i == 0) {
      head_ = head_->next;
    }
    ListNode* prevvvv = currt_->prev;
    ListNode* node3 = currt_->next->next;
    ListNode* node2 = currt_->next;
    ListNode* node3_next = node3->next;
    node2->prev = prevvvv;
    node3->next = currt_;
    currt_->prev = node3;
    currt_->next = node3_next;
    if (node3_next != NULL) {
      node3_next->prev = currt_;
    }
    if (prevvvv != NULL) {
      prevvvv->next = node2;
    }
    if (i+2==length_-1) {
      tail_ = currt_;
    }
    currt_ = currt_->next;
  }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  if (startPoint == endPoint || startPoint == NULL || endPoint == NULL) {
    return;
  }
  ListNode* curr = startPoint;
  ListNode* endnext = endPoint->next;
  ListNode* startprev = startPoint->prev;
  while (curr != endnext && curr != NULL) {
    ListNode* next___ = curr->next;
    curr->next = curr->prev;
    curr->prev = next___;
    curr = next___;
  }
  
  ListNode* temp = startPoint;
  startPoint = endPoint;
  endPoint = temp;
  endPoint -> next = endnext;
  if (endnext != NULL) {
    endnext -> prev = endPoint;
  }
  startPoint -> prev = startprev;
  if (startprev != NULL) {
    startprev -> next = startPoint;
  }

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  ListNode* end = head_;
  if (length_ <= 1 || n <= 1) {
    return;
  }
  if (n >= length_) {
    reverse();
  }
  ListNode* curr = head_;
  ListNode* _head_ = head_;
  ListNode* _tail_ = head_;
  int num = 0;
  while (curr != NULL) {
    if (num == n) {
      reverse(_head_, _tail_);
      if (head_ == _tail_) {
        head_ = _head_;
      } else if (tail_ == _head_) {
        tail_ = _tail_;
        tail_->next = NULL;
      }
      num = 0;
      _head_ = curr;
      _tail_ = curr;
    }
    if (curr->next == NULL) {
      reverse(_head_, curr);
      curr->next = NULL;
      tail_ = curr;
    }
    _tail_ = curr;
    curr = curr->next;
    num++;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == NULL) {
    return second;
  } else if (second == NULL) {
    return first;
  }
  ListNode* new_head;
  ListNode* first_curr = first;
  ListNode* second_curr = second;
  if (first_curr->data < second_curr->data) {
    new_head = first_curr;
    first_curr = first_curr->next;
  } else {
    new_head = second_curr;
    second_curr = second_curr->next;
  }
  ListNode* curr = new_head;
  while (first_curr != NULL && second_curr != NULL) {
    if (first_curr->data < second_curr->data) {
      first_curr->prev = curr;
      curr->next = first_curr;
      first_curr = first_curr->next;
    } else {
      second_curr->prev = curr;
      curr->next = second_curr;
      second_curr = second_curr->next;
    }
    curr = curr->next;
  }
  if (first_curr == NULL) {
    curr->next = second_curr;
  } else  {
    curr->next = first_curr;
  }
  return new_head;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (chainLength <= 1) {
    return start;;
  }
  ListNode* right = split(start, chainLength/2);
  right = mergesort(right, chainLength/2  + chainLength%2);
  start = mergesort(start, chainLength/2);
  return merge(start, right);
}