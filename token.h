#define OPERAND 100 
#define OPERATOR 200
#define	END	300
#define ERROR	400
typedef struct token {
	int type; /*type can be operator, operand, error, spc */
	int number;//used when type is operand
	char *val;
	char op;// used when type is operator
}token;
token *getnext(char *arr, int *i);
