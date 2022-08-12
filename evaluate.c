#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "stack.c"
#include "token.c"
#define ERR -199
#define E 2.71828182846
#define M 1.44269504088896340736 // log2(e)
#define PI 3.14159265358
extern int count;
extern int type;
extern int flag;
extern int sign;
char str1[100];
char str2[100];
char newString[100][100];
char newString_ctf[100][100];
double result = 0;
double resultA = 1;
double restultB = 1;
double difResult = 0;
char operator[1024];
int n = 0;
int unary = 1;

void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char *res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	// Extract floating part
	float fpart = n - (float)ipart;

	// convert integer part to string
	int i = intToStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0)
	{
		res[i] = '.'; // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);

		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

// phép toán một ngôi có duy nhất một giá trị nhập vào
// kiểm tra từ kí tự đều tiên đến cuối cùng trong chuỗi

void ctf(char *str2)
{
	// ctr: convert to string
	// char operator[100];
	// sin( 60 )
	long int i, j, ctr;
	j = 0;
	ctr = 0;
	// strlen: tính toán độ dài của chuỗi str (không bao gồm ký tự null kết thúc)
	for (i = 0; i <= (strlen(str2)); i++)
	{
		// sin( pi )
		// if space or NULL found, assign NULL into newString_ctf[ctr]
		if (str2[i] == ' ' || str2[i] == '\0')
		{
			newString_ctf[ctr][j] = '\0';
			ctr++; // for next word
			j = 0; // for next word, init index to 0
		}
		else if (str2[i] == '=')
		{
			ctr--;
			newString_ctf[ctr][j] = '\0';
			j = 0;
		}
		else
		{
			newString_ctf[ctr][j] = str2[i];
			j++;
		}
	}
}

void readline(char *str1)
{
	// ctr: convert to string
	// char operator[100];
	// sin( 60 )
	long int i, j, ctr;
	int o_count = 0;
	j = 0;
	ctr = 0;
	// strlen: tính toán độ dài của chuỗi str (không bao gồm ký tự null kết thúc)
	for (i = 0; i <= (strlen(str1)); i++)
	{
		// sin( pi )
		// if space or NULL found, assign NULL into newString[ctr]
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			newString[ctr][j] = '\0';
			ctr++; // for next word
			j = 0; // for next word, init index to 0
		}
		else if (str1[i] == '=')
		{
			ctr--;
			newString[ctr][j] = '\0';
			j = 0;
		}
		if (str1[i] == ',')
		{
			newString[ctr][j] = '\0';
			ctr++; // for next word
			j = 0; // for next word, init index to 0
		}
		// sin( 60+e+30 )
		else if (str1[i] == 'e')
		{
			ftoa(E, newString[ctr], 9);
			j = 11;
		}
		else if (str1[i] == 'P')
		{
			ftoa(PI, newString[ctr], 9);
			j = 11;
		}
		// sin( 60+30*2*3-1 )
		else if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/')
		{
			operator[o_count] = str1[i];
			newString[ctr][j] = '\0';
			o_count++;
			ctr++;
			j = 0;
		}
		else
		{
			newString[ctr][j] = str1[i];
			j++;
		}
		// ví dụ người dùng nhập "sin( 1 )" ---> strlen(str1) = 7
		// mảng hai chiều kiểu long int gồm ctr mảng một chiều - mỗi mảng gồm j phần tử con
		// str1[0] = 's' ---> newString[0][0] = str1[0]; lúc này kí tự 's' sẽ không hợp lệ
		// str1[1] = 'i' ---> newString[0][1] = str1[1]; lúc này kí tự 'i' sẽ không hợp lệ
		// str1[2] = 'n' ---> newString[0][2] = str1[2]; lúc này kí tự 'n' sẽ không hợp lệ
		// str1[3] = '(' ---> newString[0][3] = str1[3]; lúc này kí tự '(' sẽ không hợp lệ
		// str1[4] = ' ' ---> newString[0][4] = '\0'; lúc này kí tự ' ' sẽ bằng NULL (ctr++ & j = 0)
		// str1[5] = '1' ---> newString[1][0] = str1[5]; j = 1; i = 6;
		// str1[6] = '+' ---> newString[1][1] = '\0'; ctr = 2, j = 0;
		// str1[7] = '3' ---> newString[2][0] = str1[7]; j = 1; i = 8;
		// str1[8] = '+' ---> newString[2][1] = '\0'; ctr = 3, j = 0;
		// str1[9] = '5' ---> newString[3][0] = '\0'; ctr = 4, j = 0, i = 10;
		// str1[10] = ' ' ---> newString[4][0] = '\0'; ctr = 5, j = 0, i = 11;

		// chuỗi X = 7 Y = 8 Z = 10
		// i = 0; i =< 10; i++
		// str1[0] = 'X' ---> newString[0][0] = str1[0]; j = 1; i = 1;
		// str1[1] = ' ' ---> newString[0][1] = '\0'; ctr = 1; j = 0; i = 2;
		// str1[2] = '=' ---> newString[0][0] = '\0'; ctr = 0; j = 0; i = 3;
		// str1[3] = ' ' ---> newString[0][0] = '\0'; ctr = 1; j = 0; i = 4;
		// str1[4] = '7' ---> newString[1][0] = str1[4]; j = 1; i = 5;          newString[1][0] = 7;
		// str1[5] = ' ' ---> newString[1][1] = '\0'; ctr = 2; j = 0; i = 6;
		// str1[6] = 'Y' ---> newString[2][0] = str1[6]; ctr = 2; j = 1; i = 7;
		// str1[7] = ' ' ---> newString[2][1] = '\0'; ctr = 3; j = 0; i = 8;
		// str1[8] = '=' ---> newString[2][0] = '\0'; j = 0; i = 9;
		// str1[9] = ' ' ---> newString[2][0] = '\0'; ctr = 3; j = 0; i = 10;
		// str1[10] = '8' ---> newString[3][0] = str1[10]; ctr = 3; j = 1; i = 11; newString[3][0] == 8;
	}

	for (int i = 0; i < o_count; i++)
	{
		if (operator[i] == '*' || operator[i] == '/')
		{
			if (operator[i] == '*')
			{
				resultA = atof(newString[i + 1]) * atof(newString[i + 2]);
			}
			else
			{
				resultA = atof(newString[i + 1]) / atof(newString[i + 2]);
			}
			operator[i] = '+';
			newString[i + 2][0] = '0';

			int j = i;
			while (operator[j + 1] == '*' || operator[j + 1] == '/')
			{
				if (operator[j + 1] == '*')
				{
					resultA = resultA * atof(newString[j + 3]);
				}
				else
				{
					resultA = resultA / atof(newString[j + 3]);
				}
				operator[j + 1] = '+';
				newString[j + 3][0] = '0';
				j++;
			}

			ftoa(resultA, newString[i + 1], 9);
		}
	}

	result = atof(newString[1]);
	int k = 2;
	for (int i = 0; i < o_count; i++)
	{
		if (operator[i] == '+')
		{
			result = result + atof(newString[k]);
		}
		else if (operator[i] == '-')
		{
			result = result - atof(newString[k]);
		}
		k++;
	}
}

