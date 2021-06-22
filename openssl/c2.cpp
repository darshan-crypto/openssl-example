#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include<asio/ssl.hpp>
using namespace std;
int main(int argc, char const *argv[])
{
    ERR_load_SSL_strings();
    ERR_load_BIO_strings();
    ERR_load_ERR_strings();
ERR_load_X509_strings();
    OpenSSL_add_all_algorithms();
    SSL_library_init();
    const SSL_METHOD *m;
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!SSL_CTX_load_verify_locations(ctx, "2.pem", NULL))
    {

        cout << "error";
    }
     if (SSL_CTX_use_PrivateKey_file(ctx, "2key.pem", SSL_FILETYPE_PEM) <= 0)
    {
       cout << "key error";
    }
    ssl = SSL_new(ctx);
    bio = BIO_new_ssl_connect(ctx);
    BIO_get_ssl(bio, ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    BIO_set_conn_hostname(bio, "www.youtube.com:443");

    if (BIO_do_handshake(bio) <= 0)
    {
        cout << "error2";
    }

    
    if (SSL_get_verify_result(ssl) != X509_V_OK)
    {
        cout << "error";
    }


    X509 *cer =  SSL_get_peer_certificate(ssl);
 if(cer == NULL)
{
printf("cert error");
 cout << endl
           << ERR_error_string(ERR_get_error(), 0);
     cout << endl
          << ERR_reason_error_string(ERR_get_error());
} 
 
 
    size_t nm;
     std::string s = "GET / HTTP/1.1 \r\n Host : www.youtube.com \r\n Connection : keep-alive \r\n\r\n";
    if(ssl==NULL)printf("\n error ssl \n");
    
    SSL_write_ex(ssl,(const void *)"hello",5,&nm);
    cout << "\n written " << nm;
    cout << endl
           << ERR_error_string(ERR_get_error(), 0);
     cout << endl
          << ERR_reason_error_string(ERR_get_error());

    char mc[20000];
    cout << "x";
    SSL_read(ssl, mc, 1998);
    cout << mc;
}