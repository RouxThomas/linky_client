
#ifndef RUNNABLE_H_
#define RUNNABLE_H_

#ifdef __cplusplus
extern "C" {
#endif

class runnable {
      public:
      virtual void run() = 0;
      // PRE  : N/A
      // POST  : N/A
}; 

#ifdef __cplusplus
}
#endif


#endif