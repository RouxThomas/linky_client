#include <stdio.h>
#include "text_test_reporter.h"

static void flush(void) {
	fflush (stdout);
	fflush (stderr);
}

void text_test_reporter::start(char* testName) {
	flush();
	printf("start test : %s...", testName);
}

void text_test_reporter::end(__attribute__((unused)) char* testName) {
	flush();
	printf("end\n");
}

void text_test_reporter::log(char* msg) {
	flush();
	printf("%s\n", msg);
}

void text_test_reporter::addFailure(char* msg) {
	flush();
	printf("!!! test ko !!!, %s\n", msg);
}
