#ifndef SRC_JSON_JSONABLE_H_
#define SRC_JSON_JSONABLE_H_

class jsonable {
public:
    virtual ~jsonable() {
    }
    ;

    virtual void to_json(char* destination, unsigned int indent_offset) = 0;
};

#endif /* SRC_JSON_JSONABLE_H_ */
