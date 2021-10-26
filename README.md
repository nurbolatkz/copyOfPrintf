# copyOfPrintf
In this project I made a copy of [printf](https://www.opennet.ru/man.shtml?topic=printf&category=3&russian=0) function.

## Description
The printf functions output data according to the format parameter.

Printf working principle

  - Printf takes multiple arguments using vararg function.
  - User enter a string and input arguments. Like printf("Hello, my name is %s having an id %d", name, id);
  - Now printf iterates through each characters of user string and print each characters. Printf only stops at %. % means there is an argument to convert. Arguments are in the form of char, int, long, float, double or string. 


### Return type
Upon successful completion, these functions return the number of characters printed.

#### Using functions
```
void printfadrs(void* a);
char* convert(unsigned int num, int base);
int chprintf(char* s);
char intohex(int v);
int print_ads(void* p);
```


##### Format flags
My_printf function works with flags
| Type | Output|
| --- | --- |
|  %c  |  Char |
|  %d  |  Signed/unsigned integer in decimal form|
|  %o  |  Unsigned in octal form|
|  %x  |  Unsigned integer in hexadecimal form|
|  %u  | Unsigned integer in decimal form|
|  %p  |  Pointer address |
|  %s  |String (null-terminated array of characters)|


#### Expected outputs
```
int n = 150;
char a = 'b';
my_printf("number - %d", n);
my_printf("char - %c", a);
my_printf("returned value - %d", my_printf("number - %d", n);)
```

<b>output</b>
number - 150;
char- a
number - 150;
returned value - 12
