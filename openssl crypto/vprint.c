#include<stdio.h>
#include<stdarg.h>
void WriteFrmtd(char *format,...) {
 
   va_list args;
   
   va_start(args, format);
   vprintf(format, args);
   va_end(args);
}

int main(int argc, char const *argv[])
{

WriteFrmtd("%d variable argument\n", 1);
   WriteFrmtd("%d variable %s\n", 2, "arguments");

    return 0;
}
