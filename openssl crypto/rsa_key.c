#include<stdio.h>
#include<openssl/evp.h>
#include<openssl/rsa.h>
#include<openssl/err.h>
int main(){

EVP_PKEY *key;
EVP_PKEY_CTX *ctx;
ERR_load_CRYPTO_strings();
  //  key = EVP_PKEY_Q_keygen()
key =EVP_PKEY_new();
ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,NULL);
if (ctx == NULL)
{
    printf("error ctx");
     printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
    return 101;

}

if ( EVP_PKEY_keygen_init(ctx)  <=0)
{
    printf("error init");
    return 101;
}

if(EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,1024)<=0) printf("\n%s" ,ERR_error_string(ERR_get_error(),0));
if(EVP_PKEY_keygen(ctx,&key)<=0) printf("\n%s" ,ERR_error_string(ERR_get_error(),0));

size_t len;
unsigned char key2[1025];
EVP_PKEY_get_raw_public_key(key,key2,&len);
//printf("%ld",len);
for(size_t i =0;i<len;i++){

printf("%02x",key2[i]);
}
}