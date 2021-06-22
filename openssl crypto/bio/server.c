#include<stdio.h>
#include<openssl/bio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    BIO *b = BIO_new_accept("127.0.0.1:8089");

    BIO_do_accept(b);
    BIO_do_accept(b);
    char m[] ="<html> <body>v</body></html>";
    BIO_write(b,m,strlen(m));
    getchar();
    return 0;
}
