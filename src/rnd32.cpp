#include	<stdlib.h>//rand, srand

#include	<rbgo-random.h>
#include	<rbgo-time.h>

namespace rbgo {

#if RTD_Ti8 && RTD_Ti32
Tu32 rnd32(Tu32 mn, Tu32 mx){

	static Tu8 s = 0;
	//re-seed every 16th call
	if(!(s++ % 16)) srand(tsc_ns_u32());
	
	Tu32 gen;
	Tu8 b0, b1, b2, b3;
	//Generate 0...4,294,967,295
	b0 = (Tu8)rand();
	b1 = (Tu8)rand();
	b2 = (Tu8)rand();
	b3 = (Tu8)rand();
	gen = b3 << 24 | b2 << 16 | b1 << 8 | b0;

	return gen % (mx - mn + 1) + mn;
}
#endif

}//ns
