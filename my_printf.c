#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int my_printf(char*, ...);
char* convert(unsigned long int, int);
void my_putchar(char c);
void my_puts(char* ch);
int my_strlen(char* ch);

int main()
{
  int y = 10;
  char* t = NULL;
  my_printf(" %d\n ", my_printf("Hello world!\n"));
  my_printf(" %d\n ", my_printf("%c!\n", 'H'));
  my_printf(" %d\n ", my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'));
  my_printf(" %d\n ", my_printf("Hello %s!\n", "QWASAR.IO"));
  my_printf(" %d\n ", my_printf("Hello %s %s!\n", "Mr", "Gaetan"));
  my_printf(" %d\n ", my_printf("NULL STRING %s!\n",t));
  my_printf(" %d\n ", my_printf("%d!\n", 1337));
  my_printf(" %d\n ", my_printf("%d - %d - %d!\n", 2048, 0, -1337));
  my_printf(" %d\n ", my_printf("%o!\n", 100));
  my_printf(" %d\n ", my_printf("%u!\n", 1337));
  my_printf(" %d\n ", my_printf("%x!\n", 14));
  my_printf(" %d\n ", my_printf("%p!\n", &y));

return 0;
}

int my_printf(char* format, ...)
{
   char* traverse;
   int i;
   char* s;
   unsigned long int n;
   int CharacterCount = 0;
   va_list arg;
   va_start(arg, format);

  for (traverse = format; *traverse != '\0';)
    {
    while (*traverse != '%' && *traverse != '\0')
        {
      my_putchar(*traverse);
     traverse++;
     CharacterCount++;
    }
    if (*traverse == '%')
        {
            traverse++;

switch (*traverse)
{
case 'c':
        i = va_arg(arg, int); 
        my_putchar(i);
        traverse++;
        CharacterCount++;
        break;

case 'd':
        i = va_arg(arg, int);
        if (i < 0)
        {
        i = -i;
        my_putchar('-');
        CharacterCount++;
        }
        my_puts(convert(i, 10));
        traverse++;
        CharacterCount += my_strlen(convert(i, 10));
        break;
case 'o':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 8));
        traverse++;
        CharacterCount += my_strlen(convert(i, 8));
        break;
case 's':
        s = va_arg(arg, char*);
        if (s == NULL)
        {
        s = "(null)";
        }
        my_puts(s);
        traverse++;
        CharacterCount += my_strlen(s);
        break;
case 'x':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 16));
        traverse++;
        CharacterCount += my_strlen(convert(i, 16));
        break;
case 'u':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 10));
        traverse++;
        CharacterCount += my_strlen(convert(i, 10));
        break;
case 'p':
        n = va_arg(arg, unsigned long int);
        my_putchar('0');
        my_putchar('x');
        my_puts(convert(n, 16));
        traverse++;
        CharacterCount += my_strlen(convert(n, 16))+2;
         break;
}
}
}
 va_end(arg);
 return CharacterCount;
}

void swap(char* a, char* b)
{
char temp = *a;
*a = *b;
*b = temp;
}

char* reverse(char* buffer, int end)
{
int start = 0;
end = end - 1;
while (start < end)
{
swap(&buffer[start++], &buffer[end--]);
}
return buffer;
}

char* convert(unsigned long int num, int base)
{
    char* str = malloc(1000);
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
while (num != 0)
{
int rem = num % base;
str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
num = num / base;
}

if (isNegative) str[i++] = '-';
str[i] = '\0'; 
str = reverse(str, i);
return str;
}
void my_putchar(char c)
{
  write(1, &c, 1);
}
void my_puts(char* ch)
{
int len = my_strlen(ch);
for (int i = 0; i < len; i++)
{
my_putchar(ch[i]);
}
}

int my_strlen(char* ch)
{
int count = 0;
if (ch[0] == '\0')
{
return 0;
 }

 while (*ch) 
{ 
  count++; 
  ch++;
   }
return count;
   }
