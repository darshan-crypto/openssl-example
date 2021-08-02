#include<stdio.h>
#include"openssl.h"
// int callback(EVP_PKEY_CTX *ctx){
//   int *x;
//   x =  EVP_PKEY_CTX_get_data(ctx);
// printf("%d",*x);

//     return 1;
// }
int main(){
EVP_PKEY  *key = EVP_PKEY_new();
//EVP_PKEY  *key2 = EVP_PKEY_new();

EVP_PKEY_CTX *ctx =EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,0);
//int *x =101;
EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,2048);
//EVP_PKEY_CTX_set_app_data(ctx,&x);
//EVP_PKEY_CTX_set_cb(ctx,callback);

//EVP_PKEY_paramgen_init(ctx);
//EVP_PKEY_paramgen(ctx,&key);

//EVP_PKEY_CTX *ctx2 =EVP_PKEY_CTX_new(key,0);
//EVP_PKEY_CTX_set_rsa_keygen_bits(ctx2,2048);
//EVP_PKEY_CTX_set_app_data(ctx2,x);
//EVP_PKEY_CTX_set_cb(ctx2,callback);
//error();
EVP_PKEY_keygen_init(ctx);
//EVP_PKEY_CTX_set_rsa_keygen_bits(ctx2,2048);
EVP_PKEY_keygen(ctx,&key);

FILE *i = fopen("param.pem","w");
PEM_write_PrivateKey(i,key,0,0,0,0,0);

BIO *b = BIO_new_fp(stdout,1);
EVP_PKEY_print_public(b,key,0,0);
unsigned char x[10000];
int len=0;
//BIO_read(b,x,len);
//printf("%d",len);
    BIO *privateBIO = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(privateBIO, key, NULL, NULL, 0, 0, NULL);
  //  int privateKeyLen = BIO_pending(privateBIO);
   int c= BIO_read(privateBIO,x,2000);
  // printf("\n %d",privateKeyLen);
//int privateKeyLen=1704;
  //  unsigned char *privateKeyChar = (unsigned char *) malloc(privateKeyLen);
  //printf("\n%d\n" , BIO_read(privateBIO, privateKeyChar, privateKeyLen));

printf("%d %s",c,x);
    return 0;
}