#include <stdio.h>
#include <stdarg.h>

int myprintf(char *format, ...)
{
	int d, total = 0;
	char c, *s;
	va_list ap;

	va_start(ap, format);

	for(s = format; *s != '\0'; s++){
		if(*s == '%'){
			s++;
			switch(*s){
				case 's' :{
					char *q;
					q = va_arg(ap, char *);
					for(; *q != '\0'; q++)
						putchar(*q);
					break;
						  }
				case 'd' :
					d = va_arg(ap, int);
					putchar(d);
					break;
				case 'c' :
					c = (char)va_arg(ap, int);
					putchar(c);
					break;
				default:
					putchar(*format);
					break;
			}
		} else 
			putchar(*s);
		
		total++;
	}
	va_end(ap);
	return total;
}

int main(void)
{
	//printf("%s");
//	myprintf("%s");
	printf("----------------------%d, %s, %s, %c, %d\n", 3, "hello", "world", 'A', 43);
	myprintf("%d, %s, %s, %c, %d\n", 3, "hello", "world", 'A', 43);
	putchar('\n');
	myprintf("%s, %c, %d\n", "akaedu", 'B', 22);

	return 0;
}