int infix(char *exp)
{
	long int operator, brace, prob;
	long int tem2, tem3, tem4, fact = 1, c, n;
	long int difResult;
	long int tem;
	stack tokens;
	// (Last In First Out (LIFO))
	/*
	Ngăn xếp là 1 dạng đặc biệt của danh sách liên kết mà việc bổ sung hay loại bỏ 1 phần tử đều thực hiện ở 1 đầu của danh sách gọi là đỉnh.
	Ngăn xếp có 2 thao tát cơ bản: thêm phần tử vào được gọi là push và loại bỏ phần tử được gọi là pop.
	Việc loại bỏ phần tử sẽ tiến hành loại bỏ phần tử mới nhất được đưa vào danh sách,
	chính vì tính chất này mà ngăn xếp còn được gọi là kiểu dữ liệu LIFO( last in first out – Vào sau ra trước)
	init là một daemon(trình nền) luôn chạy cho đến khi hệ thống tắt.
	*/

	init(&tokens);
	while (1)
	{
		tem = tokenise(exp);
		if (unary == 1)
		{
			unary = 0;
			if (tem == '-' && type == 1)
			{
				tem = tokenise(exp);
				tem *= -1;
			}
		}
		if (count == -1)
			break;
		if (type == 0)
		{
			push(&tokens, tem);
		}
		else if (type == 1)
		{
			if (tem == '!')
			{
				n = pop(&tokens);
				for (c = 1; c <= n; c++)
					fact = fact * c;
				return fact;
				// push(&tokens, difResult);
			}
			if (tem == '*' || tem == '%' || tem == '/' || tem == '^')
			{
				prob = tokenise(exp);
				if (prob == -1 || type == 1)
					return ERR;
				if (empty(&tokens))
					return ERR;
				switch (tem)
				{
				case '*':
					if (prob != '(')
					{
						difResult = pop(&tokens) * prob;
						push(&tokens, difResult);
					}
					else
					{
						unary = 1;
						brace = infix(exp);
						difResult = pop(&tokens) * brace;
						push(&tokens, difResult);
					}
					break;
				case '/':
					if (prob != '(')
					{
						difResult = pop(&tokens) / prob;
						push(&tokens, difResult);
					}
					else
					{
						unary = 1;
						brace = infix(exp);
						difResult = pop(&tokens) / brace;
						push(&tokens, difResult);
					}
					break;
				case '%':
					if (prob != '(')
					{

						difResult = pop(&tokens) % prob;
						return difResult;
						// push(&tokens, difResult);
					}
					else
					{
						unary = 1;
						brace = infix(exp);
						difResult = pop(&tokens) % brace;
						return difResult;
						// push(&tokens, difResult);
					}
				case '^':
					if (prob != '(')
					{
						difResult = pow(pop(&tokens), prob);
						push(&tokens, difResult);
					}
					else
					{
						unary = 1;
						brace = infix(exp);
						difResult = pow(pop(&tokens), brace);
						push(&tokens, difResult);
					}
				}
			}
			else if (tem == '+' || tem == '-')
			{
				push(&tokens, tem);
			}
		}
		else if (type == 2)
		{
			if (tem == '(')
			{
				unary = 1;
				brace = infix(exp);
				push(&tokens, brace);
			}
			else if (tem == ')')
			{
				break;
			}
		}
	}
	while (1)
	{
		tem2 = pop(&tokens);
		// printf("%d\n", tem2);
		if (empty(&tokens))
		{
			return tem2;
		}
		operator= pop(&tokens);
		if (operator!= '+' && operator!= '-')
			return ERR;
		switch (operator)
		{
		case '+':
			if (!empty(&tokens))
				tem3 = pop(&tokens);
			else
				return ERR;
			if (!empty(&tokens))
			{
				tem4 = pop(&tokens);
				if (tem4 == '-')
				{
					tem3 = (-1) * tem3;
					push(&tokens, '+');
				}
				else
				{
					push(&tokens, tem4);
				}
			}
			difResult = tem3 + tem2;
			push(&tokens, difResult);
			break;

		case '-':
			if (!empty(&tokens))
				tem3 = pop(&tokens);
			else
				return ERR;
			if (!empty(&tokens))
			{
				tem4 = pop(&tokens);
				if (tem4 == '-')
				{
					tem3 = (-1) * tem3;
					push(&tokens, '+');
				}
				else
				{
					push(&tokens, tem4);
				}
			}
			difResult = tem3 - tem2;
			push(&tokens, difResult);
			break;
		}
	}
}

