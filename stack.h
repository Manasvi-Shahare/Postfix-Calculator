typedef struct strstack {
	char *a[10000];
	int i;
}strstack;
void sinit(strstack *s);
void spush(strstack *s, char num[]);
char *spop(strstack *s);
int sempty(strstack *s);
int sfull(strstack *s);

typedef struct charstack {
	char c[10000];
	int j;
}charstack;
void cinit(charstack *s);
void cpush(charstack *s, char num);
int cpop(charstack *s);
int cempty(charstack *s);
int cfull(charstack *s);
