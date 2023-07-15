#ifdef RBGORANDOM_DEVMAIN
#include <dev/main.h>
#include <stdio.h>

namespace rbgo {

Rnd32::Rnd32(Tu32 _uA, Tu32 _uZ, Tu32 _mul){

	uA = _uA;
	uZ = _uZ;
	length = uZ - uA + 1;
	array = new Tu32[length];

	count = length * _mul;
}

Rnd32::~Rnd32(){

	delete array;
}

void Rnd32::generate(){

	Tu32 i, ru, index;

	reset();

	i = 0;
	while(i < count){
		ru = rbgo::rnd32(uA, uZ);
		index = ru - uA;
		array[index]++;
		i++;
	}

	print();
}

void Rnd32::print(){

	Tu32 occur, ru, index;

	printf("Generate: %u numbers within range(%u,%u)\n", count, uA, uZ);

	index = 0;
	while(index < length){
		occur = array[index];
		ru = index + uA;
		printf("%10u=%-10u ", ru, occur);
		if(!(index % 5)) puts("");
		index++;
	}
	puts("");
}

void Rnd32::reset(){

	Tu32 i = 0;
	while(i < length)
		array[i++] = 0;
}

}//ns

#endif//RBGORANDOM_DEVMAIN
