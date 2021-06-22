#include<iostream>
#include<openssl/bio.h>
using namespace std;

int main(int argc, char const *argv[])
{
BIO *b;
b = BIO_new_connect("127.0.0.1:8089");
//BIO_set_bind_mode(b,BIO_BIND_REUSEADDR);

BIO_do_connect(b);
while (1)
{
    /* code */


//if(n!=1)cout <<"not connected";
    char m[8];
    BIO_read(b,(void *)m,8);
     printf("\n%s",(char*)m);

  
}
  return 0;
}
