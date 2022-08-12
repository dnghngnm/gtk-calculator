#define ERR -199
int dec = 0;
int count = 0;
int type = -1;

int tokenise(char *str)
{
	int i, temp = 0;
	for (i = count; str[i] != '\0'; i++, count++)
	{
		// 53+6'\0'
		// i = 0; str[0] = '5';
		temp = 0;
		if (str[i] <= '9' && str[i] >= '0')
		{
			temp = temp * 10 + str[i] - '0';
			// temp = 0 * 10 + 5 - '0';
			// temp = 53 - 48 = 5;
			i++;	 // i = 1 // i = 4;
			count++; // count = 1; // count = 5;
			while (str[i] <= '9' && str[i] >= '0')
			{
				temp = temp * 10 + str[i] - '0'; // temp = 5 * 10 + 51 - 48 = 53
				i++;							 // i = 2;
				count++;						 // count = 2;
			}

			type = 0;
			return temp; // temp = 53;
		}
		if (str[i] == '.')
		{
			return 0;
		}
		if (str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '/' || str[i] == '-' || str[i] == '!' || str[i] == '^')
		{
			count++;
			type = 1;

			return str[i];
		}
		if (str[i] == ')' || str[i] == '(')
		{

			count++;
			type = 2;
			return str[i];
		}
		if (str[i] != ' ' && !(str[i] <= '9' && str[i] >= '0') && !(str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '/' || str[i] == '-' || str[i] != '^' || str[i] != '!') && str[i] != '\n')
		{
			count++;
			return ERR;
		}
	}
	count = -1;
	return -1;
}
