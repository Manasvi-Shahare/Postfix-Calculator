#define MAX 1000000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OPERAND 100
#define OPERATOR 200
#define	END	300
#define ERROR	400
typedef struct token {
	int type;
	int number;
	char *val;
	char op;
}token;
enum states { SPC, DIG, OPR, STOP, ERR};
token *getnext(char *arr, int *i) {
	char p[MAX];
	static int currstate = SPC;
	if (*i == 0)
		currstate = SPC;
	int nextstate;
	int num;
	token *t = (token *)malloc(sizeof(token));
	t->val = (char *) malloc(512);
	while (1) {
		strcpy( p, arr);
		switch(arr[*i]) {
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9': case '.': 
			case '=': case 's': case 'S': case 'i':
			case 'I': case 'n': case 'N': case 'o':
			case 'O': case 'c': case 'C': case 'T':
			case 't': case 'a': case 'A':
				nextstate = DIG;
				break;
			case '+': case '-': case '*': case '/':
			case '%': case '!': case '^': case 'd':
			case 'D':
				nextstate = OPR;
				break;
			case '\0':
				nextstate = STOP;
				break;
			case ' ':
				nextstate = SPC;
				break;
			default:
				nextstate = ERR;
				break;
		}
		switch (currstate) {
			case SPC:
				if(nextstate == DIG){
					num = arr[*i] - '0';
					p[0] = arr[*i];
					p[1] = '\0';
					strcpy( t->val, p);
				}

				break;
			case DIG:
				if(nextstate == DIG){
					p[0] = arr[*i];
					p[1] = '\0';
					strcat( t->val, p);
					num = num * 10 + arr[*i] - '0';}
				else if(nextstate == OPR) {
					currstate = SPC;
					t->type = OPERAND;
					t->number = num;
					return t;
				}
				else  {
					t->type = OPERAND;
					t->number = num;
					currstate = nextstate;
					return t;
				}
				break;
			case OPR:
				t->type = OPERATOR;
				t->op = arr[*i - 1];	
				currstate = SPC;
				return t;
				break;
			case STOP:
				t->type = END;
				currstate = SPC;
				(*i)++;
				return t;
				break;
			case ERR:
				t->type = ERROR;
				currstate = nextstate;
				return t;
				break;
		}
		currstate = nextstate;
		(*i)++;
	}
}

