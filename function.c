/*This program is coded by MANASVI SHAHARE.It is a basic precision calculator containing addition, subtraction, multiplication, division, modulo and trignometric functions and also power function.*/
#include <stdio.h>
#include "function.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "token.h"
#define MAX 1000000
int ii = 0, iii = 0, scale = 0;
int readline(char *arr, int len) {
	int i = 0;
	int ch;
	while((ch = getchar()) != '\n' && i < MAX - 1) {
		arr[i] = ch;
		i++;
	}
	arr[i] = '\0';
	return i;
}
char *sub(char *a, char *b) {
	int diff, carry = 0, i = 0 , j, k=0, len1, len2, p , q, len3, sign = 0, x=0;
	char *str,temp[10000];
	len1 = strlen(a);
	len2 = strlen(b);
	if(len1 >= len2) {
		str = (char *)malloc(len1 + 2);
	}
	else {
		str = (char *)malloc(len2 + 2);
	}
	if((strcmp(a, "0")) == 0 && (strcmp(b, "0") != 0)) {
		strcpy(str, "-");
		strcat(str, b);
		return str;
	}
	if((strcmp(a, "0")) != 0 && (strcmp(b, "0") == 0)) {
		strcpy(str, a);
		return str;
	}
	if(compare(a, b) == 2) {
		str[0] = 0 + '0';
		str[1] = '\0';
		return str;
	}
	if((len1 == 1) && (len2 == 1)) {
		p = a[i] - '0';
		q = b[i] - '0';
		if(p >= q) {
			diff = p - q;
			str[0] = diff + '0';
			str[1] = '\0';
			return str;
		}
		else {
			diff = q - p;
			str[0] = '-';
			str[1] = diff + '0';
			str[2] = '\0';
		}	
		return str;
	}	
	else {	
		if(len2 < len1) {
			i = len1 - 1;
			for(j = (len2 - 1); j >= 0  ; j--) {
				b[i] = b[j];
				i--;
			}
			for(j = i; j >= 0; j--) {
				b[j] = '0';
			}
			b[len1] = '\0';
		}
		if(len1 < len2) {
			i = len2 - 1;
			for(j = (len1 - 1); j >= 0  ; j--) {
				a[i] = a[j];
				i--;
			}
			for(j = i; j >= 0; j--) {
				a[j] = '0';
			}
			a[len2] = '\0';
		}	 
		if((strcmp(a,b)) < 0) {
			strcpy(temp, a);
			strcpy(a, b);
			strcpy(b, temp);
			len3 = len1;
			len1 = len2;
			len2 = len3;
			sign = 1;
		}
		for(i = (len1 - 1), j = (len2 - 1); ; i--, j--) {
			if(a[i] == '.') {
				i--;
			}	
			if(b[j] == '.') {
				j--;
			}	
			p = a[i] - '0';
			q = b[i] - '0';	
			if(i < 0 && j < 0) {
				break;
			}
			if(i < 0) {
				p = 0;
			}	
			if(j < 0) {
				q = 0;
			}
			diff = p - q - carry;
			if(diff < 0) {
				str[k] = (diff + 10) + '0';
				carry = 1;
				diff = 0;
				k++;
			}
			else {
				str[k] = diff + '0';
				carry = 0;
				diff = 0;
				k++;
			}
		}	
		for(x = (k - 1) , i = 0; i <= k; x--, i++) {
			a[i] = str[x];
		}
		if(sign == 1) {
			for(j = i; j >= 0; j--) {
				a[j] = a[j-1];
			}
			a[0] = '-';
		}
		a[i] = '\0';
		return a;
	}
}
char *add(char *a, char *b) {
	int sum, carry = 0, i = 0 , j, k=0, len1, len2, p , q, x=0, len3, k1;
	char *str;
	len1 = strlen(a);
	len2 = strlen(b);
	if(len1 > len2) {
		str = (char *)malloc(len1 + 2);
	}
	else {
		str = (char *)malloc(len2 + 2);
	}
	if((len1 == 1) && (len2 == 1)) {
		sum = (a[i] - '0') + (b[i] - '0');
		if(sum <= 9) {
			str[0] = sum + '0';
			str[1] = '\0';
		}
		else {
			str[0] = (sum / 10) + '0';
			str[1] = (sum % 10) + '0';
			str[2] = '\0';
		}
		return str;
	}
	else {
		for(i = (len1 - 1), j = (len2 - 1); ; i--, j--) {
			if(a[i] == '.') {
				i--;
			}	
			if(b[j] == '.') {
				j--;
			}
			p = a[i] - '0';
			q = b[j] - '0';
			if(i < 0 && j < 0) {
				break;
			}
			if(i < 0) {
				p = 0;
			}	
			if(j < 0) {
				q = 0;
			}
			sum = p + q + carry;
			str[k] = (sum % 10) + '0';
			carry = sum / 10;
			k++;	
		}
		for(x = (k - 1), i = 0; i <= k; x--, i++) {
			a[i] = str[x]; 
		}
		a[i] = '\0';
		if(carry == 1) {
			len3 = strlen(a);
			k1 = len3;
			while(len3 != 0) {
				a[len3] = a[len3-1];
				len3--;
			}
			a[0] = carry + '0';
			a[k1 + 1] = '\0';
		}
		return a;
	}	
}
int checkstr(char str[]){
	int i = 0, j = 0;
	token *t;
	t = getnext( str, &i);
	if( t->type == OPERATOR){
		if(t->op == 'd' || t->op == 'D'){
			return 1;
		}
		printf("STANDARD INPUT : POSTFIX only\n");
		return 0;
	}
	if(t->val[0] >='0' && t->val[0] <= '9'){
		j = 1;
	}
	t = getnext( str, &i);
	if(t->type == OPERATOR ) {
		if( j == 1){
			if(t->op != '!'){
				printf("STANDARD INPUT : POSTFIX only\n");
				return 0;
			}
			return 1;
		}
		return 1;
	}
	t = getnext( str, &i);
	if( t->type == OPERATOR){
		return 1;
	}
}
void multiply(char a[], char b[], char res[]) {
	int i, j, k = 0, p = 0, q, r = 0, l1, l2;
	long sum = 0;
	char *c = (char *)malloc( MAX );
	char *tmp = (char *)malloc( MAX );
	char * c1, *c2;
	c1 = (char *)malloc(strlen ( a ) + 2);
	c2 = (char *)malloc(strlen ( b ) + 2);
	l1 = strlen(a) - 1;
	l2 = strlen(b) - 1;
	if((strcmp(a, "0") == 0) || (strcmp(b, "0") == 0)) {
		strcpy(res, "0");
		return;
	}
	for(i = 0; i <= l1; i++){
		c1[i] = a[i] - 48;
	}
	for(i = 0; i <= l2; i++) {
		c2[i] = b[i] - 48;
	}
	for(i = l2; i >= 0; i--){
		r = 0;
		for(j = l1; j >= 0; j--){
				tmp[k++] = (c2[i] * c1[j] + r) % 10;
				r = (c2[i] * c1[j] + r) / 10;
		}
		tmp[k++] = r;
		p++;
		for(q = 0; q < p; q++ ) {
			tmp[k++] = 0;
		}
	}
	k = 0;
	r = 0;
	for( i = 0 ; i < l1 + l2 + 2; i++){
		sum = 0;
		q = 0;
		for(j = 1; j <= l2 + 1; j++){
			if(i <= l1 + j){
				sum = sum + tmp[q + i];
			}
			q += j + l1 + 1;
		}
		c[k++] = (sum + r) % 10;
		r = (sum + r)/10;
	}
	c[k] = r;
	j = 0;
	for(i = k - 1; i >= 0; i--){
		res[j++] = c[i] + 48;
	}
	res[j] = '\0';
	free( c );
	free( tmp );
	free( c1 );
	free( c2 );
	removezero(res);
	return;
}
int compare(char a[],char b[]){
	removezero (a);
	removezero (b);
	int i, j;
	i = strlen(a);
	j = strlen(b);
	if(i > j){
		return 1;
	}
	if(i < j){
		return -1;
	}
	if( i == j ){
		i = strcmp(a, b);
		if( i == 0)
			return 2;
		if( i < 0 )
			return -1;
		if( i > 0 )
			return 1;
	}
	
}
void removezero(char a[]){
	int i = 0;
	int l;
	l = strlen(a);
	while(a[0] == '0'){
		l = strlen(a);
		while(i < l){
			a[i] = a[i+1];
			i++;
		}
		i = 0;
	}
	return;
}
void division(char *a, char *b, char *e, char *a2) {
	char *b2 = (char *)malloc(MAX);
	char *c = (char *)malloc(strlen(b) + 3);
	char *c1 = (char *)malloc(strlen(b));
	int f[MAX];
	strcpy(c1, "10");
	int count = 0, i = 0, len1, len2, flag1 = 0, j = 0, l = 1, s= 0;
	f[0] = 0;
	len1 = strlen(a);
	len2 = strlen(b);
	if((strcmp(b, "0")) == 0) {
		strcpy(e, "NOT DEFINED");
		return;
	}
	if(compare(a, b) == -1) {
		strcpy(e, "0");
		return;
	}
	strcpy(c, b);
	while((compare(a, c)) != -1) {
		flag1 = 0;
		j = 0;
		strcpy(b, c);
		while((compare(a, b)) != -1) {
			flag1++;
			strcpy(b2, b);
			strcpy(c1, "10");
			multiply(b, c1, b);
		}
		f[l] = flag1;
		s = f[l - 1] - f[l];
			l++;
		/*this loop is for reintroducing the missing zeroes*/
		while(1) {
			if(s > 1) {
				e[i] = 0 + '0';
				i++;
				s--;
			}
			else
				break;
		} 
			
		while((compare(a, b2)) != -1) {
			a = sub(a, b2);
			strcpy(a2, a);
			count++;
			e[i] = count + '0';	
		}
		i++;
		count = 0;
	}
	if(compare(b2, c) == 2) {
		//if(atoi(a) >= atoi(b2)) 		
	}
	else {/*this loop is for reintroducing missing zeroes if remainder is less than divisor*/
		while(flag1 > 1) {
			e[i] = 0 + '0';
			flag1--;
			i++;
		}		
	}
	e[i] = '\0';		
	return;
}
char *powminus(char a[]){
	//this function reduces the power by 1.
 	int i, j, k=0;
	if(strlen(a) == 1 && a[0] == '0'){
		return a;
	}
	i = strlen(a) - 1;
	j = 0;
	int p = 0;
	while(a[i-j] == '0') {
		k++;
		j++;
	}
	if(k >= 1){
		while(k != 0) {
			a[i] = '9';
			k--;
			i--;
		}
		a[i] = a[i]-1;
		if(a[0] == '0' && a[1] != '0'){
			p = strlen(a);
			k = 0;
			while(k < p) {
				a[k] = a[k+1];
				k++;
			}
		}
	}
	else {
		i = strlen(a) - 1;
		a[i] = a[i] - 1;
	}
	p++;
}
char *power(char a[], char b[], char c[]) {
	int l1, l2, i = 0;
	char *p, *q;
	l1 = strlen(a);
	l2 = strlen(b);
	p = (char *)malloc(l1 + 3);
	q = (char *)malloc(l2 + 3);
	if(l2 == 1 && b[0] == '0'){
		c[0] = '1';
		c[1] ='\0';
		return c;
	}
	while(a[0] == '0'){
		l1 = strlen(a);
		while(i < l1){
			a[i] = a[i + 1];
			i++;
		}
		i = 0;
	}
	if(strcmp(b,"1") == 0){
		strcpy( c, a);
		return c;
	}
	strcpy( p, a);
	strcpy( q, b);
	powminus(b);
	while(b[0] != '0'){//this loop multiplies the number repeatedly and calls the powminus function to reduce power each time by one.
		multiply( a, p, c);
		strcpy(a, c);
		powminus(b);
	}
	strcpy(a, p);
	strcpy(b, q);
	free(p);
	free (q);
	return c;
}
char *modulo(char *a, char *b, char *c, char *d) {
	char *cc = (char *)malloc(MAX);
	if((strcmp(a, "0") == 0) && (strcmp(b, "0") == 0))
		return "NOT DEFINED";
	if((strcmp(b, "0")) == 0) {
		strcpy(cc, "NOT DEFINED");
		return cc;
	}
	if((compare(a, b)) == 2) {
		return "0";
	}
	if(strcmp(a, "0") == -48 && compare(a, b) == -1)
		return "0";
	if((compare(a, b)) == -1) {
		return a;
	}		
	division(a, b, c, d);
	//this function calls the division function and store the remainder in d and then copy in cc.
	strcpy(cc, d);
	if(atoi(cc) == 0) 
		return "0";
	else
		removezero(cc);
	return cc;
}
