#ifndef UTILS_MEMORY_SERIAL_H_
#define UTILS_MEMORY_SERIAL_H_

class utils_memory_serial {
   public:
    static void init(unsigned long serial_speed);
	static void printFreeMemory(char* msg);

};

#endif /* UTILS_MEMORY_SERIAL_H_ */
