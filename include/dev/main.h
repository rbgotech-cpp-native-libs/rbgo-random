#pragma once
#ifdef RBGORANDOM_DEVMAIN
#include <rbgo-random.h>


namespace rbgo {

class Rnd32 {

	Tu32 uA;
	Tu32 uZ;
	Tu32 length;
	Tu32 *array;
	Tu32 count;
public:
	Rnd32(Tu32 uA, Tu32 uZ, Tu32 mul);
	~Rnd32();
	void generate();
private:
	void print();
	void reset();
};

}//ns
#endif//RBGORANDOM_DEVMAIN
