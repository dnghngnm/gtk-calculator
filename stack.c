#define ERR -199

typedef struct data
{
	long int value;
	struct data *next;
} data;

typedef data *node; // danh sách liên kết

typedef struct stack
{
	node p;
} stack;

void push(stack *, long int); // Thêm một phần tử vào đỉnh của ngăn xếp, số phần tử của ngăn xếp tăng lên 1.
int pop(stack *);			  // Xóa bỏ phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp giảm đi 1.
int empty(stack *);			  // Kiểm tra ngăn xếp trống hay không. Ngăn xếp trống là ngăn xếp không có phần tử nào.
void init(stack *);
int tokenise(char *);

void init(stack *s)
{
	s->p = malloc(sizeof(data));
	s->p->next = NULL;
}

void push(stack *s, long int a)
{
	node temp;
	s->p->value = a;
	temp = s->p;
	s->p = malloc(sizeof(data));
	s->p->next = temp; // temp = 53;
}

int pop(stack *s)
{
	if (s->p->next == NULL)
	{
		return 0;
	}
	else
	{
		s->p = s->p->next;
		long int num = s->p->value;
		return num;
	}
}

int empty(stack *s)
{
	if (s->p->next == NULL)
		return 1;
	else
		return 0;
}