#include<iostream>
#include<openssl/bio.h>
#include<ctime>
using namespace std;

int main(int argc, char const *argv[])
{
BIO *b;
b = BIO_new_accept("127.0.0.1:8089");
BIO_set_bind_mode(b,BIO_BIND_REUSEADDR);


BIO_do_accept(b);
    BIO_do_accept(b);
while(1){

    time_t times;
    time(&times);
    struct tm *tm1;
   tm1 = localtime(&times);
   char timet[9];
    strftime(timet,9,"%T",tm1);
    BIO_puts(b,timet);

cout << endl<<timet;
   
}
 return 0;
}
