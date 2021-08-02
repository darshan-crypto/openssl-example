//#define OPENSSL_API_COMPAT 0x10100000L
//#define OPENSSL_NO_DEPRECATED
#include<stdio.h>
#include"openssl.h"

int main(){
  
EVP_PKEY *pkey,*pubkey;
EVP_PKEY_CTX *ctx,*encctx;
//pkey = EVP_PKEY_new();
pubkey = EVP_PKEY_new();
ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,0);
encctx = EVP_PKEY_CTX_new(pubkey,0);
if(ctx == NULL)printf("ctx error\n");
EVP_PKEY_keygen_init(ctx);
EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,2048);
EVP_PKEY_keygen(ctx,&pkey);
//BIO *b = BIO_new_file("x.pem",'w');
 FILE *x = fopen("x.pem","w");
 FILE *xp = fopen("xpriv.pem","w");
PEM_write_PUBKEY(x,pkey);
PEM_write_PrivateKey(xp,pkey,0,0,0,0,0);
PEM_read_PUBKEY(x,&pubkey,0,0);
EVP_PKEY_CTX_set1_id(encctx,EVP_PKEY_RSA,0);
EVP_PKEY_encrypt_init(encctx);
unsigned char  out[10000];
unsigned char *in = "helloin";
EVP_PKEY_CTX_set_rsa_padding(encctx, RSA_NO_PADDING);
size_t len;
EVP_PKEY_encrypt(encctx,out,&len,in,7);
for(int i=0;i<len;i++){

    printf("%02x",out[i]);
}
printf("%d %s",len,ERR_error_string(ERR_get_error(),0));
    return 0;
}  