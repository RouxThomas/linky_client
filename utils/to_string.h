#ifndef UTILS_TO_STRING_H_
#define UTILS_TO_STRING_H_

class to_string {
public:
  virtual void to_str(char* destination, void* elem) = 0;
  virtual void type(char* destination) = 0;
};

#endif /* UTILS_TO_STRING_H_ */
