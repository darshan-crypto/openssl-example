#include<iostream>
#include<openssl/bio.h>
#include<sys/socket.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
using namespace std;


int main(int argc, char const *argv[])
{
ERR_load_BIO_strings();

 BIO_ADDR *q;  
 BIO_ADDR *p = BIO_ADDR_new();
 q = BIO_ADDR_new();
 //BIO_ADDR_free(p);
 //BIO_ADDR_clear(p);
int c=  BIO_ADDR_rawmake(p,AF_INET,"127.0.0.1",9,8089);
cout << endl <<  ERR_error_string(ERR_get_error(),0);
 BIO_ADDR_rawmake(q,AF_INET,"127.0.0.1",9,8089);
 //cout << BIO_ADDR_hostname_string(p,1);
int socket =  BIO_socket(AF_INET,SOCK_STREAM,0,0);
//int bind  = BIO_bind(socket,q,0);
int connect = BIO_connect(socket,p,BIO_SOCK_KEEPALIVE );
//cout << endl <<"g"<<BIO_listen(socket,q,0);
//cout << endl <<BIO_accept_ex(socket,q,0);
//cout << BIO_closesocket(socket);
cout << endl << "c " << c;
cout << socket << endl  << endl << connect;
    return 0;
}
