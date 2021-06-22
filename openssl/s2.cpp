#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "openssl/bio.h"  
#include "openssl/ssl.h"  
#include "openssl/err.h"  
 
#define log(...) do { printf(__VA_ARGS__); fflush(stdout); } while(0)
#define check0(x, ...) if(x) do { log( __VA_ARGS__); exit(1); } while(0)
#define check1(x, ...) if(!(x)) do { log( __VA_ARGS__); exit(1); } while(0)

int main(int argc, char **argv)  
{
   
    SSL_library_init();
    SSL_load_error_strings();  
    ERR_load_BIO_strings();  
 
    SSL_CTX* ctx = SSL_CTX_new (SSLv23_method());
    check1(ctx, "SSL_CTX_new failed\n");
 
    // 加载自己的证书  
    int r = SSL_CTX_use_certificate_file(ctx, "clicert.pem", SSL_FILETYPE_PEM);
    check1(r>0, "SSL_CTX_use_certificate_file failed");
 

    r = SSL_CTX_use_PrivateKey_file(ctx, "clikey.pem", SSL_FILETYPE_PEM);  
    check1(r>0, "SSL_CTX_use_PrivateKey_file failed");

 
    r = SSL_CTX_check_private_key(ctx);
    check1(r, "SSL_CTX_check_private_key failed");

    log("ssl inited\n");
   
    
    SSL_CTX_free (ctx);  
   
    return 0;
}