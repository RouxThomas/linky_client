
#ifndef CHECKER_BOOL_H_
#define CHECKER_BOOL_H_

#include "checker.h"
#include "test_reporter.h"
#include "bool_to_string.h"

class checker_bool : public checker {
   public:

      checker_bool(bool_to_string* bool_to_str, test_reporter* test_report, bool isVerbose);
      // PRE  : not null test_report
      // POST : N/A

      void bool_are_equals(bool a, bool b, char* msg);
      // PRE  : not null msg
      // POST : if the test is KO, the log is written via test_reporter

   private :

      bool_to_string* bool_to_str;
      bool compare(void* a, void* b);
      void to_string(char* destination , void* a);
}; 

#endif
