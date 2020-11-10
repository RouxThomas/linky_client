
#ifndef CHECKER_STR_H_
#define CHECKER_STR_H_

#include "checker.h"
#include "test_reporter.h"

class checker_str : public checker {
   public:

      checker_str(test_reporter* test_report, bool isVerbose);
      // PRE  : not null test_report
      // POST : N/A

      void str_are_equals(char* a, char* b, char* msg);
      // PRE  : not null msg
      // POST : if the test is KO, the log is written via test_reporter

   private :

      bool compare(void* a, void* b);
      void to_string(char* destination , void* a);
}; 

#endif
