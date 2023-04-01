#include <stdlib.h>
#include <gtk/gtk.h>
#include <math.h>
#include <string.h>
#include <stdio.h>


double a, b; /*Define two variables involved in the operation, double precision*/
double p;
int hasdot; /*Whether there is a decimal point*/
int method; /*Used to distinguish different operations*/
int principle; /*Identify different bases*/
char out[20]; /*Output result*/

GtkWidget *window;
GtkWidget *box;

GtkWidget *widget;
GtkWidget *grid;
GtkWidget *radio_buttons; /*Grid For Radio Buttons*/
GtkWidget *entry;/*Text Box*/

GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
GtkWidget *label5;
GtkWidget *label6;

GtkWidget *radio1;
GtkWidget *radio2;
GtkWidget *radio3;
GtkWidget *radio4;

/*buttons*/
GtkWidget *button0;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *button10;
GtkWidget *button11;
GtkWidget *button12;
GtkWidget *button13;
GtkWidget *button14;
GtkWidget *button15;
GtkWidget *button16;
GtkWidget *button17;
GtkWidget *button18;
GtkWidget *button19;
GtkWidget *button20;
GtkWidget *button21;
GtkWidget *button22;


void Add(GtkWidget *widget, gpointer data);
void subtract_cb(GtkWidget *widget, gpointer data);
void Mul(GtkWidget *widget, gpointer data);
void Division(GtkWidget *widget, gpointer data);
void clear(GtkWidget *widget, gpointer data);
void input(GtkWidget *widget, gpointer data);
void error_handle(const char* info);

void Binary_Operator();
void Right_output();
void output();
void on_clicked(GtkWidget *widget, gpointer data);
void dot(GtkWidget *widget, gpointer data);
int Conversion(char num[20], int t, int n);

int str2int(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
  {
      if (*str == '-')
        puiss = puiss * -1;
      str++;
  }
  while ((*str >= '0') && (*str <= '9'))
  {
      result = (result * 10) + ((*str) - '0');
      str++;
  }
  return (result * puiss);
}

char* decToBinary(int n)
{
	char *bin = calloc(5, sizeof(char));
	//char bin[32];
	char str[32];
	int binaryNum[32];
	//char bin[32];
	char num[10];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	int j;
	for(j=i-1; j>=0; j--){
		sprintf(str, "%d", binaryNum[j]);
		strcat(bin,str);
	}
	return bin;

}
char* decToOcta(int quotient){
	char *bin = calloc(5, sizeof(char));
	char str[32];
	long decimalnum, remainder;
    	int octalNumber[100], i = 1, j;
	while (quotient != 0)
	{
        	octalNumber[i++] = quotient % 8;
        	quotient = quotient / 8;
	}
	for (j = i - 1; j > 0; j--){
	//printf("%d", octalNumber[j]);
		sprintf(str, "%d", octalNumber[j]);
		strcat(bin,str);
	}
	return bin;
}

char* decToHexa(int n)
{
	char *bin = calloc(5, sizeof(char));
	char str[32];
	char hexaDeciNum[100];
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n/16;
    }
    int j;
    for(j=i-1; j>=0; j--){
    	//printf("%c",hexaDeciNum[j]);
    	sprintf(str, "%c", hexaDeciNum[j]);
	strcat(bin,str);
	}
	return bin;
}
char* binaryToDec(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 2;
			value/=10;
		}
	//printf("%d", dec);
	//snprintf(str, "%d", dec);
	asprintf (&str, "%i", dec);
	//itoa(dec, str, 10);
	return str;
}
char* binaryToOctal(int binarynum){
	long int octalnum = 0, j = 1, remainder;
	char* str;
    while (binarynum != 0)
    {
        remainder = binarynum % 10;
        octalnum = octalnum + remainder * j;
        j = j * 2;
        binarynum = binarynum / 10;
    }
    //printf("%lo", octalnum);
	asprintf (&str, "%lo", octalnum);
	return str;

}
char* binaryToHex(binaryval){
	long int hexadecimalval = 0, i = 1, remainder;
	char* str;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    //printf("%lX", hexadecimalval);
	asprintf (&str, "%lX", hexadecimalval);
	return str;
}


char* octalToBinary(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	//base10 to binary
	re = 0;
	decToBinary(dec);
}

