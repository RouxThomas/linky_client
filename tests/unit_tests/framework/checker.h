
#ifndef CHECKER_H_
#define CHECKER_H_

#include "test_reporter.h"

#define MAX_MSG_SIZE_IN_BYTES 500

class checker{
   public:

      checker(test_reporter* test_report, bool is_verbose);
      // PRE  : not null test_report
      // POST : N/A

      virtual ~checker() {};

      virtual bool compare(void* a, void* b) = 0;
      virtual void to_string(char* destination , void* a) = 0;

   protected:

      void are_equals(void* expected,
			   	      void* computed,
			          char* msg);

      void msg_formatter(void* a,
			   	   	   void* b,
					   char* msg);

      bool is_verbose;
      char to_string_buffer[MAX_MSG_SIZE_IN_BYTES/2];
      char global_buffer[MAX_MSG_SIZE_IN_BYTES];
      test_reporter* test_report;
}; 


#endif
