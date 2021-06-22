#include<stdio.h>
#include<openssl/bio.h>
#include<openssl/buffer.h>
#include<stdarg.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<openssl/err.h>
void write(BIO *m1,char* m,...){
    va_list bu ;
va_start(bu,m);
BIO_vprintf(m1,m,bu);
va_end(bu);
}
void writer2(char *bu,int len,char l[],...){
   
     va_list a;
     va_start(a,l);
     BIO_vsnprintf(bu,len,l,a);
     
    va_end(a);
}
int main(int argc, char const *argv[])
{
    ERR_load_BIO_strings();
    ERR_load_ERR_strings();
FILE *m = fopen("tvp.c2","w");

BIO *b = BIO_new_fp(m,1);
// while (!BIO_eof(b))
// {
//     char data;
//     BIO_read(b,&data,1);
//     int x = BIO_pending(b);
//     printf("%c \n%d",data,x);
// }

//BIO_vprintf(b,"\ni gave you %d dollers\n",*bu);
//va_end(bu);
char m9[50];
//BIO_snprintf(m9,50,"--darshan %s--","sotra");
writer2(m9,50,"=----hello %s at %d ","darshan",907);
//write(b,"hello %s my name is %s","drarshan","darshan0");
printf("\n%s\n",m9);
BIO_free(b);
 printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
    return 0;
}
