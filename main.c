#define MAX 1000000
#define pi 3.14159265
#define PI 3.142857142857
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
#include "stack.h"
#include "function.h"
#include "token.h"
int main() {
	char str[MAX], *ps1, *ps2;
	char *cc, *tmp, *pow, *d;
	int x, ans;
	int i = 0;
	token *t;
	strstack s;
	charstack c;
	sinit (&s);
	cinit (&c);
	x = 1;
	while (1) {
		x = readline(str, 10000);
		if(x == 0) 
			break;
		i = checkstr(str);
		if(i == 0)
			continue;
		i = 0;
		while(1){	
			t = getnext( str, &i);
			if(t->type == ERROR){
				printf(" error in expression\n");
				break;
			}
			if(t->type == OPERAND) {
				cc = (char *)malloc(MAX);
				if(( t->val[0] == 's' || t->val[0] == 'S') && (t->val[1] == 'i' || t->val[1] == 'I') &&( t->val[2] == 'n' || t->val[2] == 'N')){
					//sin
					x = 0;
					while(1){
						t = getnext(str, &i);
						if(t->type == END)
							goto End;
						if( t->op == '-')
						 	x = 1;
						if(t->val[0] >= '0' && t->val[0] <= '9' ){
							long g = atol(t->val);
							if(x == 1)
								g = g * (-1);	
							printf("%lf\n", sin((g * PI / 180)));
							goto End;
						}
					}	
				}
				else if( (t->val[0] == 'c' || t->val[0] == 'C') && (t->val[1] == 'o' || t->val[1] == 'O') && ( t->val[2] == 's' || t->val[2] == 'S')){
					//cos
					x = 0;
					while(1){
						t = getnext(str, &i);
						if(t->type == END)
							goto End;
						if( t->op == '-')
						 	x = 1;
						if(t->val[0] >= '0' && t->val[0] <= '9' ){
							long g = atol(t->val);
							if(x == 1)
								g = g * (- 1);
							printf("%lf\n", cos((g * PI / 180)));
							goto End;
						}
					}
				}
				else if((t->val[0] == 't'|| t->val[0] == 'T') && (t->val[1] == 'a' || t->val[1] == 'A') && ( t->val[2] == 'n'|| t->val[2] == 'N')){
					//tan
					x = 0;
					while(1){
						t = getnext(str, &i);
						if(t->type == END)
							goto End;
						if( t->op == '-')
						 	x = 1;
						if(t->val[0] >= '0' && t->val[0] <= '9' ){
							long g = atol(t->val);
							if(x == 1)
								g = g * (-1);
							if( g % 90 == 0 && g% 180 != 0){
								printf("NOT DEFINED\n");
								goto End;
							}
							printf("%lf\n", tan((g * PI / 180)));
							goto End;
						}
					}
				}			
				spush(&s, t->val);
			}
			if(t->type == OPERATOR){
				ps1 = spop (&s);			
				ps2 = spop (&s);
				switch( t->op ){
					case '+':
						//addition
						ps2 = add( ps2, ps1);
						spush(&s, ps2);
						break;
					case '-':
						//subtraction
						if(strlen( ps1 ) > strlen(ps2) ){
							cc = (char *)malloc(MAX);
						}
						else {
							cc = (char *)malloc( MAX );
						}
						cc = sub(ps2, ps1);
						if(atoi(cc) != 0) 
							removezero(cc);
						spush( &s, cc);
						break;
					case '*':
						//multiplication
						cc = (char *)malloc(MAX);
						multiply( ps1, ps2, cc);
						tmp = (char *)malloc(strlen(cc) +3);
						strcpy(tmp , cc);
						free( cc );
						spush (&s,tmp);
						break;
					case '%':
						//modulo
						cc = (char *)malloc( MAX);
						d = (char *)malloc(strlen( ps1 ) + strlen( ps2 ));
						d = modulo( ps2, ps1, cc, d);
						spush( &s, d);
						free (cc);
						break;
					case '/':
						//division
						cc = (char *)malloc( MAX );
						d = (char *)malloc( strlen( ps1 ) + strlen( ps2 ));
						division( ps2, ps1, cc, d);
						spush( &s, cc);
						break;
					case '^':
						//power
						pow = (char *)malloc(MAX);
						d = (char *)malloc(MAX);
						strcpy( d, ps2);
						strcpy(pow,power( d, ps1, pow));
						cc = (char *)malloc( strlen(pow) + 3);
						strcpy(cc, pow);
						free( pow );
						free( d );
						spush( &s, cc);
						break;
					case 'd': case 'D':
						exit(1);
				}
			}
			if(t->type == END){
				ps2 = spop(&s);
				ans = strlen (ps2);
				if(s.i >= 1){
					printf("error\n");
					sinit(&s);
					break;
				}
				printf("%s\n",ps2);
				break;
			}
		}
		End:
			continue;
	}
}
