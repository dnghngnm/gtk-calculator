// gcc `pkg-config --cflags gtk+-3.0` -o app calculator.c `pkg-config --libs gtk+-3.0`

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "evaluate.c"
#include <cairo.h>

#define WIDTH 900
#define HEIGHT 900

#define ZOOM_X 100.0
#define ZOOM_Y 100.0

int sign;
int flag = -1;
int argc;
char **argv;
char ans[1024];
double s2;
char s3[100] = "-0";
char s4[100] = "0";
char s5[100] = "-";

typedef struct
{
	GtkWidget *entry, *textview;
} Widgets;

Widgets *w;

typedef struct
{
	GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8, *entry9, *entry10, *entry11, *entry12;
	GtkWidget *entryA, *entryB, *entryC, *entryD;
	GtkWidget *textview0, *textview1, *textview2;
} Widget;

Widget *o;

GtkWidget *window;
GtkWidget *entry;
GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *entry3;
GtkWidget *entry4;
GtkWidget *entry5;
GtkWidget *entry6;
GtkWidget *entry7;
GtkWidget *entry8;
GtkWidget *entry9;
GtkWidget *entry10;
GtkWidget *entry11;
GtkWidget *entry12;

/*
flag = 1 for sin
flag = 2 for cos
flag = 3 for tan
flag = 4 for cot
flag = 7 for log
flag = 8 for ln
flag = 9 for square root
flag = 10 for absolute Value
flag = 11 for ceil
flag = 12 for floor
flag = 13 for LCM
flag  = 14 for GCD
*/

static void load_css(void)
{
	GtkCssProvider *provider;
	GdkDisplay *display;
	GdkScreen *screen;

	const gchar *css_style_file = "style.css";
	GFile *css_fp = g_file_new_for_path(css_style_file);
	GError *error = 0;

	provider = gtk_css_provider_new();
	display = gdk_display_get_default();
	screen = gdk_display_get_default_screen(display);

	gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	gtk_css_provider_load_from_file(provider, css_fp, &error);
}

void close_window(GtkWindow *window)
{
	gtk_window_close(window);
}

void kill_window(GtkWidget *widget, GtkWidget *window)
{
	gtk_widget_hide(window);
}

void show_window(GtkWidget *widget, GtkWidget *window)
{
	gtk_widget_show(window);
}

static void clicked(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void Setabs(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));
	flag = 10;
	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void Setroot(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));
	flag = 9;
	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setsin(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer; // buffer là vùng lưu trữ dữ liệu tạm thời
	GtkTextMark *mark;
	GtkTextIter iter;

	const gchar *text;
	char *button_num = (char *)data; // gán char cho dữ liệu lấy từ người dùng

	flag = 1;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num); // đặt văn bản - text trong button_num thành giá trị đã cho (char)
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);			   // trả về mark đại diện cho con trỏ
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark); // khởi tạo iter với giá trị hiện tại của mark
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setcos(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 2;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void settan(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 3;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setcot(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 4;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setceil(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 11;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setfloor(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 12;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setlog(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 7;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setln(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 8;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setLCM(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 13;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setGCD(GtkWidget *widget, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	char *button_num = (char *)data;
	flag = 14;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	text = gtk_entry_get_text(GTK_ENTRY(w->entry));

	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
	gtk_text_buffer_insert(buffer, &iter, text, -1);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void setAns(GtkWidget *widget, gpointer data)
{
	char *button_num = (char *)data;
	flag = 18;
	gtk_entry_set_text(GTK_ENTRY(w->entry), button_num);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void equal(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextIter start, end;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer((GtkTextView *)w->textview);
	gchar *text;

	/*const gchar *entry_text;
	// const char* là một con trỏ có thể thay đổi thành một ký tự / chuỗi bất biến
	// char*là một con trỏ có thể thay đổi thành một ký tự / chuỗi có thể thay đổi
	char *entry_text1;*/

	char str[1024], dg[1024];
	double result = 0;
	char str1[1024];
	strcpy(str1, "1/0"); // được sử dụng để sao chép chuỗi ký tự từ "1/0" tới str1
	gtk_text_buffer_get_bounds(buffer, &start, &end);
	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

	// printf("%s\n", text);

	// strcmp được sử dụng để so sánh hai chuỗi
	if (strcmp(text, "") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Enter Expression");
	}
	if (strcmp(text, str1) == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Math ERROR");
		return;
	}
	if (strcmp(text, "tan( 90 )") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Math Error");
		return;
	}
	if (strcmp(text, "tan( 90") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Math Error");
		return;
	}
	if (strcmp(text, "cot( 90") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Math Error");
		return;
	}
	if (strcmp(text, "cot( 90 )") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Math Error");
		return;
	}
	if (strcmp(text, "∫") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "Load...");
		return;
	}
	if (strcmp(text, "e") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "2.71828182846");
		return;
	}
	if (strcmp(text, "-e") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "-2.71828182846");
		return;
	}
	if (strcmp(text, "P") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "3.14159265358");
		return;
	}
	if (strcmp(text, "-P") == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(w->entry), "-3.14159265358");
		return;
	}

	// entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
	// gtk_label_set_text (GTK_LABEL(label1), (char*)entry_text);
	// printf("%s\n", text);

	if (flag > 0 && flag < 16)
	{
		result = eval((char *)text);
		if (result == -199)
		{
			gtk_entry_set_text(GTK_ENTRY(w->entry), "Math Error");
		}
		if (result < 0 && result > -1)
		{
			result = result * -1;
			ftoa(result, dg, 9);

			char s1[10] = "-0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(dg);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = dg[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(w->entry), s1);

			s2 = atof(s1);
			
			if (s2 < 0 && s2 > -1)
			{
				s2 = s2 * -1;
				ftoa(s2, ans, 9);

				int m, n, k1, k2;

				k1 = strlen(s3);
				k2 = strlen(ans);

				n = 0;
				for (m = k1; m < (k1 + k2); m++) {
					s3[m] = ans[n];
					n++;
				}

				s3[m] = '\0';
				s2 = s2 * -1;
				// printf("%s", s3);
			}
		}
		else if (result >= 1)
		{
			ftoa(result, dg, 9);
			gtk_entry_set_text(GTK_ENTRY(w->entry), dg);
			s2 = atof(dg);
			ftoa(s2, ans, 9);
		}
		else if (result == 0)
		{
			ftoa(result, dg, 1);
			gtk_entry_set_text(GTK_ENTRY(w->entry), "0");
			s2 = atof(dg);
			ftoa(s2, ans, 9);
		}
		else if (result > 0 && result < 1)
		{
			ftoa(result, dg, 9);

			char s1[10] = "0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(dg);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = dg[j];
				j++;
			}

			s1[i] = '\0';
			gtk_entry_set_text(GTK_ENTRY(w->entry), s1);

			s2 = atof(s1);
			if (s2 > 0 && s2 < 1)
			{
				ftoa(s2, ans, 9);

				int m, n, k1, k2;

				k1 = strlen(s4);
				k2 = strlen(ans);

				n = 0;
				for (m = k1; m < (k1 + k2); m++) {
					s4[m] = ans[n];
					n++;
				}

				s4[m] = '\0';
			}
		}
		else if (result <= -1)
		{
			result = result * -1;
			ftoa(result, dg, 9);

			char s1[10] = "-";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(dg);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = dg[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(w->entry), s1);

			s2 = atof(s1);
			if (s2 <= -1)
			{
				s2 = s2 * -1;
				ftoa(s2, ans, 9);

				int m, n, k1, k2;

				k1 = strlen(s5);
				k2 = strlen(ans);

				n = 0;
				for (m = k1; m < (k1 + k2); m++) {
					s5[m] = ans[n];
					n++;
				}

				s5[m] = '\0';
				s2 = s2 * -1;
			}
		}
		else
		{
			ftoa(result, dg, 9);
			gtk_entry_set_text(GTK_ENTRY(w->entry), dg);
			s2 = atof(dg);
			ftoa(s2, ans, 9);
		}
	}
	else if (flag == 18)
	{
		if (s2 < 0 && s2 > -1) {
			gtk_entry_set_text(GTK_ENTRY(w->entry), s3);
		}
		else if (s2 > 0 && s2 < 1) {
			gtk_entry_set_text(GTK_ENTRY(w->entry), s4);
		}
		else if (s2 <= -1) {
			gtk_entry_set_text(GTK_ENTRY(w->entry), s5);
		}
		else {
			gtk_entry_set_text(GTK_ENTRY(w->entry), ans);
		}
	}
	else
	{
		result = infix((char *)text);
		// printf("%lf", result);
		if (result < 0)
		{
			result = result * -1;
			ftoa(result, dg, 3);
			str[0] = '-';
			str[1] = '\0';
			strcat(str, dg);
			// g_print("%s", str);
			gtk_entry_set_text(GTK_ENTRY(w->entry), str);
			s2 = atof(str);
			ftoa(s2, ans, 9);
		}
		else if (result == 0)
		{
			// ftoa(result, dg, 9);
			gtk_entry_set_text(GTK_ENTRY(w->entry), "0");
		}
		else
		{
			ftoa(result, dg, 9);
			gtk_entry_set_text(GTK_ENTRY(w->entry), dg);
			s2 = atof(dg);
			ftoa(s2, ans, 9);
		}
	}

	flag = -1;
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);
}

static void clear(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w->textview));
	gtk_text_buffer_get_bounds(buffer, &start, &end);
	gtk_text_buffer_delete(buffer, &start, &end);
	gtk_window_set_default_size(GTK_WINDOW(window), 410, 770);

	gtk_entry_set_text(GTK_ENTRY(w->entry), "");
}

// static void enter_callback(GtkWidget *widget, GtkWidget *entry) {
// 	const gchar *entry_text;
// 	entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
// 	printf ("Entry contents: %s\n", entry_text);
// }

static void equation_2(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	double x1 = 0, x2 = 0;
	double dt = (b * b) - (4 * a * c);

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		return;
	}

	if (dt < 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution!");
	}
	else if (dt == 0)
	{
		x1 = -b / (2 * a);

		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
	}
	else if (dt > 0)
	{
		x1 = (-b + sqrt(dt)) / (2 * a);
		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X1 = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X1 = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X1 = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X1 = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X1 = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}

		/* ***************************************************************** */

		x2 = (-b - sqrt(dt)) / (2 * a);
		if (x2 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "X2 = 0");
		}
		else if (x2 < 0 && x2 > -1)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "X2 = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0 && x2 < 1)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "X2 = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 < 0)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "X2 = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "X2 = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
	}
}