char* octalToDec(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	//printf("%d", dec);
	asprintf(&str, "%d", dec);
	return str;
}

char* octalToHex(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	decToHexa(dec);

}

// Function to convert hexadecimal to decimal
char* hexadecimalToDecimal(char hexVal[])
{
	int len = strlen(hexVal);
	char* str;
	// Initializing base value to 1, i.e 16^0
	int base = 1;

	int dec_val = 0;
	int i;
	// Extracting characters as digits from last character
	for (i=len-1; i>=0; i--)
	{
		// if character lies in '0'-'9', converting
		// it to integral 0-9 by subtracting 48 from
		// ASCII value.
		if (hexVal[i]>='0' && hexVal[i]<='9')
		{
			dec_val += (hexVal[i] - 48)*base;

			// incrementing base by power
			base = base * 16;
		}

		// if character lies in 'A'-'F' , converting
		// it to integral 10 - 15 by subtracting 55
		// from ASCII value
		else if (hexVal[i]>='A' && hexVal[i]<='F')
		{
			dec_val += (hexVal[i] - 55)*base;

			// incrementing base by power
			base = base*16;
		}
	}

	//return dec_val;
	asprintf(&str,"%d",dec_val);
	return str;
}
char* hexadecimalToBinary(char hexVal[])
{
	int len = strlen(hexVal);
	char* str;
	// Initializing base value to 1, i.e 16^0
	int base = 1;

	int dec_val = 0;
	int i;
	// Extracting characters as digits from last character
	for (i=len-1; i>=0; i--)
	{
		// if character lies in '0'-'9', converting
		// it to integral 0-9 by subtracting 48 from
		// ASCII value.
		if (hexVal[i]>='0' && hexVal[i]<='9')
		{
			dec_val += (hexVal[i] - 48)*base;

			// incrementing base by power
			base = base * 16;
		}

		// if character lies in 'A'-'F' , converting
		// it to integral 10 - 15 by subtracting 55
		// from ASCII value
		else if (hexVal[i]>='A' && hexVal[i]<='F')
		{
			dec_val += (hexVal[i] - 55)*base;

			// incrementing base by power
			base = base*16;
		}
	}

	//return dec_val;
	decToBinary(dec_val);
}
char* hexadecimalToOcta(char hexVal[])
{
	int len = strlen(hexVal);
	char* str;
	// Initializing base value to 1, i.e 16^0
	int base = 1;

	int dec_val = 0;
	int i;
	// Extracting characters as digits from last character
	for (i=len-1; i>=0; i--)
	{
		// if character lies in '0'-'9', converting
		// it to integral 0-9 by subtracting 48 from
		// ASCII value.
		if (hexVal[i]>='0' && hexVal[i]<='9')
		{
			dec_val += (hexVal[i] - 48)*base;

			// incrementing base by power
			base = base * 16;
		}

		// if character lies in 'A'-'F' , converting
		// it to integral 10 - 15 by subtracting 55
		// from ASCII value
		else if (hexVal[i]>='A' && hexVal[i]<='F')
		{
			dec_val += (hexVal[i] - 55)*base;

			// incrementing base by power
			base = base*16;
		}
	}

	//return dec_val;
	decToOcta(dec_val);
}





void show_all();

void show_all()
{
            gtk_widget_set_sensitive((button0), TRUE);
            gtk_widget_set_sensitive((button1), TRUE);
            gtk_widget_set_sensitive((button2), TRUE);
            gtk_widget_set_sensitive((button3), TRUE);
            gtk_widget_set_sensitive((button4), TRUE);
            gtk_widget_set_sensitive((button5), TRUE);
            gtk_widget_set_sensitive((button6), TRUE);
            gtk_widget_set_sensitive((button7), TRUE);
            gtk_widget_set_sensitive((button8), TRUE);
            gtk_widget_set_sensitive((button9), TRUE);
            gtk_widget_set_sensitive((button10), TRUE);
            gtk_widget_set_sensitive((button11), TRUE);
            gtk_widget_set_sensitive((button12), TRUE);
            gtk_widget_set_sensitive((button13), TRUE);
            gtk_widget_set_sensitive((button14), TRUE);
            gtk_widget_set_sensitive((button15), TRUE);
}


GtkBuilder *builder;

