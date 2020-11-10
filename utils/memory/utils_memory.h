#ifndef UTILS_MEMORY_H_
#define UTILS_MEMORY_H_

class utils_memory {
   public:
	static int freeRamInByte ();
   private:
	static int freeListSize();
};

#endif /* UTILS_MEMORY_H_ */