static void equation_3(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	d = convert_d_to_f((char *)text0);

	double x1 = 0, x2 = 0, x3 = 0;
	double dt = b * b - 3 * a * c;
	double first = (9 * a * b * c - 2 * pow(b, 3) - 27 * a * a * d);
	double second = (2 * sqrt(pow(fabs(dt), 3)));
	double k = first / second;
	double result = fabs(k);

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		return;
	}

	if (dt == 0)
	{
		x1 = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);
		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}

		return;
	}

	else if (dt < 0)
	{
		x1 = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}

		return;
	}

	if (dt > 0)
	{
		if (k > 1)
		{
			x1 = (sqrt(dt) * fabs(k)) / (3 * a * k) * (pow(fabs(k) + sqrt(k * k - 1), 1.0 / 3) + pow(fabs(k) - sqrt(k * k - 1), 1.0 / 3)) - b / (3 * a);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			return;
		}
		else if (k <= 1)
		{
			x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X1 = 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X1 = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X1 = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X1 = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X1 = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X2 = 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X2 = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X2 = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X2 = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X2 = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}

			/* ***************************************************************************************** */

			x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
			if (x3 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryC), "X3 = 0");
			}
			else if (x3 < 0 && x3 > -1)
			{
				x3 = x3 * -1;
				ftoa(x3, x3_ftoa, 9);

				char s1[10] = "X3 = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x3_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x3_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
			}
			else if (x3 > 0 && x3 < 1)
			{
				ftoa(x3, x3_ftoa, 9);

				char s1[10] = "X3 = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x3_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x3_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
			}
			else if (x3 < 0)
			{
				x3 = x3 * -1;
				ftoa(x3, x3_ftoa, 9);

				char s1[10] = "X3 = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x3_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x3_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
			}
			else if (x3 > 0)
			{
				ftoa(x3, x3_ftoa, 9);

				char s1[10] = "X3 = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x3_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x3_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
			}
		}
	}
}

