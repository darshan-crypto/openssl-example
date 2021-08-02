#include<stdio.h>
#include"openssl.h"

int main(){
EVP_PKEY_CTX * ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,0);
EVP_PKEY *key = EVP_PKEY_new();
EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,2048);

EVP_PKEY_keygen_init(ctx);
EVP_PKEY_keygen(ctx,&key);

BIO *b = BIO_new_file("private-key.pem","w");
BIO *b1 = BIO_new_file("public-key.pem","w");
PEM_write_bio_PUBKEY(b1,key);
PEM_write_bio_PrivateKey(b,key,0,0,0,0,0);

    return 0;
}