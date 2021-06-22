#include<iostream>
#include<openssl/ssl.h>
#include<openssl/err.h>
#include<openssl/bio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ERR_load_SSL_strings();
   ERR_load_BIO_strings();
    ERR_load_ERR_strings();
    SSL_library_init();
    const SSL_METHOD *m;
    SSL_CTX *context;
    SSL *ssl;
    BIO *bio;
    m = SSLv23_client_method();
    if (m == NULL)
    {
        cout << "\nmethod error";
    }
    context  = SSL_CTX_new(m);
    if (context == NULL)
    {
               cout << "\n context error";

    }
        return 0;
}