static void equation_4(GtkWidget *widget, GtkWidget *entr)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0, g = 0, e = 0, f = 0;

	// d->e; e->f;

	a = convert_a_to_f((char *)text0);
	b = convert_b_to_f((char *)text0);
	c = convert_c_to_f((char *)text0);

	GtkTextIter start1, end1;
	GtkTextBuffer *buffer1 = gtk_text_view_get_buffer((GtkTextView *)o->textview1);
	gchar *text1;
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	text1 = gtk_text_buffer_get_text(buffer1, &start1, &end1, FALSE);

	e = convert_e_to_f((char *)text1);
	f = convert_f_to_f((char *)text1);

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryD), "Math Error!");
		return;
	}

	int n = 4, dem;
	double x[4] = {-30, -15, 15, 30}, temp = 0;
	for (int i = 0; i <= 3; i++)
	{
		dem = 0;
		while (x[i] - temp != 0)
		{
			float f1 = a * pow(x[i], 4) + b * pow(x[i], 3) + c * pow(x[i], 2) + e * x[i] + f;
			float f2 = 4 * a * pow(x[i], 3) + 3 * b * pow(x[i], 2) + 2 * c * x[i] + e;
			temp = x[i];
			x[i] = x[i] - f1 / f2;
			dem++;
			if (dem == 100000)
			{
				break;
			}
		}
	}

	if (dem == 100000)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "No Solution");
		gtk_entry_set_text(GTK_ENTRY(o->entryD), "No Solution");
	}
	else
	{
		for (int i = 0; i <= 2; i++)
		{
			int j = i + 1;
			for (int j = i + 1; j < n; j++)
			{
				if (i != j)
				{
					x[j] = x[n - 1];
					n--;
				}
			}
		}

		for (int i = 0; i <= n - 1; i++)
		{
			// printf("X%d = %f\n", i + 1, x[i]);
			if (x[i] == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X1 = 0");
			}
			else if (x[i] < 0 && x[i] > -1)
			{
				x[i] = x[i] * -1;
				ftoa(x[i], x1_ftoa, 9);

				char s1[10] = "X1 = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x[i] > 0 && x[i] < 1)
			{
				x[i] = x[i] * -1;
				ftoa(x[i], x1_ftoa, 9);

				char s1[10] = "X1 = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x[i] < 0)
			{
				x[i] = x[i] * -1;
				ftoa(x[i], x1_ftoa, 9);

				char s1[10] = "X1 = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x[i] > 0)
			{
				ftoa(x[i], x1_ftoa, 9);

				char s1[10] = "X1 = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			i++;
			if (i <= n - 1)
			{
				// printf("X%d = %f\n", i + 1, x[i]);
				if (x[i] == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X2 = 0");
				}
				else if (x[i] < 0 && x[i] > -1)
				{
					x[i] = x[i] * -1;
					ftoa(x[i], x1_ftoa, 9);

					char s1[10] = "X2 = -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x[i] > 0 && x[i] < 1)
				{
					x[i] = x[i] * -1;
					ftoa(x[i], x1_ftoa, 9);

					char s1[10] = "X2 = 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x[i] < 0)
				{
					x[i] = x[i] * -1;
					ftoa(x[i], x1_ftoa, 9);

					char s1[10] = "X2 = -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x[i] > 0)
				{
					ftoa(x[i], x1_ftoa, 9);

					char s1[10] = "X2 = ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				i++;
				if (i <= n - 1)
				{
					// printf("X%d = %f\n", i + 1, x[i]);
					if (x[i] == 0)
					{
						gtk_entry_set_text(GTK_ENTRY(o->entryC), "X3 = 0");
					}
					else if (x[i] < 0 && x[i] > -1)
					{
						x[i] = x[i] * -1;
						ftoa(x[i], x1_ftoa, 9);

						char s1[10] = "X3 = -0";
						int i, j, n1, n2;

						n1 = strlen(s1);
						n2 = strlen(x1_ftoa);
						j = 0;
						for (i = n1; i < (n1 + n2); i++)
						{
							s1[i] = x1_ftoa[j];
							j++;
						}

						s1[i] = '\0';

						gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
					}
					else if (x[i] > 0 && x[i] < 1)
					{
						x[i] = x[i] * -1;
						ftoa(x[i], x1_ftoa, 9);

						char s1[10] = "X3 = 0";
						int i, j, n1, n2;

						n1 = strlen(s1);
						n2 = strlen(x1_ftoa);
						j = 0;
						for (i = n1; i < (n1 + n2); i++)
						{
							s1[i] = x1_ftoa[j];
							j++;
						}

						s1[i] = '\0';

						gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
					}
					else if (x[i] < 0)
					{
						x[i] = x[i] * -1;
						ftoa(x[i], x1_ftoa, 9);

						char s1[10] = "X3 = -";
						int i, j, n1, n2;

						n1 = strlen(s1);
						n2 = strlen(x1_ftoa);
						j = 0;
						for (i = n1; i < (n1 + n2); i++)
						{
							s1[i] = x1_ftoa[j];
							j++;
						}

						s1[i] = '\0';

						gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
					}
					else if (x[i] > 0)
					{
						ftoa(x[i], x1_ftoa, 9);

						char s1[10] = "X3 = ";
						int i, j, n1, n2;

						n1 = strlen(s1);
						n2 = strlen(x1_ftoa);
						j = 0;
						for (i = n1; i < (n1 + n2); i++)
						{
							s1[i] = x1_ftoa[j];
							j++;
						}

						s1[i] = '\0';

						gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
					}
					i++;
					if (i <= n - 1)
					{
						// printf("X%d = %f\n", i + 1, x[i]);
						if (x[i] == 0)
						{
							gtk_entry_set_text(GTK_ENTRY(o->entryD), "X4 = 0");
						}
						else if (x[i] < 0 && x[i] > -1)
						{
							x[i] = x[i] * -1;
							ftoa(x[i], x1_ftoa, 9);

							char s1[10] = "X4 = -0";
							int i, j, n1, n2;

							n1 = strlen(s1);
							n2 = strlen(x1_ftoa);
							j = 0;
							for (i = n1; i < (n1 + n2); i++)
							{
								s1[i] = x1_ftoa[j];
								j++;
							}

							s1[i] = '\0';

							gtk_entry_set_text(GTK_ENTRY(o->entryD), s1);
						}
						else if (x[i] > 0 && x[i] < 1)
						{
							x[i] = x[i] * -1;
							ftoa(x[i], x1_ftoa, 9);

							char s1[10] = "X4 = 0";
							int i, j, n1, n2;

							n1 = strlen(s1);
							n2 = strlen(x1_ftoa);
							j = 0;
							for (i = n1; i < (n1 + n2); i++)
							{
								s1[i] = x1_ftoa[j];
								j++;
							}

							s1[i] = '\0';

							gtk_entry_set_text(GTK_ENTRY(o->entryD), s1);
						}
						else if (x[i] < 0)
						{
							x[i] = x[i] * -1;
							ftoa(x[i], x1_ftoa, 9);

							char s1[10] = "X4 = -";
							int i, j, n1, n2;

							n1 = strlen(s1);
							n2 = strlen(x1_ftoa);
							j = 0;
							for (i = n1; i < (n1 + n2); i++)
							{
								s1[i] = x1_ftoa[j];
								j++;
							}

							s1[i] = '\0';

							gtk_entry_set_text(GTK_ENTRY(o->entryD), s1);
						}
						else if (x[i] > 0)
						{
							ftoa(x[i], x1_ftoa, 9);

							char s1[10] = "X4 = ";
							int i, j, n1, n2;

							n1 = strlen(s1);
							n2 = strlen(x1_ftoa);
							j = 0;
							for (i = n1; i < (n1 + n2); i++)
							{
								s1[i] = x1_ftoa[j];
								j++;
							}

							s1[i] = '\0';

							gtk_entry_set_text(GTK_ENTRY(o->entryD), s1);
						}
						i++;
					}
				}
			}
		}
	}
}

static void disequation_2_1(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	double x1 = 0, x2 = 0, temp = 0;
	double dt = b * b - 4 * a * c;

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		x1 = (-b + sqrt(dt)) / (2 * a);
		x2 = (-b - sqrt(dt)) / (2 * a);

		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
	}
	if (a > 0)
	{
		if (dt < 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "All Real Number");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "All Real Number");
		}
		if (dt == 0)
		{
			// printf("X ≠ %lf", -b / (2 * a));
			x1 = -b / (2 * a);

			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≠ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		if (dt > 0)
		{
			// printf("X < %lf, X > %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X > 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
	else if (a < 0)
	{
		if (dt <= 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution!");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution!");
		}
		if (dt > 0)
		{
			// printf("%lf < X < %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X < 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
}

static void disequation_2_2(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	double x1 = 0, x2 = 0, temp = 0;
	double dt = b * b - 4 * a * c;

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		x1 = (-b + sqrt(dt)) / (2 * a);
		x2 = (-b - sqrt(dt)) / (2 * a);

		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
	}
	if (a < 0)
	{
		if (dt < 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "All Real Number");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "All Real Number");
		}
		if (dt == 0)
		{
			// printf("X ≠ %lf", -b / (2 * a));
			x1 = -b / (2 * a);

			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≠ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≠ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		if (dt > 0)
		{
			// printf("X < %lf, X > %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X > 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
	else if (a > 0)
	{
		if (dt <= 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution!");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution!");
		}
		if (dt > 0)
		{
			// printf("%lf < X < %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X < 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
}

static void disequation_2_3(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	double x1 = 0, x2 = 0, temp = 0;
	double dt = b * b - 4 * a * c;

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		x1 = (-b + sqrt(dt)) / (2 * a);
		x2 = (-b - sqrt(dt)) / (2 * a);

		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
	}
	if (a > 0)
	{
		if (dt <= 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "All Real Number");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "All Real Number");
		}
		if (dt > 0)
		{
			// printf("X < %lf, X > %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≥ 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
	else if (a < 0)
	{
		if (dt < 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution!");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution!");
		}
		if (dt == 0)
		{
			// printf("X = %lf", -b / (2 * a));
			x1 = -b / (2 * a);

			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		if (dt > 0)
		{
			// printf("%lf < X < %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≤ 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
}

static void disequation_2_4(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	double x1 = 0, x2 = 0, temp = 0;
	double dt = b * b - 4 * a * c;

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		x1 = (-b + sqrt(dt)) / (2 * a);
		x2 = (-b - sqrt(dt)) / (2 * a);

		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
	}
	if (a < 0)
	{
		if (dt <= 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "All Real Number");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "All Real Number");
		}
		if (dt > 0)
		{
			// printf("X < %lf, X > %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≥ 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
	else if (a > 0)
	{
		if (dt < 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution!");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution!");
		}
		if (dt == 0)
		{
			// printf("X = %lf", -b / (2 * a));
			x1 = -b / (2 * a);

			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X = ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		if (dt > 0)
		{
			// printf("%lf < X < %lf", x1, x2);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}

			/* ***************************************************************************************** */

			if (x2 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≤ 0");
			}
			else if (x2 < 0 && x2 > -1)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0 && x2 < 1)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 < 0)
			{
				x2 = x2 * -1;
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
			else if (x2 > 0)
			{
				ftoa(x2, x2_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x2_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x2_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
			}
		}
	}
}

static void disequation_3_1(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	d = convert_d_to_f((char *)text0);

	double x1, x2, x3, temp;
	double dt = b * b - 3 * a * c;
	double k = (9 * a * b * c - 2 * pow(b, 3) - 27 * a * a * d) / (2 * sqrt(pow(fabs(dt), 3)));

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		if (fabs(k) <= 1)
		{
			x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
			x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
			x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
			if (x1 <= x2)
			{
				if (x2 >= x3)
				{
					temp = x2;
					if (x1 >= x3)
					{
						x2 = x1;
						x1 = x3;
					}
					else
					{
						x2 = x3;
					}
					x3 = temp;
				}
			}
			else
			{
				if (x2 >= x3)
				{
					temp = x1;
					x1 = x3;
					x3 = temp;
				}
				else
				{
					if (x1 <= x3)
					{
						temp = x1;
						x1 = x2;
						x2 = temp;
					}
				}
			}
		}
		else
		{
			x1 = (sqrt(dt) * fabs(k)) / (3 * a * k) * (pow(fabs(k) + sqrt(k * k - 1), 1.0 / 3) + pow(fabs(k) - sqrt(k * k - 1), 1.0 / 3)) - b / (3 * a);
		}
	}
	else if (dt == 0)
	{
		x1 = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);
	}
	else if (dt < 0)
	{
		x1 = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
	}

	if (dt >= 0 && fabs(k) <= 1)
	{
		if (a > 0)
		{
			if (x1 == x2)
			{
				// printf("x > %lf", x3);
				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X > 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf > X, x khac %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≠ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else
			{
				// printf("%lf < X < %lf, X > %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X < 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X > 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
		else
		{
			if (x1 == x2)
			{
				// printf("X khac %lf, x < %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≠ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X < 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf < X", x1);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
			}
			else
			{
				// printf("X < %lf, %lf < X < %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X > 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X < 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
	}
	else
	{
		if (a > 0)
		{
			// printf("X > %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		else
		{
			// printf("X < %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
	}
}

static void disequation_3_2(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	d = convert_d_to_f((char *)text0);

	double x1, x2, x3, temp;
	double dt = b * b - 3 * a * c;
	double k = (9 * a * b * c - 2 * pow(b, 3) - 27 * a * a * d) / (2 * sqrt(pow(fabs(dt), 3)));

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		if (fabs(k) <= 1)
		{
			x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
			x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
			x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
			if (x1 <= x2)
			{
				if (x2 >= x3)
				{
					temp = x2;
					if (x1 >= x3)
					{
						x2 = x1;
						x1 = x3;
					}
					else
					{
						x2 = x3;
					}
					x3 = temp;
				}
			}
			else
			{
				if (x2 >= x3)
				{
					temp = x1;
					x1 = x3;
					x3 = temp;
				}
				else
				{
					if (x1 <= x3)
					{
						temp = x1;
						x1 = x2;
						x2 = temp;
					}
				}
			}
		}
		else
		{
			x1 = (sqrt(dt) * fabs(k)) / (3 * a * k) * (pow(fabs(k) + sqrt(k * k - 1), 1.0 / 3) + pow(fabs(k) - sqrt(k * k - 1), 1.0 / 3)) - b / (3 * a);
		}
	}
	else if (dt == 0)
	{
		x1 = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);
	}
	else if (dt < 0)
	{
		x1 = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
	}

	if (dt >= 0 && fabs(k) <= 1)
	{
		if (a < 0)
		{
			if (x1 == x2)
			{
				// printf("x > %lf", x3);
				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X > 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf > X, x khac %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≠ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≠ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else
			{
				// printf("%lf < X < %lf, X > %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X < 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X > 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
		else
		{
			if (x1 == x2)
			{
				// printf("X khac %lf, x < %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≠ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≠ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X < 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf < X", x1);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
			}
			else
			{
				// printf("X < %lf, %lf < X < %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X > 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X > ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X < 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X < ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
	}
	else
	{
		if (a < 0)
		{
			// printf("X > %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X > 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X > ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		else
		{
			// printf("X < %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X < 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X < ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
	}
}

static void disequation_3_3(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	d = convert_d_to_f((char *)text0);

	double x1, x2, x3, temp;
	double dt = b * b - 3 * a * c;
	double k = (9 * a * b * c - 2 * pow(b, 3) - 27 * a * a * d) / (2 * sqrt(pow(fabs(dt), 3)));

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		if (fabs(k) <= 1)
		{
			x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
			x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
			x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
			if (x1 <= x2)
			{
				if (x2 >= x3)
				{
					temp = x2;
					if (x1 >= x3)
					{
						x2 = x1;
						x1 = x3;
					}
					else
					{
						x2 = x3;
					}
					x3 = temp;
				}
			}
			else
			{
				if (x2 >= x3)
				{
					temp = x1;
					x1 = x3;
					x3 = temp;
				}
				else
				{
					if (x1 <= x3)
					{
						temp = x1;
						x1 = x2;
						x2 = temp;
					}
				}
			}
		}
		else
		{
			x1 = (sqrt(dt) * fabs(k)) / (3 * a * k) * (pow(fabs(k) + sqrt(k * k - 1), 1.0 / 3) + pow(fabs(k) - sqrt(k * k - 1), 1.0 / 3)) - b / (3 * a);
		}
	}
	else if (dt == 0)
	{
		x1 = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);
	}
	else if (dt < 0)
	{
		x1 = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
	}

	if (dt >= 0 && fabs(k) <= 1)
	{
		if (a > 0)
		{
			if (x1 == x2)
			{
				// printf("X khac %lf, x > %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≥ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("X ≥ %lf", x1);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
			}
			else
			{
				// printf("%lf < X < %lf, X > %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≤ 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≥ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
		else
		{
			if (x1 == x2)
			{
				// printf("X <= %lf", x3);
				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≤ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf >= X, x = %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X = 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else
			{
				// printf("X < %lf, %lf < X < %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≥ 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≤ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
	}
	else
	{
		if (a > 0)
		{
			// printf("X > %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		else
		{
			// printf("X < %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
	}
}

static void disequation_3_4(GtkWidget *widget, GtkWidget *entry)
{
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");

	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0;

	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	a = convert_a_to_f((char *)text0);

	b = convert_b_to_f((char *)text0);

	c = convert_c_to_f((char *)text0);

	d = convert_d_to_f((char *)text0);

	double x1, x2, x3, temp;
	double dt = b * b - 3 * a * c;
	double k = (9 * a * b * c - 2 * pow(b, 3) - 27 * a * a * d) / (2 * sqrt(pow(fabs(dt), 3)));

	if (a == 0)
	{
		gtk_entry_set_text(GTK_ENTRY(o->entryA), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryB), "Math Error!");
		gtk_entry_set_text(GTK_ENTRY(o->entryC), "Math Error!");
		return;
	}

	if (dt > 0)
	{
		if (fabs(k) <= 1)
		{
			x1 = (2 * sqrt(dt) * cos(acos(k) / 3) - b) / (3 * a);
			x2 = (2 * sqrt(dt) * cos(acos(k) / 3 - 2 * PI / 3) - b) / (3 * a);
			x3 = (2 * sqrt(dt) * cos(acos(k) / 3 + 2 * PI / 3) - b) / (3 * a);
			if (x1 <= x2)
			{
				if (x2 >= x3)
				{
					temp = x2;
					if (x1 >= x3)
					{
						x2 = x1;
						x1 = x3;
					}
					else
					{
						x2 = x3;
					}
					x3 = temp;
				}
			}
			else
			{
				if (x2 >= x3)
				{
					temp = x1;
					x1 = x3;
					x3 = temp;
				}
				else
				{
					if (x1 <= x3)
					{
						temp = x1;
						x1 = x2;
						x2 = temp;
					}
				}
			}
		}
		else
		{
			x1 = (sqrt(dt) * fabs(k)) / (3 * a * k) * (pow(fabs(k) + sqrt(k * k - 1), 1.0 / 3) + pow(fabs(k) - sqrt(k * k - 1), 1.0 / 3)) - b / (3 * a);
		}
	}
	else if (dt == 0)
	{
		x1 = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);
	}
	else if (dt < 0)
	{
		x1 = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
	}

	if (dt >= 0 && fabs(k) <= 1)
	{
		if (a < 0)
		{
			if (x1 == x2)
			{
				// printf("X khac %lf, x > %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X = ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≥ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("X ≥ %lf", x1);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
			}
			else
			{
				// printf("%lf < X < %lf, X > %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≤ 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≥ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
		else
		{
			if (x1 == x2)
			{
				// printf("X <= %lf", x3);
				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≤ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else if (x2 == x3)
			{
				// printf("%lf >= X, x = %lf", x1, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X = 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X = ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
			else
			{
				// printf("X < %lf, %lf < X < %lf", x1, x2, x3);
				if (x1 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
				}
				else if (x1 < 0 && x1 > -1)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0 && x1 < 1)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 < 0)
				{
					x1 = x1 * -1;
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}
				else if (x1 > 0)
				{
					ftoa(x1, x1_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x1_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x1_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
				}

				/* ***************************************************************************************** */

				if (x2 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryB), "X ≥ 0");
				}
				else if (x2 < 0 && x2 > -1)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0 && x2 < 1)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 < 0)
				{
					x2 = x2 * -1;
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}
				else if (x2 > 0)
				{
					ftoa(x2, x2_ftoa, 9);

					char s1[10] = "X ≥ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x2_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x2_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
				}

				/* ***************************************************************************************** */

				if (x3 == 0)
				{
					gtk_entry_set_text(GTK_ENTRY(o->entryC), "X ≤ 0");
				}
				else if (x3 < 0 && x3 > -1)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0 && x3 < 1)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ 0";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 < 0)
				{
					x3 = x3 * -1;
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ -";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
				else if (x3 > 0)
				{
					ftoa(x3, x3_ftoa, 9);

					char s1[10] = "X ≤ ";
					int i, j, n1, n2;

					n1 = strlen(s1);
					n2 = strlen(x3_ftoa);
					j = 0;
					for (i = n1; i < (n1 + n2); i++)
					{
						s1[i] = x3_ftoa[j];
						j++;
					}

					s1[i] = '\0';

					gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
				}
			}
		}
	}
	else
	{
		if (a < 0)
		{
			// printf("X > %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≥ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≥ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
		else
		{
			// printf("X < %lf", x1);
			if (x1 == 0)
			{
				gtk_entry_set_text(GTK_ENTRY(o->entryA), "X ≤ 0");
			}
			else if (x1 < 0 && x1 > -1)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0 && x1 < 1)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ 0";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 < 0)
			{
				x1 = x1 * -1;
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ -";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
			else if (x1 > 0)
			{
				ftoa(x1, x1_ftoa, 9);

				char s1[10] = "X ≤ ";
				int i, j, n1, n2;

				n1 = strlen(s1);
				n2 = strlen(x1_ftoa);
				j = 0;
				for (i = n1; i < (n1 + n2); i++)
				{
					s1[i] = x1_ftoa[j];
					j++;
				}

				s1[i] = '\0';

				gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
			}
		}
	}
}

static void simul_equation_2(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	char x1_ftoa[1024], x2_ftoa[1024];
	double a = 0, b = 0, c = 0, g = 0, e = 0, f = 0;

	a = convert_a_to_f((char *)text0); // a1
	b = convert_b_to_f((char *)text0); // b1
	c = convert_c_to_f((char *)text0); // c1

	GtkTextIter start1, end1;
	GtkTextBuffer *buffer1 = gtk_text_view_get_buffer((GtkTextView *)o->textview1);
	gchar *text1;
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	text1 = gtk_text_buffer_get_text(buffer1, &start1, &end1, FALSE);

	e = convert_e_to_f((char *)text1); // a2
	f = convert_f_to_f((char *)text1); // b2
	g = convert_g_to_f((char *)text1); // c2

	float D, Dx, Dy, x1, x2;
	D = a * f - e * b;
	Dx = c * f - g * b;
	Dy = a * g - e * c;

	if (D == 0)
	{
		// nếu D = 0 và Dx + Dy = 0 thì phương trình vô số nghiệm, ngược lại thì vô nghiệm
		if (Dx + Dy == 0)
		{
			// printf("Hệ phương trình có vô số nghiệm");
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "Infinite Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "Infinite Solution");
		}
		else
		{
			// printf("Hệ phương trình vô nghiệm");
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution");
		}
	}
	else
	{
		x1 = Dx / D;

		// printf("Hệ phương trình có nghiệm (x1, x2) = (%.1f, %.1f)", x1, x2);

		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}

		/* ***************************************************************** */

		x2 = Dy / D;
		if (x2 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "Y = 0");
		}
		else if (x2 < 0 && x2 > -1)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0 && x2 < 1)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 < 0)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
	}
}

static void simul_equation_3(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	char x1_ftoa[1024], x2_ftoa[1024], x3_ftoa[1024];
	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0;

	a = convert_a_to_f((char *)text0); // a1
	b = convert_b_to_f((char *)text0); // b1
	c = convert_c_to_f((char *)text0); // c1
	d = convert_d_to_f((char *)text0); // d1

	GtkTextIter start1, end1;
	GtkTextBuffer *buffer1 = gtk_text_view_get_buffer((GtkTextView *)o->textview1);
	gchar *text1;
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	text1 = gtk_text_buffer_get_text(buffer1, &start1, &end1, FALSE);

	e = convert_e_to_f((char *)text1); // a2
	f = convert_f_to_f((char *)text1); // b2
	g = convert_g_to_f((char *)text1); // c2
	h = convert_h_to_f((char *)text1); // d2

	GtkTextIter start2, end2;
	GtkTextBuffer *buffer2 = gtk_text_view_get_buffer((GtkTextView *)o->textview2);
	gchar *text2;
	gtk_text_buffer_get_bounds(buffer2, &start2, &end2);
	text2 = gtk_text_buffer_get_text(buffer2, &start2, &end2, FALSE);

	i = convert_i_to_f((char *)text2); // a3
	j = convert_j_to_f((char *)text2); // b3
	k = convert_k_to_f((char *)text2); // c3
	l = convert_l_to_f((char *)text2); // d3

	float D, Dx, Dy, Dz, x1, x2, x3;
	D = a * f * k + b * g * i + e * j * c - c * f * i - b * e * k - a * j * g;
	Dx = d * f * k + b * g * l + h * j * c - c * f * l - b * h * k - g * j * d;
	Dy = a * h * k + d * g * i + e * l * c - c * h * i - d * e * k - g * l * a;
	Dz = a * f * l + b * h * i + e * j * d - d * f * i - b * e * l - h * j * a;

	if (D == 0)
	{
		if ((Dx == 0) && (Dy == 0) && (Dz == 0))
		{
			// printf("he vo so nghiem");
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "Infinite Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "Infinite Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryC), "Infinite Solution");
		}
		else
		{
			// printf("he vo nghiem");
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "No Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "No Solution");
			gtk_entry_set_text(GTK_ENTRY(o->entryC), "No Solution");
		}
	}
	else
	{
		// printf("he co nghiem la:\n x=%.2f \n y=%.2f \n z=%.2f", dx / d, dy / d, dz / d);
		x1 = Dx / D;
		if (x1 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryA), "X = 0");
		}
		else if (x1 < 0 && x1 > -1)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0 && x1 < 1)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 < 0)
		{
			x1 = x1 * -1;
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}
		else if (x1 > 0)
		{
			ftoa(x1, x1_ftoa, 9);

			char s1[10] = "X = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x1_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x1_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryA), s1);
		}

		/* ***************************************************************** */

		x2 = Dy / D;
		if (x2 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryB), "Y = 0");
		}
		else if (x2 < 0 && x2 > -1)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0 && x2 < 1)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 < 0)
		{
			x2 = x2 * -1;
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}
		else if (x2 > 0)
		{
			ftoa(x2, x2_ftoa, 9);

			char s1[10] = "Y = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x2_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x2_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryB), s1);
		}

		/* ***************************************************************** */

		x3 = Dz / D;
		if (x3 == 0)
		{
			gtk_entry_set_text(GTK_ENTRY(o->entryC), "Z = 0");
		}
		else if (x3 < 0 && x3 > -1)
		{
			x3 = x3 * -1;
			ftoa(x3, x3_ftoa, 9);

			char s1[10] = "Z = -0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x3_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x3_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
		}
		else if (x3 > 0 && x3 < 1)
		{
			ftoa(x3, x3_ftoa, 9);

			char s1[10] = "Z = 0";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x3_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x3_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
		}
		else if (x3 < 0)
		{
			x3 = x3 * -1;
			ftoa(x3, x3_ftoa, 9);

			char s1[10] = "Z = -";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x3_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x3_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
		}
		else if (x3 > 0)
		{
			ftoa(x3, x3_ftoa, 9);

			char s1[10] = "Z = ";
			int i, j, n1, n2;

			n1 = strlen(s1);
			n2 = strlen(x3_ftoa);
			j = 0;
			for (i = n1; i < (n1 + n2); i++)
			{
				s1[i] = x3_ftoa[j];
				j++;
			}

			s1[i] = '\0';

			gtk_entry_set_text(GTK_ENTRY(o->entryC), s1);
		}
	}
}

static gboolean on_draw_1(GtkWidget *widget, cairo_t *cr, gpointer user_data, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	double a = 0, b = 0;

	a = convert_a_to_f((char *)text0); // a
	b = convert_b_to_f((char *)text0); // b

	GdkRectangle da;
	gdouble dx = 5.0, dy = 5.0;
	gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
	GdkWindow *window = gtk_widget_get_window(widget);

	gdk_window_get_geometry(window,
							&da.x,
							&da.y,
							&da.width,
							&da.height);

	cairo_translate(cr, da.width / 2, da.height / 2);
	cairo_scale(cr, ZOOM_X, -ZOOM_Y);

	cairo_device_to_user_distance(cr, &dx, &dy);
	cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
	cairo_set_line_width(cr, dx);

	cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
	cairo_move_to(cr, clip_x1, 0.0);
	cairo_line_to(cr, clip_x2, 0.0);
	cairo_move_to(cr, 0.0, clip_y1);
	cairo_line_to(cr, 0.0, clip_y2);
	cairo_stroke(cr);

	for (i = clip_x1; i < clip_x2; i += dx)
		cairo_line_to(cr, i, a * i + b);

	cairo_set_source_rgba(cr, 1, 0.2, 0.2, 0.6);
	cairo_stroke(cr);

	return FALSE;
}

static void graph1(GtkWidget *widget, GtkWidget *entry)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Graph");
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_icon_name("accessories-calculator");

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=ax+b");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

	GtkWidget *draw;
	draw = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), draw);

	g_signal_connect(G_OBJECT(draw),
					 "draw",
					 G_CALLBACK(on_draw_1),
					 NULL);

	gtk_widget_show_all(window);
}

static gboolean on_draw_2(GtkWidget *widget, cairo_t *cr, gpointer user_data, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	double a = 0, b = 0, c = 0;

	a = convert_a_to_f((char *)text0); // a
	b = convert_b_to_f((char *)text0); // b
	c = convert_c_to_f((char *)text0); // c

	GdkRectangle da;
	gdouble dx = 5.0, dy = 5.0;
	gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
	GdkWindow *window = gtk_widget_get_window(widget);

	gdk_window_get_geometry(window,
							&da.x,
							&da.y,
							&da.width,
							&da.height);

	cairo_translate(cr, da.width / 2, da.height / 2);
	cairo_scale(cr, ZOOM_X, -ZOOM_Y);

	cairo_device_to_user_distance(cr, &dx, &dy);
	cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
	cairo_set_line_width(cr, dx);

	cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
	cairo_move_to(cr, clip_x1, 0.0);
	cairo_line_to(cr, clip_x2, 0.0);
	cairo_move_to(cr, 0.0, clip_y1);
	cairo_line_to(cr, 0.0, clip_y2);
	cairo_stroke(cr);

	for (i = clip_x1; i < clip_x2; i += dx)
		cairo_line_to(cr, i, a * pow(i, 2) + b * i + c);

	cairo_set_source_rgba(cr, 1, 0.2, 0.2, 0.6);
	cairo_stroke(cr);

	return FALSE;
}

static void graph2(GtkWidget *widget, GtkWidget *entry)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Graph");
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_icon_name("accessories-calculator");

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=ax^2+bx+c");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

	GtkWidget *draw;
	draw = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), draw);

	g_signal_connect(G_OBJECT(draw),
					 "draw",
					 G_CALLBACK(on_draw_2),
					 NULL);

	gtk_widget_show_all(window);
}

static gboolean on_draw_3(GtkWidget *widget, cairo_t *cr, gpointer user_data, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	double a = 0, b = 0;

	a = convert_a_to_f((char *)text0); // a
	b = convert_b_to_f((char *)text0); // b

	GdkRectangle da;
	gdouble dx = 5.0, dy = 5.0;
	gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
	GdkWindow *window = gtk_widget_get_window(widget);

	gdk_window_get_geometry(window,
							&da.x,
							&da.y,
							&da.width,
							&da.height);

	cairo_translate(cr, da.width / 2, da.height / 2);
	cairo_scale(cr, ZOOM_X, -ZOOM_Y);

	cairo_device_to_user_distance(cr, &dx, &dy);
	cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
	cairo_set_line_width(cr, dx);

	cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
	cairo_move_to(cr, clip_x1, 0.0);
	cairo_line_to(cr, clip_x2, 0.0);
	cairo_move_to(cr, 0.0, clip_y1);
	cairo_line_to(cr, 0.0, clip_y2);
	cairo_stroke(cr);

	for (i = clip_x1; i < clip_x2; i += dx)
		cairo_line_to(cr, i, sin(a * i + b));

	cairo_set_source_rgba(cr, 1, 0.2, 0.2, 0.6);
	cairo_stroke(cr);

	return FALSE;
}

static void graph3(GtkWidget *widget, GtkWidget *entry)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Graph");
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_icon_name("accessories-calculator");

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=sin(ax+b)");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

	GtkWidget *draw;
	draw = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), draw);

	g_signal_connect(G_OBJECT(draw),
					 "draw",
					 G_CALLBACK(on_draw_3),
					 NULL);

	gtk_widget_show_all(window);
}