GdkPixbuf *create_pixbuf(const gchar *filename)
{
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if (!pixbuf)
    {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}


void on_clicked(GtkWidget *widget, gpointer data)
{

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
    {
        if (strncmp((char *) data, "Hex", 3) == 0)
        {
            principle = 16;
            show_all();
            gtk_label_set_text(GTK_LABEL(label4),"Binary");
            gtk_label_set_text(GTK_LABEL(label5),"Octal");
            gtk_label_set_text(GTK_LABEL(label6),"Decimal");
        }
        else if (strncmp((char *) data, "Dec", 3) == 0)
        {

            principle = 10;
            show_all();
            gtk_widget_set_sensitive((button10), FALSE);
            gtk_widget_set_sensitive((button11), FALSE);
            gtk_widget_set_sensitive((button12), FALSE);
            gtk_widget_set_sensitive((button13), FALSE);
            gtk_widget_set_sensitive((button14), FALSE);
            gtk_widget_set_sensitive((button15), FALSE);

            gtk_label_set_text(GTK_LABEL(label4),"Binary");
            gtk_label_set_text(GTK_LABEL(label5),"Octal");
            gtk_label_set_text(GTK_LABEL(label6),"Hexadecimal");
        }
        else if (strncmp((char *) data, "Oct", 3) == 0)
        {

            principle = 8;
            show_all();
            gtk_widget_set_sensitive((button8), FALSE);
            gtk_widget_set_sensitive((button9), FALSE);
            gtk_widget_set_sensitive((button10), FALSE);
            gtk_widget_set_sensitive((button11), FALSE);
            gtk_widget_set_sensitive((button12), FALSE);
            gtk_widget_set_sensitive((button13), FALSE);
            gtk_widget_set_sensitive((button14), FALSE);
            gtk_widget_set_sensitive((button15), FALSE);
            gtk_label_set_text(GTK_LABEL(label4),"Binary");
            gtk_label_set_text(GTK_LABEL(label5),"Decimal");
            gtk_label_set_text(GTK_LABEL(label6),"Hexadecimal");
        }
        else if (strncmp((char *) data, "Bin", 3) == 0)
        {

            principle = 2;
            show_all();
            gtk_widget_set_sensitive((button2), FALSE);
            gtk_widget_set_sensitive((button3), FALSE);
            gtk_widget_set_sensitive((button4), FALSE);
            gtk_widget_set_sensitive((button5), FALSE);
            gtk_widget_set_sensitive((button6), FALSE);
            gtk_widget_set_sensitive((button7), FALSE);
            gtk_widget_set_sensitive((button8), FALSE);
            gtk_widget_set_sensitive((button9), FALSE);
            gtk_widget_set_sensitive((button10), FALSE);
            gtk_widget_set_sensitive((button11), FALSE);
            gtk_widget_set_sensitive((button12), FALSE);
            gtk_widget_set_sensitive((button13), FALSE);
            gtk_widget_set_sensitive((button14), FALSE);
            gtk_widget_set_sensitive((button15), FALSE);
            gtk_label_set_text(GTK_LABEL(label4),"Octal");
            gtk_label_set_text(GTK_LABEL(label5),"Decimal");
            gtk_label_set_text(GTK_LABEL(label6),"Hexadecimal");
        }
        else
        {
            perror("error:on_clicked");
            exit(1);
        }
    }
}

void Right_output() /*Monocular operation result output*/
{
    char num[20];
    if (gcvt(a, 32, num) == NULL) /*The result of the operation is converted into a string*/
    {
        perror("error:Right_output");
    }
    Conversion(num, 10, principle); /*Convert the operation result (decimal string) into a specified hexadecimal number*/
    gtk_entry_set_text(GTK_ENTRY(entry), out); /*show result*/

    int value;
    value=str2int(out);
    if (principle == 16)
        {
           gtk_label_set_text(GTK_LABEL(label3), hexadecimalToDecimal(out));
           gtk_label_set_text(GTK_LABEL(label1), hexadecimalToBinary(out));
           gtk_label_set_text(GTK_LABEL(label2), hexadecimalToOcta(out));

        }
        else if (principle == 10)
        {
           gtk_label_set_text(GTK_LABEL(label1), decToBinary(value));
           gtk_label_set_text(GTK_LABEL(label2), decToOcta(value));
           gtk_label_set_text(GTK_LABEL(label3), decToHexa(value));

        }
        else if (principle == 8)
        {
            gtk_label_set_text(GTK_LABEL(label1), octalToBinary(value));
            gtk_label_set_text(GTK_LABEL(label2), octalToDec(value));
            gtk_label_set_text(GTK_LABEL(label3), octalToHex(value));
        }
        else if (principle == 2)
        {
           gtk_label_set_text(GTK_LABEL(label1), binaryToOctal(value));
           gtk_label_set_text(GTK_LABEL(label2), binaryToDec(value));
           gtk_label_set_text(GTK_LABEL(label3), binaryToHex(value));

        }

    a = 0;
    b = 0;
    method = 0;
}

void error_handle(const char* info)
{
    a = 0;
    b = 0;
    method = 0;
    gtk_entry_set_text(GTK_ENTRY(entry),g_convert(info, -1, "UTF-8", "GB2312", NULL, NULL, NULL)); /*Show error message*/
}

int Conversion(char num[20], int t, int n)
{
    int i, ii, j, k, m, x, b[30], h[30], c;
    double d, r;
    ii = 0;
    p = 0;
    memset(out, 0, 20);
    m = strlen(num); //Find the length of the string
    x = m;
    for (k = 0; k < m; k++) //Mainly in segments, with decimal points as the limit, only the integer part is converted
        {
            if (num[k] == '.')
                {
                    x = k;
                    break;
                }
        }

    for (j = x - 1; j >= 0; j--)
        {
            if (num[j] == '-')
                break; //Symbol processing
            else if ((num[j] >= 'A') && (num[j] <= 'F'))
                {
                    r = num[j] - 'A' + 10;
                }
            else if ((num[j] >= '0') && (num[j] <= '9'))
                {
                    r = num[j] - '0';
                }
            else
                {
                    perror("error:Conversion");
                    exit(1);
                }
            p = p + r * (pow((double) t, (double) (x - j - 1))); //Calculation results
        }

    if (num[x] == '.')
        {
            for (j = x + 1; j < m; j++)
                {
                    if ((num[j] >= 'A') && (num[j] <= 'F'))
                        {
                            r = num[j] - 'A' + 10;
                        }
                    else if ((num[j] >= '0') && (num[j] <= '9'))
                        {
                            r = num[j] - '0';
                        }
                    else
                        {
                            perror("error:Conversion");
                            exit(1);
                        }
                    p = p + r * (pow((double) t, (double) (x - j)));
                }
        }
    if (n == 10) //If you want to convert to decimal
        {
            if (num[0] == '-')
                {
                    p = -p;
                }
            strcpy(out, num);
            return 0;
        }
    else //If you want to convert to other bases
        {
            k = (int) p;
            i = 0;
            while (k) //Determine whether the number to be converted becomes 0
                {
                    h[i++] = k % n; //Take the remainder and perform hexadecimal conversion, but the order is opposite to the correct value
                    k /= n; //Make corresponding changes after converting one bit
                }
            c = 0;
            if (p != (int) p) //Optional calculation, if it is an integer, there is no need to perform this step of calculation
                {
                    d = p - (int) p; //Take the decimal part
                    while (d != 0)
                    {
                        b[c] = (int) (d * n); //The algorithm is ×N rounded
                        d = d * n - b[c];
                        c++;
                        if (c >= 10)
                        break; //The main purpose is to control the number to jump out of the loop in case there is an infinite decimal after the decimal, so as to avoid an infinite loop
                    }
                }
            if (num[0] == '-')
                {
                    out[0] = '-';
                    ii++;
                }
            for (j = i - 1; j >= 0; j--, ii++) //Output in reverse order, numbers greater than 10 will be changed accordingly
                {
                    if ((h[j] >= 10) && (h[j] <= 15))
                        {
                            out[ii] = h[j] - 10 + 'A';
                        }
                    else if ((h[j] >= 0) && (h[j] <= 10))
                        {
                            out[ii] = h[j] - 0 + '0';
                        }
                    else
                        {
                            perror("error:Conversion");
                        }
                }
    if (p != (int) p) //Selective output, which can save output time and program running time
    {
        out[ii++] = '.';
        for (j = 0; j < c; j++, ii++) //Positive sequence output
        {
            if ((h[j] >= 10) && (h[j] <= 15))
                {
                    out[ii] = h[j] - 10 + 'A';
                }
            else if ((h[j] >= 0) && (h[j] <= 10))
                {
                    out[ii] = h[j] - 0 + '0';
                }
            else
                {
                    perror("error:Conversion");
                }
        }
    }
return 0;
}
}

void Binary_Operator() /*Binocular operation*/
{
    char num[20];
    strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));/*Get the content of the text box*/
    if (a == 0) /*If there is no first number, it is stored as the first number*/
    {
        Conversion(num, principle, 10); //Convert all to decimal
        a = p;
        gtk_entry_set_text(GTK_ENTRY(entry), ""); /*Empty text box*/
    }
    else /*If the first number already exists, it should be stored as the second number*/
    {
        Conversion(num, principle, 10); //Convert all to decimal
        b = p;
    }
    hasdot = 0; /*Indicates that there is no decimal point*/
}

