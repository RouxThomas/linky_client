
#ifndef CHECKER_INT_H_
#define CHECKER_INT_H_

#include "checker.h"
#include "test_reporter.h"
#include "int_to_string.h"

class checker_int : public checker {
   public:

      checker_int(int_to_string* int_to_str, test_reporter* test_report, bool isVerbose);
      // PRE  : not null test_report
      // POST : N/A

      void int_are_equals(int a, int b, char* msg);
      // PRE  : not null msg
      // POST : if the test is KO, the log is written via test_reporter

   private :

      int_to_string* int_to_str;
      bool compare(void* a, void* b);
      void to_string(char* destination , void* a);
}; 

#endif