static gboolean on_draw_4(GtkWidget *widget, cairo_t *cr, gpointer user_data, GtkWidget *entry)
{
	GtkTextIter start0, end0;
	GtkTextBuffer *buffer0 = gtk_text_view_get_buffer((GtkTextView *)o->textview0);
	gchar *text0;
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	text0 = gtk_text_buffer_get_text(buffer0, &start0, &end0, FALSE);

	double a = 0, b = 0;

	a = convert_a_to_f((char *)text0); // a
	b = convert_b_to_f((char *)text0); // b

	GdkRectangle da;
	gdouble dx = 5.0, dy = 5.0;
	gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
	GdkWindow *window = gtk_widget_get_window(widget);

	gdk_window_get_geometry(window,
							&da.x,
							&da.y,
							&da.width,
							&da.height);

	cairo_translate(cr, da.width / 2, da.height / 2);
	cairo_scale(cr, ZOOM_X, -ZOOM_Y);

	cairo_device_to_user_distance(cr, &dx, &dy);
	cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
	cairo_set_line_width(cr, dx);

	cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
	cairo_move_to(cr, clip_x1, 0.0);
	cairo_line_to(cr, clip_x2, 0.0);
	cairo_move_to(cr, 0.0, clip_y1);
	cairo_line_to(cr, 0.0, clip_y2);
	cairo_stroke(cr);

	for (i = clip_x1; i < clip_x2; i += dx)
		cairo_line_to(cr, i, cos(a * i + b));

	cairo_set_source_rgba(cr, 1, 0.2, 0.2, 0.6);
	cairo_stroke(cr);

	return FALSE;
}