unsigned int log2n(unsigned int n)
{
	return (n > 1) ? 1 + log2n(n / 2) : 0;
}

double eval(char *str)
{
	readline(str);
	// atof: chuyển đổi một chuỗi được trỏ tới bởi tham số str thành một số thực dấu chấm động (kiểu double)
	// converting radians to degrees

	if (flag == 1)
	{
		result = result * (PI / 180.0);
		return sin(result);
	}
	else if (flag == 2)
	{
		result = result * (PI / 180.0);
		return cos(result);
	}
	else if (flag == 3)
	{
		result = result * (PI / 180.0);
		return tan(result);
	}
	else if (flag == 4)
	{
		result = result * (PI / 180.0); // this is to convert radian to degree
		return 1 / tan(result);
	}
	else if (flag == 7)
	{
		return log(result);
	}
	else if (flag == 8)
	{
		return log2n(result);
	}
	else if (flag == 9)
	{
		return sqrt(result);
	}
	else if (flag == 10)
	{
		if (result < 0)
		{
			result = (-1) * result;
			return result;
		}
		else
		{
			return result;
		}
	}
	else if (flag == 11)
	{
		return ceil(result);
	}
	else if (flag == 12)
	{
		return floor(result);
	}
	else if (flag == 13)
	{
		double n;
		double x = atof(newString[1]);
		double y = atof(newString[2]);
		int numerator, denominator, remainder;

		if (x > y)
		{
			numerator = x;
			denominator = y;
		}
		else
		{
			numerator = y;
			denominator = x;
		}

		remainder = numerator % denominator;

		while (remainder != 0)
		{
			numerator = denominator;
			denominator = remainder;
			remainder = numerator % denominator;
		}

		n = denominator;
		result = x * y / n;

		return result;
	}
	else if (flag == 14)
	{
		double x = atof(newString[1]);
		double y = atof(newString[2]);
		int numerator, denominator, remainder;

		if (x > y)
		{
			numerator = x;
			denominator = y;
		}
		else
		{
			numerator = y;
			denominator = x;
		}

		remainder = numerator % denominator;

		while (remainder != 0)
		{
			numerator = denominator;
			denominator = remainder;
			remainder = numerator % denominator;
		}

		result = denominator;

		return result;
	}
	else
		return 0;
}

