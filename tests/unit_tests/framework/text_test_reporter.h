#ifndef TEXTTESTREPORTER_H_
#define TEXTTESTREPORTER_H_

#include "test_reporter.h"

class text_test_reporter: public test_reporter {
public:

	void start(char* testName);

	void end(char* testName);

	void log(char* msg);

	void addFailure (char* msg);

};

#endif
