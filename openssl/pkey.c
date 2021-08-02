#include<stdio.h>
#include"openssl.h"

int main(){
load();
EVP_PKEY *key;
key = EVP_PKEY_new();
EVP_PKEY_CTX *ctx;     
ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,0);


EVP_PKEY_keygen_init(ctx);
EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,2048);
EVP_PKEY_keygen(ctx,&key);


BUF_MEM m;
m.length =1;
m.max=5000;
m.data="d";

BIO *b  = BIO_new_fp(stdout,1);
if(b==NULL){
    printf("t");
}
int n = BIO_set_mem_buf(b,&m,1);


if(b==0){
    printf("e\n");
    error();
}
FILE *i = fopen("m.txt","w");
PEM_write_bio_PUBKEY(b,key);

int c  =PEM_write_PUBKEY(i,key);
char m9[5000];
BIO_get_mem_data(b,m9);
printf("%d %d %d" ,strlen(m9),c,n)
error(
    return 0;
}