void output() /*Binocular operation result output*/
{
    char num[20];
    strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry))); /* Get the content entered in the text box*/
    Conversion(num, principle, 10); /*Convert the entered hexadecimal number to decimal*/
    b = p;
    switch (method)
    {
    case 0:
        a = a + b;
        Right_output();
        break;
    case 1:
        a = a - b;
        Right_output();
        break;
    case 2:
        a = a * b;
        Right_output();
        break;
    case 3:
        if (b == 0)
        {
            error_handle("Divisor cannot be zero");
        }
        else
        {
            a = a / b;
            Right_output();
        }
        break;
    default:
        break;
    }
}

void input(GtkWidget *widget, gpointer data) /* Change this to digit_cb as this takes entry from buttons*/
 {
char num[20];
 const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));

 gint pos = strlen(entry_text);
 gtk_editable_insert_text(GTK_EDITABLE(entry),gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
 int value;
	value = str2int(entry_text);
strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));
 if (principle == 16)
        {
           gtk_label_set_text(GTK_LABEL(label3), hexadecimalToDecimal(num));
           gtk_label_set_text(GTK_LABEL(label1), hexadecimalToBinary(num));
           gtk_label_set_text(GTK_LABEL(label2), hexadecimalToOcta(num));

        }
        else if (principle == 10)
        {
           gtk_label_set_text(GTK_LABEL(label1), decToBinary(value));
           gtk_label_set_text(GTK_LABEL(label2), decToOcta(value));
           gtk_label_set_text(GTK_LABEL(label3), decToHexa(value));

        }
        else if (principle == 8)
        {
            gtk_label_set_text(GTK_LABEL(label1), octalToBinary(value));
            gtk_label_set_text(GTK_LABEL(label2), octalToDec(value));
            gtk_label_set_text(GTK_LABEL(label3), octalToHex(value));
        }
        else if (principle == 2)
        {
           gtk_label_set_text(GTK_LABEL(label1), binaryToOctal(value));
           gtk_label_set_text(GTK_LABEL(label2), binaryToDec(value));
           gtk_label_set_text(GTK_LABEL(label3), binaryToHex(value));

        }



}

