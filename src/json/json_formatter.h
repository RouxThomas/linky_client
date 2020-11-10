
#ifndef SRC_JSON_JSON_FORMATTER_H_
#define SRC_JSON_JSON_FORMATTER_H_

class json_formatter {
public:
  char* to_json(char* destination, unsigned int indent_offset) = 0;
};

#endif /* SRC_JSON_JSON_FORMATTER_H_ */
