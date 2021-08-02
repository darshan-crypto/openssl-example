#include<stdio.h>

#include"openssl.h"
int main(){

EVP_PKEY_CTX *ctx ,*ctx2;
EVP_PKEY *pkey,*pkey2;
FILE *i = fopen("x.pem","r");
//FILE *i2 = fopen("xpriv.pem","r");
pkey =  PEM_read_PUBKEY(i,0,0,0);
//pkey2 =  PEM_read_PrivateKey(i2,0,0,0);
   //if(pkey ==NULL || pkey2 ==0)error();
   
   ctx = EVP_PKEY_CTX_new(pkey,0);
    //ctx2 = EVP_PKEY_CTX_new(pkey2,0);
   if(ctx==0)error();
   EVP_PKEY_CTX_set1_id(ctx,EVP_PKEY_RSA,1);
 //  EVP_PKEY_CTX_set1_id(ctx2,EVP_PKEY_RSA,1);
  // error();
   EVP_PKEY_CTX_set_rsa_padding(ctx,RSA_PKCS1_PADDING);
  //  EVP_PKEY_CTX_set_rsa_padding(ctx2,RSA_PKCS1_PADDING);

   EVP_PKEY_encrypt_init(ctx);
int  V = EVP_PKEY_CTX_ctrl(ctx,EVP_PKEY_RSA,1,0,0,0);
error();
printf("\n%d",V);
unsigned char out[5000];
unsigned char text[2000];
size_t len;
size_t len2;
EVP_PKEY_encrypt(ctx,out,&len,(unsigned char *)"hello",5);
   // error();
    printf("%d\n",len);
   for(int i=0;i<len;i++)printf("%02x",out[i]);
//  EVP_PKEY_decrypt_init(ctx);
 //EVP_PKEY_decrypt(ctx,text,&len2,out,len);
//printf("%s",text);
EVP_PKEY_CTX_free(ctx);
// scanf("%d",&len2);
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

   error();
    return 0;
}