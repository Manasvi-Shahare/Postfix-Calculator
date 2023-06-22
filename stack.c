#include "stack.h"
#include <stdlib.h>
#include<string.h>
#define MAX 1000000  
void sinit(strstack *s) {
	s->i = 0;
}
void spush(strstack *s, char num[]) {
	s->a[s->i] = (char *)malloc(strlen(num) +1);
	strcpy(s->a[s->i], num);
	(s->i)++;
}
char *spop(strstack *s) {
	(s->i)--;
	return s->a[s->i];
}
int sempty(strstack *s) {
	return s->i == 0;
}
int sfull(strstack *s) {
	return s->i == MAX;
}


void cinit(charstack *s) {
	s->j = 0;
}
void cpush(charstack *s, char num) {
	s->c[s->j]= num;
	(s->j)++;
}
int cpop(charstack *s) {
	(s->j)--;
	return s->c[s->j];
}
int cempty(charstack *s) {
	return s->j == 0;
}
int cfull(charstack *s) {
	return s->j == MAX;
}
char ctop(charstack *cs) {
	char x = cpop(cs);
	cpush(cs, x);
	return x;
}
