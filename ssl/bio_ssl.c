#include"common.h"


int main(){

load();

SSL_CTX *ctx = InitCTX();
LoadCertificates(ctx,"cert.crt","key.pem","12345678");
SSL* s= SSL_new(ctx);
SSL_set_connect_state(s);

BIO *b = BIO_new_ssl(ctx,1);
BIO_get_ssl(b,s);
BIO_set_conn_hostname(b,"www.example.com:https");

if(BIO_do_connect(b) <=1){
printf("\n error");
printf("%s",ERR_error_string(ERR_get_error(),0));
}
    return 0;
}
