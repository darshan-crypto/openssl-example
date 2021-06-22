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
int m = open("test.txt",O_RDWR);
if (m==0)
{
    printf("\n error");
}
  BIO *b = BIO_new_fd(m,1);
  if (b==0)
  {
      printf("\n error 2");
  }
  BIO_puts(b,"hello");
  BIO_printf(b,"nanio");
  BIO_write_filename(b,"tvp.txt");
  BIO_seek(b,0);
  char text[5];
  printf("%d", BIO_read(b,text,5));
  printf("\n%s",text);

 printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
    return 0;
}