static void graph4(GtkWidget *widget, GtkWidget *entry)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Graph");
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_icon_name("accessories-calculator");

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=cos(ax+b)");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

	GtkWidget *draw;
	draw = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), draw);

	g_signal_connect(G_OBJECT(draw),
					 "draw",
					 G_CALLBACK(on_draw_3),
					 NULL);

	gtk_widget_show_all(window);
}

void displayText1(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer0;
	GtkTextMark *mark0;
	GtkTextIter iter;
	const gchar *text0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry1));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry1));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);
}

void displayText2(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer0;
	GtkTextMark *mark0;
	GtkTextIter iter;
	const gchar *text0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry2));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry2));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);
}

void displayText3(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer0;
	GtkTextMark *mark0;
	GtkTextIter iter;
	const gchar *text0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry3));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry3));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);
}

void displayText4(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer0;
	GtkTextMark *mark0;
	GtkTextIter iter;
	const gchar *text0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry4));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	text0 = gtk_entry_get_text(GTK_ENTRY(o->entry4));

	mark0 = gtk_text_buffer_get_insert(buffer0);
	gtk_text_buffer_get_iter_at_mark(buffer0, &iter, mark0);
	gtk_text_buffer_insert(buffer0, &iter, text0, -1);
}

void displayText5(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer1;
	GtkTextMark *mark1;
	GtkTextIter iter;
	const gchar *text1;

	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry5));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry5));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);
}

void displayText6(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer1;
	GtkTextMark *mark1;
	GtkTextIter iter;
	const gchar *text1;

	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry6));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry6));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);
}

void displayText7(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer1;
	GtkTextMark *mark1;
	GtkTextIter iter;
	const gchar *text1;

	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry7));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry7));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);
}

void displayText8(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer1;
	GtkTextMark *mark1;
	GtkTextIter iter;
	const gchar *text1;

	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry8));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	text1 = gtk_entry_get_text(GTK_ENTRY(o->entry8));

	mark1 = gtk_text_buffer_get_insert(buffer1);
	gtk_text_buffer_get_iter_at_mark(buffer1, &iter, mark1);
	gtk_text_buffer_insert(buffer1, &iter, text1, -1);
}

void displayText9(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer2;
	GtkTextMark *mark2;
	GtkTextIter iter;
	const gchar *text2;

	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry9));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry9));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);
}

void displayText10(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer2;
	GtkTextMark *mark2;
	GtkTextIter iter;
	const gchar *text2;

	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry10));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry10));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);
}

void displayText11(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer2;
	GtkTextMark *mark2;
	GtkTextIter iter;
	const gchar *text2;

	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry11));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry11));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);
}

void displayText12(GtkWidget *widget, GtkWidget *entry)
{
	GtkTextBuffer *buffer2;
	GtkTextMark *mark2;
	GtkTextIter iter;
	const gchar *text2;

	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry12));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);

	gtk_entry_set_text(GTK_ENTRY(entry), " ");
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	text2 = gtk_entry_get_text(GTK_ENTRY(o->entry12));

	mark2 = gtk_text_buffer_get_insert(buffer2);
	gtk_text_buffer_get_iter_at_mark(buffer2, &iter, mark2);
	gtk_text_buffer_insert(buffer2, &iter, text2, -1);
}

static void button_clear_callback_1(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
}

static void button_clear_callback_2(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry4), "D = ");
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");
}

static void button_clear_callback_3(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	GtkTextBuffer *buffer1;
	GtkTextIter start1, end1;
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	gtk_text_buffer_delete(buffer1, &start1, &end1);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "A1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "B1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "C1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry5), "A2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry6), "B2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry7), "C2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
}

static void button_clear_callback_4(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	GtkTextBuffer *buffer1;
	GtkTextIter start1, end1;
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	gtk_text_buffer_delete(buffer1, &start1, &end1);

	GtkTextBuffer *buffer2;
	GtkTextIter start2, end2;
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview2));
	gtk_text_buffer_get_bounds(buffer2, &start2, &end2);
	gtk_text_buffer_delete(buffer2, &start2, &end2);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "A1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "B1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "C1 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry4), "D1 = ");

	gtk_entry_set_text(GTK_ENTRY(o->entry5), "A2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry6), "B2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry7), "C2 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry8), "D2 = ");

	gtk_entry_set_text(GTK_ENTRY(o->entry9), "A3 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry10), "B3 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry11), "C3 = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry12), "D3 = ");

	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");
}

static void button_clear_callback_5(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;
	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	GtkTextBuffer *buffer1;
	GtkTextIter start1, end1;
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview1));
	gtk_text_buffer_get_bounds(buffer1, &start1, &end1);
	gtk_text_buffer_delete(buffer1, &start1, &end1);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry5), "D = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry6), "E = ");
	gtk_entry_set_text(GTK_ENTRY(o->entryA), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryB), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryC), "");
	gtk_entry_set_text(GTK_ENTRY(o->entryD), "");
}

static void button_clear_callback_6(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 200);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");
}

static void button_clear_callback_7(GtkWidget *widget, GtkWidget *entry, gpointer data)
{
	GtkTextBuffer *buffer0;
	GtkTextIter start0, end0;

	buffer0 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(o->textview0));
	gtk_text_buffer_get_bounds(buffer0, &start0, &end0);
	gtk_text_buffer_delete(buffer0, &start0, &end0);

	gtk_window_set_default_size(GTK_WINDOW(window), 410, 200);

	gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");
	gtk_entry_set_text(GTK_ENTRY(o->entry3), "c = ");
}

typedef struct
{
	char *label;
	int sub_items;
	char sub_menu[6][30];
} MuButton;

MuButton menulist[] = {
	{"Polynomial", 3, {"Polynomial Degree 2", "Polynomial Degree 3", "Polynomial Degree 4"}},
	{"Simul Equation", 2, {"Simul Equation 2", "Simul Equation 3"}},
	{"Inequality", 2, {"Inequality Degree 2", "Inequality Degree 3"}},
	{"Graph", 4, {"y=ax+b", "y=ax^2+bx+c", "y=sin(ax+b)", "y=cos(ax+b)"}},
};

const int mLimit = 4;

