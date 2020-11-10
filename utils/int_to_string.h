#ifndef UTILS_INT_TO_STRING_H_
#define UTILS_INT_TO_STRING_H_

#include "to_string.h"

class int_to_string: public to_string {
public:
	void to_str(char* destination, void* elem);
	void type(char* destination);
};

#endif
