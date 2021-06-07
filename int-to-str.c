#include <stdio.h>
#include <stdlib.h>

typedef unsigned int DWORD;

DWORD int_digits_count(DWORD val){
	DWORD d = 10, dc = 0;
	while(d){
		dc++;
		if(val % d == val) break;
		d *= 10;
	}
	return dc;
}

char *itos(DWORD val){
	DWORD digit_count = int_digits_count(val), md;
	char *p = calloc(digit_count, sizeof(char));
	while(val > 0){
		md = val % 10;
		p[--digit_count] = md + 0x30;
		val = (val - md) / 10;
	}
	return p;
}
