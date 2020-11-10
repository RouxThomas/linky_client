#ifndef TESTREPORTER_H_
#define TESTREPORTER_H_

class test_reporter {
public:

	virtual ~test_reporter() {};

	virtual void start (char* testName)=0;
	// PRE  : N/A
	// POST : N/A

	virtual void end (char* testName)=0;
	// PRE  : N/A
	// POST : N/A

	virtual void log (char* testName)=0;
	// PRE  : N/A
	// POST : N/A

	virtual void addFailure (char* msg)=0;
	// PRE  : N/A
	// POST : N/A

};
#endif
