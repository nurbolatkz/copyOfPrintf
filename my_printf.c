#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

void printfadrs(void* a);
char* convert(unsigned int num, int base);
int chprintf(char* s);
char intohex(int v);
int print_ads(void* p);

int my_printf(char* format, ...)
{
    char* ptr;
    char* s;
    char* err = "Error format";
    int i;
    void* a;

    va_list arg;
    va_start(arg, format);

    int k = 0, len = 0;

    if (format == NULL)
    {
        return -1;
    }
    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr != '%')
        {
            len++;
            putchar(*ptr);
            continue;
        }

        switch (*++ptr)
        {
            case 'c':
                i = va_arg(arg, int);
                putchar(i);
                k++;
                break;
            case 'd':
                i = va_arg(arg, int);
                if (i < 0)
                {
                    i = -i;
                    putchar('-');
                    k++;
                }
                if (i == 0)
                {
                    putchar('0');
                    k++;
                }
                else
                {
                    k += chprintf(convert(i, 10));
                }
                break;
            case 'o':
                i = va_arg(arg, unsigned int);
                k += chprintf(convert(i, 8));
                break;
            case 's':
                s = va_arg(arg, char*);
                k += chprintf(s);
                break;
            case 'x':
                i = va_arg(arg, unsigned int);
                k += chprintf(convert(i, 16));
                break;
            case 'u':
                i = va_arg(arg, unsigned int);
                k += chprintf(convert(i, 10));
                break;
            case 'p':
                a = va_arg(arg, void*);
                k += print_ads(a);
                break;
            default:
                puts(err);
                break;
        }
    }
    len = len + k;
    va_end(arg);
    return len;
}

char* convert(unsigned int num, int base)
{
    static char characters[] = "0123456789ABCDEF", buffer[50];
    char* ptr;
    ptr = &buffer[49];
    *ptr = '\0';
    while (num != 0)
    {
        *--ptr = characters[num % base];
        num /= base;
    }
    return (ptr);
}

char intohex(int v)
{
    if (v >= 0 && v < 10)
    {
        return '0' + v;
    }
    else
    {
        return 'a' + v - 10;
    }
}

int print_ads(void* p0)
{
    int i, k = 0;
    uintptr_t p = (uintptr_t)p0;
    char st[30];
    for (i = (sizeof(p) << 3) - 4; i >= 0; i -= 4)
    {
        st[k] = intohex((p >> i) & 0xf);
        k++;
    }
    st[2] = '0', st[3] = 'x', k = 0;

    for (int i = 2; i <= 15; i++)
    {
        putchar(st[i]);
        k++;
    }
    return k;
}

int chprintf(char* s)
{
    int j = 0;
    if (s == NULL)
    {
        s = "(null)";
    }
    while (s[j] != '\0')
    {
        putchar(s[j]);
        j++;
    }
    putchar('\0');
    return j;
}




 /* int main()
{
    
    int size =  printf("%p!\n", &i);
    int size2 =  my_printf("%p!\n", &i);
    printf("%d\n", size2);
    
    if (size == size2)
    {
        printf("yes you can :)\n");
    
    }
   
    return 0;
} */

