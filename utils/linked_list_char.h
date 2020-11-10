
#ifndef LINKEDLISTCHAR_H_
#define LINKEDLISTCHAR_H_

#include "linked_list.h"

class linked_list_char {
   public:
	  linked_list_char();

      unsigned int nb_elem();
      // PRE  : N/A
      // POST  : current number of elements in list

      void append(char* elem);
      // PRE  : not null elem
      // POST  : elem is appended to the end of list

      char* get(unsigned int index);
      // PRE  : index in 1 .. nb_elem.
      // POST  : a not NULL element is returned.

      void insert_before(unsigned int index, char* elem);
      // PRE  : index start at 1, not null elem, index in 1..nb_elem
      // POST : elem si inserted at index

      void remove(unsigned int index);
      // PRE  : index in 1..size of list
      // POST  : elem is removed

   private:
      linked_list * list;

}; 

#endif
