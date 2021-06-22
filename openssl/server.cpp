#include<iostream>
#include<sys/socket.h>
#include<openssl/bio.h>
#include<openssl/bioerr.h>
#include<openssl/err.h>
using namespace std;
int main(int argc, char const *argv[])
{
//    const  BIO_METHOD *o = BIO_s_socket();
//     BIO* m = BIO_new_socket(SOCK_STREAM,1);
//     if (o==0)
//     {
//         cout << "\n bio not created";
        
//        ERR_load_ERR_strings();
//     }
//     BIO * b= BIO_new_connect("localhost:8089");
//     BIO_set_conn_ip_family(b,AF_LOCAL);
//     BIO_set_conn_port(b,"8089");
//     if (b==0)
//     {
//      cout << "bio error";
//     // return -9;

//     }
//    cout << BIO_do_connect(b);
//      cout << endl <<  ERR_error_string(ERR_get_error(),0);
//     return 0;
//  const  BIO_ADDR *a;
   
//      BIO_ADDRINFO *i;
//     int e =  BIO_lookup(0,"8089",BIO_lookup_type::BIO_LOOKUP_SERVER,AF_INET,SOCK_STREAM,&i);
//    a = BIO_ADDRINFO_address(i);
//    int socket = BIO_socket(AF_INET,SOCK_STREAM,0,0);
//    if (socket != 0)
//    {
       
//      // int x =  BIO_connect(socket,a,0);
//       BIO_listen(socket,a,0);
//       BIO_accept_ex(socket,0,0);
  
//    }
BIO *b = BIO_new_accept("127.0.0.1:8089");
BIO_set_bind_mode(b,BIO_BIND_REUSEADDR);
BIO_do_accept(b);

BIO_do_accept(b);   
BIO_puts(b,"<h1>helloio</h1><script>alert(\"hi\") </script>");

}
