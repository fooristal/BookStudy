#include <stdio.h>

#ifdef FOOD
#include "hamburger.h"
#include "steak.h"
#endif

#include "cola.h"
#include "cider.h"

#include "desert.h"

int main()
{
	printf("This is main\n");
#ifdef FOOD
	hamburger();
	steak();
#endif	
	cola();
	cider();
	
	if (DESERT == 0) {
		printf("I don't want desert.\n");
	} else if (DESERT > 0) {
		printf("I want %d desert(s).\n", DESERT);
	}
}