#ifdef RBGORANDOM_DEVMAIN
#include <stdlib.h>//system, exit, atoi
#include <stdio.h>//puts, printf, scanf

#include <rbgo-random.h>
#include <rbgo-time.h>
#include <dev/main.h>


#define MENU_LENGTH 7
const char* menuStrings[MENU_LENGTH] = {
	"0	quit",
	"1	menu",
	"2	clear screen",

	"3	rnd32(50,75) range1000x: ",
	"4	rnd32(675,925) range750x: ",
	"5	rnd32(800,1200) range500x: ",
	"6	rnd32(7500,8499) range1000x: "
};

int main(){

	setbuf(stdout, NULL);

	rbgo::Sw64 *sw = new rbgo::Sw64();
	char input[16] = {0};
	rbgo::Tu32 mc=1;

	//____VARIABLES____
	rbgo::Tu32 i, ru, *array;
	rbgo::Rnd32 *rr;

	while(1){

		sw->start();

		switch(mc){
		case 0: exit(0); break;
		case 1: mc=0; while(mc < MENU_LENGTH) puts(menuStrings[mc++]); break;
		case 2: system("cls | clear"); break;

//Test cases...
		case 3:
			rr = new rbgo::Rnd32(50, 75, 1000);
			rr->generate();
			delete rr;
		break;
		case 4:
			rr = new rbgo::Rnd32(675, 925, 750);
			rr->generate();
			delete rr;
		break;
		case 5:
			rr = new rbgo::Rnd32(800, 1200, 500);
			rr->generate();
			delete rr;
		break;
		case 6:
			rr = new rbgo::Rnd32(7500, 8499, 1000);
			rr->generate();
			delete rr;
		break;
		}
		
		if(2 < mc && mc < MENU_LENGTH)
			sw->stopp(menuStrings[mc], "s\n");

		printf("choice: ");
		scanf("%2s", input);
		mc = atoi(input);
	}
}

#endif//RBGORANDOM_DEVMAIN