void button_click(GtkWidget *button, gpointer data)
{
	char *btn = (char *)data;

	if (strcmp(btn, "Polynomial Degree 2") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Polynomial Degree 2");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Polynomial Degree 2");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 80);
		gtk_widget_set_size_request(o->entry1, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 160);
		gtk_widget_set_size_request(o->entry2, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 240);
		gtk_widget_set_size_request(o->entry3, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X1...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "X2...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 470);
		gtk_widget_set_size_request(o->entryA, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 550);
		gtk_widget_set_size_request(o->entryB, 355, 70);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);

		gtk_widget_show(o->textview0);

		GtkWidget *button_handle = gtk_button_new_with_label("Calculate");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 320);
		gtk_widget_set_size_request(button_handle, 178, 100);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 320);
		gtk_widget_set_size_request(button_clear, 177, 100);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_2), entry1);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_2), entry2);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_2), entry3);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_1), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Polynomial Degree 3") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Polynomial Degree 3");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Polynomial Degree 3");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		int text_width4 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entry4 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();
		o->entryC = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 80);
		gtk_widget_set_size_request(o->entry1, 355, 70);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 150);
		gtk_widget_set_size_request(o->entry2, 355, 70);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 220);
		gtk_widget_set_size_request(o->entry3, 355, 70);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry4, 20, 290);
		gtk_widget_set_size_request(o->entry4, 355, 70);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry4), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry4), text_width4);
		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry4), "D = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X1...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "X2...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryC), "X3...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);
		g_signal_connect_swapped(o->entry4, "activate", G_CALLBACK(displayText4), o->entry4);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 470);
		gtk_widget_set_size_request(o->entryA, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 540);
		gtk_widget_set_size_request(o->entryB, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryC, 20, 610);
		gtk_widget_set_size_request(o->entryC, 355, 70);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entry4);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);
		gtk_widget_show(o->entryC);

		gtk_widget_show(o->textview0);

		GtkWidget *button_handle = gtk_button_new_with_label("Calculate");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 360);
		gtk_widget_set_size_request(button_handle, 178, 100);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 360);
		gtk_widget_set_size_request(button_clear, 177, 100);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_3), entry1);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_3), entry2);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_3), entry3);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_3), entry4);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_2), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Polynomial Degree 4") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Polynomial Degree 4");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Polynomial Degree 4");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		int text_width5 = 42;
		int text_width6 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->textview1 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entry5 = gtk_entry_new();
		o->entry6 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();
		o->entryC = gtk_entry_new();
		o->entryD = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->textview1, 20, 60);
		gtk_widget_set_size_request(o->textview1, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 90);
		gtk_widget_set_size_request(o->entry1, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 140);
		gtk_widget_set_size_request(o->entry2, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 190);
		gtk_widget_set_size_request(o->entry3, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry5, 20, 240);
		gtk_widget_set_size_request(o->entry5, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry5), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry6, 20, 290);
		gtk_widget_set_size_request(o->entry6, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry6), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry5), text_width5);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry6), text_width6);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_text_view_set_monospace((GtkTextView *)o->textview1, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview1, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry5), "D = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry6), "E = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X1...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "X2...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryC), "X3...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryD), "X4...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);
		g_signal_connect_swapped(o->entry5, "activate", G_CALLBACK(displayText5), o->entry5);
		g_signal_connect_swapped(o->entry6, "activate", G_CALLBACK(displayText6), o->entry6);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 450);
		gtk_widget_set_size_request(o->entryA, 355, 50);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 500);
		gtk_widget_set_size_request(o->entryB, 355, 50);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryC, 20, 550);
		gtk_widget_set_size_request(o->entryC, 355, 50);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryD, 20, 600);
		gtk_widget_set_size_request(o->entryD, 355, 50);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entry5);
		gtk_widget_show(o->entry6);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);
		gtk_widget_show(o->entryC);
		gtk_widget_show(o->entryD);

		gtk_widget_show(o->textview0);
		gtk_widget_show(o->textview1);

		GtkWidget *button_handle = gtk_button_new_with_label("Calculate");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 340);
		gtk_widget_set_size_request(button_handle, 178, 90);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 340);
		gtk_widget_set_size_request(button_clear, 177, 90);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_4), entry1);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_4), entry2);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_4), entry3);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_4), entry5);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(equation_4), entry6);

		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_5), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Inequality Degree 2") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Inequality Degree 2");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Inequality Degree 2");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 80);
		gtk_widget_set_size_request(o->entry1, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 160);
		gtk_widget_set_size_request(o->entry2, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 240);
		gtk_widget_set_size_request(o->entry3, 355, 80);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X1...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "X2...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 470);
		gtk_widget_set_size_request(o->entryA, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 550);
		gtk_widget_set_size_request(o->entryB, 355, 70);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);

		gtk_widget_show(o->textview0);

		GtkWidget *button_handle_1 = gtk_button_new_with_label(">");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_1, 20, 320);
		gtk_widget_set_size_request(button_handle_1, 178, 10);

		GtkWidget *button_handle_2 = gtk_button_new_with_label("<");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_2, 20, 355);
		gtk_widget_set_size_request(button_handle_2, 178, 10);

		GtkWidget *button_handle_3 = gtk_button_new_with_label("≥");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_3, 20, 390);
		gtk_widget_set_size_request(button_handle_3, 178, 10);

		GtkWidget *button_handle_4 = gtk_button_new_with_label("≤");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_4, 20, 425);
		gtk_widget_set_size_request(button_handle_4, 178, 10);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 320);
		gtk_widget_set_size_request(button_clear, 177, 140);

		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_2_1), entry1);
		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_2_1), entry2);
		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_2_1), entry3);

		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_2_2), entry1);
		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_2_2), entry2);
		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_2_2), entry3);

		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_2_3), entry1);
		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_2_3), entry2);
		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_2_3), entry3);

		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_2_4), entry1);
		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_2_4), entry2);
		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_2_4), entry3);

		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_1), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Inequality Degree 3") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Inequality Degree 3");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Inequality Degree 3");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		int text_width4 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entry4 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();
		o->entryC = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 80);
		gtk_widget_set_size_request(o->entry1, 355, 60);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 140);
		gtk_widget_set_size_request(o->entry2, 355, 60);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 200);
		gtk_widget_set_size_request(o->entry3, 355, 60);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry4, 20, 260);
		gtk_widget_set_size_request(o->entry4, 355, 60);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry4), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry4), text_width4);
		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry4), "D = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X1...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "X2...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryC), "X3...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);
		g_signal_connect_swapped(o->entry4, "activate", G_CALLBACK(displayText4), o->entry4);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 470);
		gtk_widget_set_size_request(o->entryA, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 540);
		gtk_widget_set_size_request(o->entryB, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryC, 20, 610);
		gtk_widget_set_size_request(o->entryC, 355, 70);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entry4);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);
		gtk_widget_show(o->entryC);

		gtk_widget_show(o->textview0);

		GtkWidget *button_handle_1 = gtk_button_new_with_label(">");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_1, 20, 320);
		gtk_widget_set_size_request(button_handle_1, 178, 10);

		GtkWidget *button_handle_2 = gtk_button_new_with_label("<");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_2, 20, 355);
		gtk_widget_set_size_request(button_handle_2, 178, 10);

		GtkWidget *button_handle_3 = gtk_button_new_with_label("≥");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_3, 20, 390);
		gtk_widget_set_size_request(button_handle_3, 178, 10);

		GtkWidget *button_handle_4 = gtk_button_new_with_label("≤");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle_4, 20, 425);
		gtk_widget_set_size_request(button_handle_4, 178, 10);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 320);
		gtk_widget_set_size_request(button_clear, 177, 140);

		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_3_1), entry1);
		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_3_1), entry2);
		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_3_1), entry3);
		g_signal_connect(button_handle_1, "clicked", G_CALLBACK(disequation_3_1), entry4);

		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_3_2), entry1);
		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_3_2), entry2);
		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_3_2), entry3);
		g_signal_connect(button_handle_2, "clicked", G_CALLBACK(disequation_3_2), entry4);

		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_3_3), entry1);
		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_3_3), entry2);
		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_3_3), entry3);
		g_signal_connect(button_handle_3, "clicked", G_CALLBACK(disequation_3_3), entry4);

		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_3_4), entry1);
		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_3_4), entry2);
		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_3_4), entry3);
		g_signal_connect(button_handle_4, "clicked", G_CALLBACK(disequation_3_4), entry4);

		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_2), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Simul Equation 2") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Simul Equation 2");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Simul Equation 2");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		int text_width5 = 42;
		int text_width6 = 42;
		int text_width7 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->textview1 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entry5 = gtk_entry_new();
		o->entry6 = gtk_entry_new();
		o->entry7 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->textview1, 20, 60);
		gtk_widget_set_size_request(o->textview1, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 90);
		gtk_widget_set_size_request(o->entry1, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 140);
		gtk_widget_set_size_request(o->entry2, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 190);
		gtk_widget_set_size_request(o->entry3, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry5, 20, 240);
		gtk_widget_set_size_request(o->entry5, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry5), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry6, 20, 290);
		gtk_widget_set_size_request(o->entry6, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry6), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry7, 20, 340);
		gtk_widget_set_size_request(o->entry7, 355, 50);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry7), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry5), text_width5);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry6), text_width6);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry7), text_width7);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_text_view_set_monospace((GtkTextView *)o->textview1, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview1, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry5), "A2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry6), "B2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry7), "C2 = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "Y...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);
		g_signal_connect_swapped(o->entry5, "activate", G_CALLBACK(displayText5), o->entry5);
		g_signal_connect_swapped(o->entry6, "activate", G_CALLBACK(displayText6), o->entry6);
		g_signal_connect_swapped(o->entry7, "activate", G_CALLBACK(displayText7), o->entry7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 500);
		gtk_widget_set_size_request(o->entryA, 355, 70);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 570);
		gtk_widget_set_size_request(o->entryB, 355, 70);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entry5);
		gtk_widget_show(o->entry6);
		gtk_widget_show(o->entry7);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);

		gtk_widget_show(o->textview0);
		gtk_widget_show(o->textview1);

		GtkWidget *button_handle = gtk_button_new_with_label("Calculate");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 390);
		gtk_widget_set_size_request(button_handle, 178, 90);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 390);
		gtk_widget_set_size_request(button_clear, 177, 90);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry1);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry2);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry3);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry5);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry6);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_2), entry7);

		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_3), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "Simul Equation 3") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "Simul Equation 3");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 700);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Simul Equation 3");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;
		int text_width4 = 42;
		int text_width5 = 42;
		int text_width6 = 42;
		int text_width7 = 42;
		int text_width8 = 42;
		int text_width9 = 42;
		int text_width10 = 42;
		int text_width11 = 42;
		int text_width12 = 42;
		o = g_slice_new(Widget);

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o->textview0 = gtk_text_view_new();
		o->textview1 = gtk_text_view_new();
		o->textview2 = gtk_text_view_new();
		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();
		o->entry4 = gtk_entry_new();
		o->entry5 = gtk_entry_new();
		o->entry6 = gtk_entry_new();
		o->entry7 = gtk_entry_new();
		o->entry8 = gtk_entry_new();
		o->entry9 = gtk_entry_new();
		o->entry10 = gtk_entry_new();
		o->entry11 = gtk_entry_new();
		o->entry12 = gtk_entry_new();
		o->entryA = gtk_entry_new();
		o->entryB = gtk_entry_new();
		o->entryC = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 30);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->textview1, 20, 50);
		gtk_widget_set_size_request(o->textview1, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->textview2, 20, 70);
		gtk_widget_set_size_request(o->textview2, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 100);
		gtk_widget_set_size_request(o->entry1, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 134);
		gtk_widget_set_size_request(o->entry2, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 168);
		gtk_widget_set_size_request(o->entry3, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry4, 20, 202);
		gtk_widget_set_size_request(o->entry4, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry4), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry5, 20, 241);
		gtk_widget_set_size_request(o->entry5, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry5), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry6, 20, 275);
		gtk_widget_set_size_request(o->entry6, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry6), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry7, 20, 309);
		gtk_widget_set_size_request(o->entry7, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry7), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry8, 20, 343);
		gtk_widget_set_size_request(o->entry8, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry8), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry9, 20, 382);
		gtk_widget_set_size_request(o->entry9, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry9), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry10, 20, 416);
		gtk_widget_set_size_request(o->entry10, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry10), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry11, 20, 450);
		gtk_widget_set_size_request(o->entry11, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry11), 37);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry12, 20, 484);
		gtk_widget_set_size_request(o->entry12, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry12), 37);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry4), text_width4);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry5), text_width5);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry6), text_width6);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry7), text_width7);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry8), text_width8);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry9), text_width9);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry10), text_width10);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry11), text_width11);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry12), text_width12);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_text_view_set_monospace((GtkTextView *)o->textview1, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview1, GTK_JUSTIFY_CENTER);

		gtk_text_view_set_monospace((GtkTextView *)o->textview2, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview2, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "A1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "B1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "C1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry4), "D1 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry5), "A2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry6), "B2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry7), "C2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry8), "D2 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry9), "A3 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry10), "B3 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry11), "C3 = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry12), "D3 = ");

		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryA), "X...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryB), "Y...");
		gtk_entry_set_placeholder_text(GTK_ENTRY(o->entryC), "Z...");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);
		g_signal_connect_swapped(o->entry4, "activate", G_CALLBACK(displayText4), o->entry4);
		g_signal_connect_swapped(o->entry5, "activate", G_CALLBACK(displayText5), o->entry5);
		g_signal_connect_swapped(o->entry6, "activate", G_CALLBACK(displayText6), o->entry6);
		g_signal_connect_swapped(o->entry7, "activate", G_CALLBACK(displayText7), o->entry7);
		g_signal_connect_swapped(o->entry8, "activate", G_CALLBACK(displayText8), o->entry8);
		g_signal_connect_swapped(o->entry9, "activate", G_CALLBACK(displayText9), o->entry9);
		g_signal_connect_swapped(o->entry10, "activate", G_CALLBACK(displayText10), o->entry10);
		g_signal_connect_swapped(o->entry11, "activate", G_CALLBACK(displayText11), o->entry11);
		g_signal_connect_swapped(o->entry12, "activate", G_CALLBACK(displayText12), o->entry12);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryA, 20, 580);
		gtk_widget_set_size_request(o->entryA, 355, 30);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryB, 20, 614);
		gtk_widget_set_size_request(o->entryB, 355, 30);

		gtk_fixed_put(GTK_FIXED(fixed), o->entryC, 20, 648);
		gtk_widget_set_size_request(o->entryC, 355, 30);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->entry4);
		gtk_widget_show(o->entry5);
		gtk_widget_show(o->entry6);
		gtk_widget_show(o->entry7);
		gtk_widget_show(o->entry8);
		gtk_widget_show(o->entry9);
		gtk_widget_show(o->entry10);
		gtk_widget_show(o->entry11);
		gtk_widget_show(o->entry12);
		gtk_widget_show(o->entryA);
		gtk_widget_show(o->entryB);
		gtk_widget_show(o->entryC);

		gtk_widget_show(o->textview0);
		gtk_widget_show(o->textview1);
		gtk_widget_show(o->textview2);

		GtkWidget *button_handle = gtk_button_new_with_label("Calculate");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 518);
		gtk_widget_set_size_request(button_handle, 178, 50);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 518);
		gtk_widget_set_size_request(button_clear, 177, 50);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry1);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry2);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry3);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry4);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry5);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry6);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry7);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry8);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry9);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry10);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry11);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(simul_equation_3), entry12);

		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_4), NULL);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "y=ax+b") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "y=ax+b");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 200);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=ax+b");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o = g_slice_new(Widget);
		o->textview0 = gtk_text_view_new();

		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 10);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 50);
		gtk_widget_set_size_request(o->entry1, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 90);
		gtk_widget_set_size_request(o->entry2, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 7);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);

		GtkWidget *button_handle = gtk_button_new_with_label("Draw");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 130);
		gtk_widget_set_size_request(button_handle, 178, 50);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 130);
		gtk_widget_set_size_request(button_clear, 177, 50);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->textview0);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(graph1), NULL);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_6), window);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(kill_window), window);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "y=ax^2+bx+c") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "y=ax^2+bx+c");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 250);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=ax^2+bx+c");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;
		int text_width3 = 42;

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o = g_slice_new(Widget);
		o->textview0 = gtk_text_view_new();

		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();
		o->entry3 = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 10);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 50);
		gtk_widget_set_size_request(o->entry1, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 90);
		gtk_widget_set_size_request(o->entry2, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry3, 20, 130);
		gtk_widget_set_size_request(o->entry3, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry3), 7);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry3), text_width3);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry3), "c = ");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);
		g_signal_connect_swapped(o->entry3, "activate", G_CALLBACK(displayText3), o->entry3);

		GtkWidget *button_handle = gtk_button_new_with_label("Draw");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 170);
		gtk_widget_set_size_request(button_handle, 178, 50);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 170);
		gtk_widget_set_size_request(button_clear, 177, 50);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->entry3);
		gtk_widget_show(o->textview0);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(graph2), NULL);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_7), window);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(kill_window), window);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "y=sin(ax+b)") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "y=sin(ax+b)");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 200);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=sin(ax+b)");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o = g_slice_new(Widget);
		o->textview0 = gtk_text_view_new();

		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 10);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 50);
		gtk_widget_set_size_request(o->entry1, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 90);
		gtk_widget_set_size_request(o->entry2, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 7);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);

		GtkWidget *button_handle = gtk_button_new_with_label("Draw");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 130);
		gtk_widget_set_size_request(button_handle, 178, 50);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 130);
		gtk_widget_set_size_request(button_clear, 177, 50);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->textview0);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(graph3), NULL);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_6), window);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(kill_window), window);

		gtk_widget_show_all(window);
	}
	else if (strcmp(btn, "y=cos(ax+b)") == 0)
	{
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(window), "y=cos(ax+b)");
		gtk_window_set_modal(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_size(GTK_WINDOW(window), 410, 200);
		gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
		gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
		gtk_window_set_default_icon_name("accessories-calculator");

		GtkWidget *headerBar = gtk_header_bar_new();
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
		gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "y=cos(ax+b)");

		GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
		gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
		g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

		int text_width1 = 42;
		int text_width2 = 42;

		GtkWidget *fixed;
		fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window), fixed);

		o = g_slice_new(Widget);
		o->textview0 = gtk_text_view_new();

		o->entry1 = gtk_entry_new();
		o->entry2 = gtk_entry_new();

		gtk_fixed_put(GTK_FIXED(fixed), o->textview0, 20, 10);
		gtk_widget_set_size_request(o->textview0, 0, 20);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry1, 20, 50);
		gtk_widget_set_size_request(o->entry1, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry1), 7);

		gtk_fixed_put(GTK_FIXED(fixed), o->entry2, 20, 90);
		gtk_widget_set_size_request(o->entry2, 355, 30);
		gtk_entry_set_max_length(GTK_ENTRY(o->entry2), 7);

		gtk_entry_set_width_chars(GTK_ENTRY(o->entry1), text_width1);
		gtk_entry_set_width_chars(GTK_ENTRY(o->entry2), text_width2);

		gtk_text_view_set_monospace((GtkTextView *)o->textview0, TRUE);
		gtk_text_view_set_justification((GtkTextView *)o->textview0, GTK_JUSTIFY_CENTER);

		gtk_entry_set_text(GTK_ENTRY(o->entry1), "a = ");
		gtk_entry_set_text(GTK_ENTRY(o->entry2), "b = ");

		g_signal_connect_swapped(o->entry1, "activate", G_CALLBACK(displayText1), o->entry1);
		g_signal_connect_swapped(o->entry2, "activate", G_CALLBACK(displayText2), o->entry2);

		GtkWidget *button_handle = gtk_button_new_with_label("Draw");
		gtk_fixed_put(GTK_FIXED(fixed), button_handle, 20, 130);
		gtk_widget_set_size_request(button_handle, 178, 50);

		GtkWidget *button_clear = gtk_button_new_with_label("Clear");
		gtk_fixed_put(GTK_FIXED(fixed), button_clear, 198, 130);
		gtk_widget_set_size_request(button_clear, 177, 50);

		gtk_widget_show(o->entry1);
		gtk_widget_show(o->entry2);
		gtk_widget_show(o->textview0);

		g_signal_connect(button_handle, "clicked", G_CALLBACK(graph4), NULL);
		g_signal_connect(button_clear, "clicked", G_CALLBACK(button_clear_callback_6), window);
		g_signal_connect(button_handle, "clicked", G_CALLBACK(kill_window), window);

		gtk_widget_show_all(window);
	}
}

