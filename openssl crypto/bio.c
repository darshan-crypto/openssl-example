#include<stdio.h>
#include<openssl/bio.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<openssl/err.h>
int main(int argc, char const *argv[])
{
    ERR_load_BIO_strings();
    ERR_load_ERR_strings();
//FILE *m = fopen("test.txt","w");

FILE *m = fopen("test.txt","w");
//int m = open("test.txt",O_RDWR);
//printf("\n%d\n",m);
BIO *b ;
// BIO_new_fd(m,1);
b=BIO_new_fp(m,BIO_CLOSE);
//BIO_set_fp(b,m,1);
//b=BIO_new_file("tvp.c2","w");
//BIO_write_filename(b,stdout);
printf("\n%d\n", BIO_write(b,"hello9",6));
int c;
BIO_get_fd(b,&c);
printf("\n%d",c);
 printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
    return 0;
}
