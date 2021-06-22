#include<stdio.h>
#include<openssl/bio.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
int main(){

ERR_load_SSL_strings();
ERR_load_X509_strings();
ERR_load_ERR_strings();
ERR_load_BIO_strings();
   OpenSSL_add_all_algorithms();
    SSL_library_init();
    printf("advno");
SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
if(ctx = NULL){
    printf("error ctx\n");
    return 101;
}
  
//   if (!SSL_CTX_use_certificate_file(ctx,"/home/darshan/Documents/c++_projects/openssl/certificate.pem", SSL_FILETYPE_PEM)) {
//        printf("error cert\n"); 
//          printf("\n%s", ERR_error_string(ERR_get_error(), 0));
//                     printf("\n%s" ,ERR_reason_error_string(ERR_get_error()));
//        return 101;
//     }

//     if (SSL_CTX_use_PrivateKey_file(ctx, "clikey.pem", SSL_FILETYPE_PEM) <= 0 ) {
//     printf("error key\n");
// 	exit(EXIT_FAILURE);
//     }
SSL * ssl = SSL_new(ctx);
BIO *b =BIO_new_ssl_connect(ctx);
BIO_set_conn_hostname(b,"www.google.com:443");
BIO_get_ssl(b,ssl);
if(SSL_connect(ssl)<=0){
    printf("error");
}
printf("\n%d hbd", SSL_write(ssl,"hello",5));
  
 
           printf("\n%s", ERR_error_string(ERR_get_error(), 0));
                   printf("\n%s" ,ERR_reason_error_string(ERR_get_error()));
    return 0;
}