double convert_a_to_f(char *str)
{
	double a;
	ctf(str);
	a = atof(newString_ctf[1]);
	return a;
}

double convert_b_to_f(char *str)
{
	double b;
	ctf(str);
	b = atof(newString_ctf[3]);
	return b;
}

double convert_c_to_f(char *str)
{
	double c;
	ctf(str);
	c = atof(newString_ctf[5]);
	return c;
}

double convert_d_to_f(char *str)
{
	double d;
	ctf(str);
	d = atof(newString_ctf[7]);
	return d;
}

double convert_e_to_f(char *str)
{
	double e;
	ctf(str);
	e = atof(newString_ctf[1]);
	return e;
}

double convert_f_to_f(char *str)
{
	double f;
	ctf(str);
	f = atof(newString_ctf[3]);
	return f;
}

double convert_g_to_f(char *str)
{
	double g;
	ctf(str);
	g = atof(newString_ctf[5]);
	return g;
}

double convert_h_to_f(char *str)
{
	double h;
	ctf(str);
	h = atof(newString_ctf[7]);
	return h;
}

double convert_i_to_f(char *str)
{
	double i;
	ctf(str);
	i = atof(newString_ctf[1]);
	return i;
}

double convert_j_to_f(char *str)
{
	double j;
	ctf(str);
	j = atof(newString_ctf[3]);
	return j;
}

double convert_k_to_f(char *str)
{
	double k;
	ctf(str);
	k = atof(newString_ctf[5]);
	return k;
}

double convert_l_to_f(char *str)
{
	double l;
	ctf(str);
	l = atof(newString_ctf[7]);
	return l;
}