#include<iostream>
#include<sys/socket.h>
#include<openssl/bio.h>
#include<openssl/bioerr.h>
#include<openssl/err.h>
using namespace std;
int main(int argc, char const *argv[])
{

BIO *b = BIO_new_connect("127.0.0.1:8089");
BIO_set_bind_mode(b,BIO_BIND_REUSEADDR);
BIO_do_connect(b);  
//BIO_puts(b,"<h1>helloio</h1><script>alert(\"hi\") </script>");
char m[30];
BIO_read(b,m,30);
cout <<endl<<m<<endl;
}