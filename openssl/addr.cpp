#include<iostream>
#include<openssl/bio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<openssl/err.h>
using namespace std;
int main(int argc, char const *argv[])
{
    OPENSSL_init();
    ERR_load_ERR_strings();
   const  BIO_ADDR *a;
   BIO_ADDR *p;
     BIO_ADDRINFO *i;
    int e =  BIO_lookup("142.250.194.132","80",BIO_lookup_type::BIO_LOOKUP_CLIENT,AF_INET,SOCK_STREAM,&i);
   a = BIO_ADDRINFO_address(i);
//    BIO_ADDR_rawaddress(p,a,0);
//     if( p==NULL) cout <<"S";
//    if ( BIO_ADDR_family(p) == AF_INET )
//    {
//      // cout << "inet"  <<BIO_ADDRINFO_family(i) << e;
//       cout << BIO_ADDR_hostname_string(a,1);
//    }
//    cout << endl <<  ERR_error_string(ERR_get_error(),0);
//     cout << endl << ERR_reason_error_string(ERR_get_error());
    return 0;
}