void Add(GtkWidget *widget, gpointer data) /*Addition operation*/
{
    method = 0;
    Binary_Operator();
}

void subtract_cb(GtkWidget *widget, gpointer data) /*Addition operation*/
{
    method = 1;
    Binary_Operator();
}

void Mul(GtkWidget *widget, gpointer data) /*Multiplication operation*/
{
    method = 2;
    Binary_Operator();
}

void Division(GtkWidget *widget, gpointer data) /*Division operation*/
{
    method = 3;
    Binary_Operator();
}

void dot(GtkWidget *widget, gpointer data)
{
    if (hasdot == 0) /* If there is no decimal point, add a decimal point*/
    {
        const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
        gint pos = strlen(entry_text);
        gtk_editable_insert_text(GTK_EDITABLE(entry),
                gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
        hasdot = 1;/*  Indicates that there is a decimal point*/
    }
}

void clear(GtkWidget *widget, gpointer data)
{
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    gtk_label_set_text(GTK_LABEL(label1),"");
    gtk_label_set_text(GTK_LABEL(label2),"");
    gtk_label_set_text(GTK_LABEL(label3),"");

    hasdot = 0;
    a = 0;
    b = 0;
    method = 0;
}

int main (int argc, char *argv[])
{
    a = 0;
    b = 0;
    hasdot = 0;
    gtk_init(&argc, &argv);
    method = 0; /*Calculation method*/

    builder = gtk_builder_new_from_file ("buttons-programming.ui");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

    // The title will be centered with respect to the width of the box
    gtk_window_set_title(GTK_WINDOW(window), ("Programming Calculator"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
    gtk_builder_connect_signals(builder, NULL);

    entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry")); /*Text boxes for input and output*/


    box = GTK_WIDGET(gtk_builder_get_object(builder, "button_panel"));


    grid = GTK_WIDGET(gtk_builder_get_object(builder,"advanced_panel"));

    label1 = GTK_WIDGET(gtk_builder_get_object(builder,"label1"));

    label2 = GTK_WIDGET(gtk_builder_get_object(builder,"label2"));

    label3 = GTK_WIDGET(gtk_builder_get_object(builder,"label3"));

    label4 = GTK_WIDGET(gtk_builder_get_object(builder,"label4"));

    label5 = GTK_WIDGET(gtk_builder_get_object(builder,"label5"));

    label6 = GTK_WIDGET(gtk_builder_get_object(builder,"label6"));

    /*GET ALL BUTTONS FROM UI INTO PROGRAM*/
    button0 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_0_button"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_1_button"));
    button2 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_2_button"));
    button3 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_3_button"));
    button4 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_4_button"));
    button5 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_5_button"));
    button6 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_6_button"));
    button7 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_7_button"));
    button8 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_8_button"));
    button9 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_9_button"));
    button10 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_10_button"));/*A*/
    button11 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_11_button"));/*B*/
    button12 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_12_button"));/*C*/
    button13 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_13_button"));/*D*/
    button14 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_14_button"));/*E*/
    button15 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_15_button"));/*F*/
    button16 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_add_button"));
    button17 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_subtract_button"));
    button18 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_multiply_button"));
    button19 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_divide_button"));
    button20 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_result_button"));/*=*/
    button21 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_clear_button"));
    button22 = GTK_WIDGET(gtk_builder_get_object(builder, "calc_numeric_point_button"));/*.*/





    g_signal_connect(button0, "clicked", G_CALLBACK(input/*handler function name here*/), NULL);
    g_signal_connect(button1, "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button10), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button11), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button12), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button13), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button14), "clicked", G_CALLBACK(input), NULL);
    g_signal_connect(G_OBJECT(button15), "clicked", G_CALLBACK(input), NULL);

    /*The buttons below realize the input of various calculations*/

    g_signal_connect(G_OBJECT(button16), "clicked", G_CALLBACK(Add), NULL);
    g_signal_connect(G_OBJECT(button17), "clicked", G_CALLBACK(subtract_cb), NULL);
    g_signal_connect(G_OBJECT(button18), "clicked", G_CALLBACK(Mul), NULL);
    g_signal_connect(G_OBJECT(button19), "clicked", G_CALLBACK(Division), NULL);

    /* The button below realizes the reset function*/
    g_signal_connect(G_OBJECT(button21), "clicked", G_CALLBACK(clear), NULL);

    /* The button below realizes the result output*/
    g_signal_connect(G_OBJECT(button20), "clicked", G_CALLBACK(output), NULL);

    g_signal_connect(G_OBJECT(button22), "clicked", G_CALLBACK(dot), NULL);

   /*The following is to set the "decimal" button to be selected by default*/
    radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "Hex_button"));
    g_signal_connect(GTK_WIDGET(radio1), "clicked", G_CALLBACK(on_clicked),"Hex");


    radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "Dec_button"));
    g_signal_connect(GTK_WIDGET(radio2), "clicked", G_CALLBACK(on_clicked),"Dec");
    gtk_toggle_button_set_active(GTK_WIDGET(radio2),TRUE); /*Decimal radio is set to the default selected state*/


    radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "Oct_button"));
    g_signal_connect(GTK_WIDGET(radio3), "clicked", G_CALLBACK(on_clicked),"Oct");

    radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "Bin_button"));
    g_signal_connect(GTK_WIDGET(radio4), "clicked", G_CALLBACK(on_clicked),"Bin");

    gtk_widget_show(window);

    gtk_main();
    return 0;

}

