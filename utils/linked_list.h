
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


class linked_list {
   public:
      linked_list();

      unsigned int nb_elem();
      // PRE  : N/A
      // POST  : current number of elements in list

      void append(void* elem);
      // PRE  : not null elem
      // POST  : elem is appended to the end of list

      void* get(unsigned int index);
      // PRE  : index in 1 .. nb_elem.
      // POST  : a not NULL element is returned.

      void insert_before(unsigned int index, void* elem);
      // PRE  : index start at 1, not null elem, index in 1..nb_elem
      // POST : elem si inserted at index

      void remove(unsigned int index);
      // PRE  : index in 1..size of list
      // POST  : elem is removed

   private:

      struct Node {
         void* elem;
         Node* next;
      };

      linked_list::Node* getNode(unsigned int index);
      Node* first_node;
}; 

#endif
