#include <assert.h>
#include "buffer_tools.h"

void buffer_tools::init(char* buff_to_init, int buffer_size, char init_with) {
    assert(buff_to_init != NULL && buffer_size > 0);
    for (int index = 0; index < buffer_size; index++) {
        buff_to_init[index] = init_with;
    }
}