void make_menu(GtkWidget *fixed)
{
	GtkWidget *menubar;
	menubar = gtk_menu_bar_new();

	gtk_fixed_put(GTK_FIXED(fixed), menubar, 31, -1);

	for (int index = 0; index < mLimit; index++)
	{
		GtkWidget *item;
		item = gtk_menu_item_new_with_label(menulist[index].label);

		GtkWidget *item_menu;
		item_menu = gtk_menu_new();
		gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item);
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), item_menu);

		int limit = menulist[index].sub_items;
		for (int loop = 0; loop < limit; loop++)
		{
			GtkWidget *subitem;
			subitem = gtk_menu_item_new_with_label(menulist[index].sub_menu[loop]);
			g_signal_connect(GTK_WIDGET(subitem), "activate",
							 G_CALLBACK(button_click),
							 menulist[index].sub_menu[loop]);
			gtk_menu_shell_append(GTK_MENU_SHELL(item_menu), subitem);
		}
	}

	// gtk_container_add(GTK_CONTAINER(fixed), menubar);
}

static void activate()
{
	int text_width = 42;
	char *num;
	w = g_slice_new(Widgets);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Casio 590 VN Plus");
	gtk_window_set_default_size(GTK_WINDOW(window), 507, 770);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 50);
	gtk_window_set_default_icon_name("accessories-calculator");

	GtkWidget *fixed;
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	make_menu(fixed);

	// create a text box and textview

	w->textview = gtk_text_view_new();
	w->entry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(w->entry), "Enter Expression");
	gtk_fixed_put(GTK_FIXED(fixed), w->textview, 26, 40);
	gtk_widget_set_size_request(w->textview, 0, 0);
	gtk_fixed_put(GTK_FIXED(fixed), w->entry, 26, 80);
	gtk_entry_set_max_length(GTK_ENTRY(w->entry), 37);
	gtk_entry_set_width_chars(GTK_ENTRY(w->entry), text_width);
	gtk_text_view_set_monospace((GtkTextView *)w->textview, TRUE);
	gtk_text_view_set_justification((GtkTextView *)w->textview, GTK_JUSTIFY_CENTER);
	gtk_widget_show(w->entry);
	gtk_widget_show(w->textview);

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "Casio 590 VN Plus");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);

	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);

	// creating a button
	GtkWidget *button[40];
	char *button_labels[] = {
		"abs", "↑", "↓", "%", ",",
		"∫", "sin", "cos", "tan", "cot",
		"^", "√", "ln", "log", "!",
		"(", ")", "π", "L", "G",
		"7", "8", "9", "DEL", "AC",
		"4", "5", "6", "x", "/",
		"1", "2", "3", "+", "-",
		"0", ".", "e", "Ans", "="};
	int i;
	int j;
	int a = 0;
	int b = 0;
	for (i = 0; i <= 4; i++)
	{
		for (j = i; j <= i + 35; j += 5)
		{
			button[j] = gtk_button_new_with_label(button_labels[j]);
			gtk_fixed_put(GTK_FIXED(fixed), button[j], 20 + a, 150 + b);
			b += 70;
		}
		a += 80;
		b = 0;
	}

	g_signal_connect(button[0], "clicked", G_CALLBACK(Setabs), (gpointer) "| ");
	g_signal_connect(button[1], "clicked", G_CALLBACK(setceil), (gpointer) "↑ ");
	g_signal_connect(button[2], "clicked", G_CALLBACK(setfloor), (gpointer) "↓ ");
	g_signal_connect(button[3], "clicked", G_CALLBACK(clicked), (gpointer) "%");
	g_signal_connect(button[4], "clicked", G_CALLBACK(clicked), (gpointer) ",");
	g_signal_connect(button[5], "clicked", G_CALLBACK(setsin), (gpointer) "∫");
	g_signal_connect(button[6], "clicked", G_CALLBACK(setsin), (gpointer) "sin( ");
	g_signal_connect(button[7], "clicked", G_CALLBACK(setcos), (gpointer) "cos( ");
	g_signal_connect(button[8], "clicked", G_CALLBACK(settan), (gpointer) "tan( ");
	g_signal_connect(button[9], "clicked", G_CALLBACK(setcot), (gpointer) "cot( ");
	g_signal_connect(button[10], "clicked", G_CALLBACK(clicked), (gpointer) "^");
	g_signal_connect(button[11], "clicked", G_CALLBACK(Setroot), (gpointer) "√ ");
	g_signal_connect(button[12], "clicked", G_CALLBACK(setln), (gpointer) "ln( ");
	g_signal_connect(button[13], "clicked", G_CALLBACK(setlog), (gpointer) "log( ");
	g_signal_connect(button[14], "clicked", G_CALLBACK(clicked), (gpointer) "!");
	g_signal_connect(button[15], "clicked", G_CALLBACK(clicked), (gpointer) "( ");
	g_signal_connect(button[16], "clicked", G_CALLBACK(clicked), (gpointer) " )");
	g_signal_connect(button[17], "clicked", G_CALLBACK(clicked), (gpointer) "P");
	g_signal_connect(button[18], "clicked", G_CALLBACK(setLCM), (gpointer) "LCM( ");
	g_signal_connect(button[19], "clicked", G_CALLBACK(setGCD), (gpointer) "GCD( ");
	g_signal_connect(button[20], "clicked", G_CALLBACK(clicked), (gpointer) "7");
	g_signal_connect(button[21], "clicked", G_CALLBACK(clicked), (gpointer) "8");
	g_signal_connect(button[22], "clicked", G_CALLBACK(clicked), (gpointer) "9");
	// g_signal_connect (button[23], "clicked", G_CALLBACK (delete), NULL);
	g_signal_connect(button[24], "clicked", G_CALLBACK(clear), NULL);
	g_signal_connect(button[25], "clicked", G_CALLBACK(clicked), (gpointer) "4");
	g_signal_connect(button[26], "clicked", G_CALLBACK(clicked), (gpointer) "5");
	g_signal_connect(button[27], "clicked", G_CALLBACK(clicked), (gpointer) "6");
	g_signal_connect(button[28], "clicked", G_CALLBACK(clicked), (gpointer) "*");
	g_signal_connect(button[29], "clicked", G_CALLBACK(clicked), (gpointer) "/");
	g_signal_connect(button[30], "clicked", G_CALLBACK(clicked), (gpointer) "1");
	g_signal_connect(button[31], "clicked", G_CALLBACK(clicked), (gpointer) "2");
	g_signal_connect(button[32], "clicked", G_CALLBACK(clicked), (gpointer) "3");
	g_signal_connect(button[33], "clicked", G_CALLBACK(clicked), (gpointer) "+");
	g_signal_connect(button[34], "clicked", G_CALLBACK(clicked), (gpointer) "-");
	g_signal_connect(button[35], "clicked", G_CALLBACK(clicked), (gpointer) "0");
	g_signal_connect(button[36], "clicked", G_CALLBACK(clicked), (gpointer) ".");
	g_signal_connect(button[37], "clicked", G_CALLBACK(clicked), (gpointer) "e");
	g_signal_connect(button[38], "clicked", G_CALLBACK(setAns), (gpointer) "Ans");
	g_signal_connect(button[39], "clicked", G_CALLBACK(equal), entry);

	gtk_widget_show_all(window);
}

