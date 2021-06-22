#include<stdio.h>
#include<openssl/bio.h>
#include<openssl/buffer.h>
#include<stdarg.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<openssl/err.h>
long int callback(BIO *b, int oper, const char *argp,long unsigned int len ,int argi,long argl, int ret,long unsigned int *p){
    printf("\n");
    
    if (oper == BIO_CB_PUTS)
    {
        printf("%lud puter",(p));
    }
   // else return BIO_CB_RETURN;
    //printf("%d",len);
   // printf("callback");
     printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
}
int main(int argc, char const *argv[])
{
    ERR_load_BIO_strings();
    ERR_load_ERR_strings();
FILE *m = fopen("tvp.c3","w");

BIO *b = BIO_new_fp(m,1);

char m9[50];
BIO_set_callback_ex(b,callback);

BIO_puts(b,"hello909");

//BIO_free(b);
 printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
    return 0;
}
