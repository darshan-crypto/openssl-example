#include<stdio.h>
#include"openssl.h"
int main(){
load();
EVP_PKEY *pubkey,*priv;
EVP_PKEY_CTX *ctx,*ctx2;
pubkey = EVP_PKEY_new();
priv = EVP_PKEY_new();
if(pubkey == 0)printf("error u");
FILE *i = fopen("x.pem","r");
FILE *i2 = fopen("xpriv.pem","r");
pubkey =  PEM_read_PUBKEY(i,0,0,0);
priv =  PEM_read_PrivateKey(i2,0,0,0);
if(i == NULL || pubkey == 0)printf("error x");
ctx = EVP_PKEY_CTX_new(pubkey,0);
ctx2 = EVP_PKEY_CTX_new(priv,0);

 int x =  EVP_PKEY_encrypt_init(ctx);
EVP_PKEY_CTX_set1_id(ctx,EVP_PKEY_RSA,0);
EVP_PKEY_CTX_set_rsa_padding(ctx,RSA_PKCS1_PADDING);
EVP_PKEY_CTX_set1_id(ctx2,EVP_PKEY_RSA,0);
EVP_PKEY_CTX_set_rsa_padding(ctx2,RSA_PKCS1_PADDING);


   printf("\n %d",x);
   unsigned char* out;
unsigned char text[2000];
size_t len;
size_t len2;
int y  = EVP_PKEY_encrypt(ctx,0,&len,(unsigned char *)"hello",5);
 out = OPENSSL_malloc(len);
int yi  = EVP_PKEY_encrypt(ctx,out,&len,(unsigned char *)"hello",5);

   printf("\n %ld %d %d\n",len,y,yi);
  for(int i=0;i<len;i++)printf("%02x",*(out+i));
EVP_PKEY_CTX_free(ctx);
EVP_PKEY_free(pubkey);
// char encoded[10000];
// int len3=0,temp;
// EVP_ENCODE_CTX *ec =EVP_ENCODE_CTX_new();
// EVP_EncodeInit(ec);
// EVP_EncodeUpdate(ec,encoded,&temp,out,len);
// len3+=temp;
// EVP_EncodeFinal(ec,encoded+len3,&temp);
// len3+=temp;
// printf("\n\n");
// for(int i=0;i<len3;i++)printf("%c",encoded[i]);
 unsigned char* decrypted;
    EVP_PKEY_decrypt_init(ctx2);
    size_t len5=0;
    EVP_PKEY_decrypt(ctx2,0,&len5,out,len);
    error();
    
   decrypted = OPENSSL_malloc(len5);
   EVP_PKEY_decrypt(ctx2,decrypted,&len5,out,len);
     for(int i=0;i<len5;i++)printf("%c",*(decrypted+i));
    return 0;
}