void about_dialog_clbk()
{
	GtkWidget *aboutDialog = gtk_about_dialog_new();
	gtk_window_set_title(GTK_WINDOW(aboutDialog), "About Dialog");
	gtk_window_set_modal(GTK_WINDOW(aboutDialog), TRUE);
	gtk_window_set_position(GTK_WINDOW(aboutDialog), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_default_size(GTK_WINDOW(aboutDialog), 700, 400);
	gtk_window_set_resizable(GTK_WINDOW(aboutDialog), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(aboutDialog), 10);

	const gchar *authors[] = {"Dương Hoàng Nam", "Lê Tuấn Anh", NULL};
	const gchar *artists[] = {"Dương Hoàng Nam", "Lê Tuấn Anh", NULL};
	const gchar *documenters[] = {"Lý Tuấn Kiệt", "Trần Minh Khang", "GNOME", "Gtk - 3.0", NULL};

	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(aboutDialog), "Calculator");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(aboutDialog), "1.0.0");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(aboutDialog), " Project C 13/03/2022");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(aboutDialog), "AnhNamEntertainment");
	gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(aboutDialog), "License");
	gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(aboutDialog), TRUE);
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(aboutDialog), GTK_LICENSE_GPL_3_0_ONLY);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(aboutDialog), "https://www.facebook.com/fcodefpt");
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(aboutDialog), "F-CODE");
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(aboutDialog), authors);
	gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG(aboutDialog), artists);
	gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG(aboutDialog), documenters);
	gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(aboutDialog), "accessories-calculator-symbolic");

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "About Dialog");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);
	gtk_window_set_titlebar(GTK_WINDOW(aboutDialog), headerBar);

	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), aboutDialog);

	gtk_widget_show_all(aboutDialog);
}

void about_us()
{
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "About Us");
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_default_size(GTK_WINDOW(window), 700, 400);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	GtkWidget *headerBar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerBar), TRUE);
	gtk_header_bar_set_title(GTK_HEADER_BAR(headerBar), "About Us");

	GtkWidget *back_button = gtk_button_new_with_mnemonic("Back");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), back_button);

	GtkWidget *aboutDialog = gtk_button_new_with_mnemonic("Dialog");
	gtk_header_bar_pack_end(GTK_HEADER_BAR(headerBar), aboutDialog);

	gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);

	GtkWidget *fixed;
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	GtkWidget *label1;
	label1 = gtk_label_new(NULL);
	gtk_widget_set_size_request(label1, 0, 0);
	gtk_label_set_markup(GTK_LABEL(label1), "<span weight='ultralight' style=\"normal\" font='40px' color='black'>          MEMBER OF CLUB F-CODE</span>");
	gtk_container_add(GTK_CONTAINER(fixed), label1);

	GtkWidget *label2;
	label2 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label2), "<span weight='light' style=\"oblique\" font='25px' color='black'>LÊ TUẤN ANH</span>");
	gtk_fixed_put(GTK_FIXED(fixed), label2, 265, 80);

	GtkWidget *label3;
	label3 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label3), "<span weight='light' style=\"oblique\" font='20px' color='black'>SE140478</span>");
	gtk_fixed_put(GTK_FIXED(fixed), label3, 297, 110);

	GtkWidget *label4;
	label4 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label4), "<span weight='light' style=\"oblique\" font='25px' color='black'>DƯƠNG HOÀNG NAM</span>");
	gtk_fixed_put(GTK_FIXED(fixed), label4, 215, 210);

	GtkWidget *label5;
	label5 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label5), "<span weight='light' style=\"oblique\" font='20px' color='black'>SE172173</span>");
	gtk_fixed_put(GTK_FIXED(fixed), label5, 297, 240);

	GtkWidget *linkButtonA1;
	const gchar *const uriA1 = "https://www.facebook.com/anhlt.2403";
	const gchar *labelA1 = "Facebook";
	linkButtonA1 = gtk_link_button_new_with_label(uriA1, labelA1);
	gtk_fixed_put(GTK_FIXED(fixed), linkButtonA1, 260, 140);

	GtkWidget *linkButtonA2;
	const gchar *const uriA2 = "file:///C:/Users/namdh/Downloads/SE170478.pdf";
	const gchar *labelA2 = "Profile";
	linkButtonA2 = gtk_link_button_new_with_label(uriA2, labelA2);
	gtk_fixed_put(GTK_FIXED(fixed), linkButtonA2, 336, 140);

	GtkWidget *linkButtonB1;
	const gchar *const uriB1 = "https://www.facebook.com/namdh03/";
	const gchar *labelB1 = "Facebook";
	linkButtonB1 = gtk_link_button_new_with_label(uriB1, labelB1);
	gtk_fixed_put(GTK_FIXED(fixed), linkButtonB1, 220, 270);

	GtkWidget *linkButtonB2;
	const gchar *const uriB2 = "https://www.instagram.com/namdh03/";
	const gchar *labelB2 = "Instagram";
	linkButtonB2 = gtk_link_button_new_with_label(uriB2, labelB2);
	gtk_fixed_put(GTK_FIXED(fixed), linkButtonB2, 296, 270);

	GtkWidget *linkButtonB3;
	const gchar *const uriB3 = "file:///C:/Users/namdh/Downloads/SE172173.pdf";
	const gchar *labelB3 = "Profile";
	linkButtonB3 = gtk_link_button_new_with_label(uriB3, labelB3);
	gtk_fixed_put(GTK_FIXED(fixed), linkButtonB3, 372, 270);

	g_signal_connect(linkButtonA1, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(linkButtonA2, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(linkButtonB1, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(linkButtonB2, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(linkButtonB3, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(back_button, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(aboutDialog, "clicked", G_CALLBACK(kill_window), window);
	g_signal_connect(aboutDialog, "clicked", G_CALLBACK(about_dialog_clbk), window);

	gtk_widget_show_all(window);
}

void main_screen()
{
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Casio 590 VN Plus");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 50);
	g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
	g_signal_connect(window, "destroy", gtk_main_quit, NULL);

	// const gchar *const icon_name = "icon.png";
	// GError *err = NULL;
	// GdkPixbuf *icon_app = gdk_pixbuf_new_from_file(icon_name, &err);
	// gtk_window_set_default_icon(icon_app);

	gtk_window_set_default_icon_name("accessories-calculator-symbolic");

	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add(GTK_CONTAINER(window), box);

	GtkWidget *toolbar = gtk_toolbar_new();
	gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, FALSE, 5);
	gtk_toolbar_set_show_arrow(GTK_TOOLBAR(toolbar), FALSE);
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);
	gtk_toolbar_set_icon_size(GTK_TOOLBAR(toolbar), GTK_ICON_SIZE_DIALOG);

	GtkWidget *icon_1 = gtk_image_new_from_icon_name("accessories-calculator-symbolic", GTK_ICON_SIZE_DIALOG);
	GtkWidget *icon_2 = gtk_image_new_from_icon_name("help-about-symbolic", GTK_ICON_SIZE_DIALOG);
	GtkWidget *icon_3 = gtk_image_new_from_icon_name("application-exit-symbolic", GTK_ICON_SIZE_DIALOG);

	GtkToolItem *tool_item_1 = gtk_tool_button_new(icon_1, "Calculator");
	GtkToolItem *tool_item_2 = gtk_tool_button_new(icon_2, "About Us");
	GtkToolItem *tool_item_3 = gtk_tool_button_new(icon_3, "Quit");

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_item_1, 0);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_item_2, 1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_item_3, 2);

	gtk_orientable_set_orientation(GTK_ORIENTABLE(toolbar), GTK_ORIENTATION_VERTICAL);

	g_signal_connect_swapped(tool_item_1, "clicked", G_CALLBACK(activate), window);
	g_signal_connect_swapped(tool_item_2, "clicked", G_CALLBACK(about_us), window);
	g_signal_connect(tool_item_3, "clicked", G_CALLBACK(close_window), window);

	// g_signal_connect(tool_item_1, "clicked", G_CALLBACK(activate), window);
	// g_signal_connect(tool_item_1, "clicked", G_CALLBACK(kill_window), window);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	load_css();
	main_screen();
	gtk_main();
	return 0;
}