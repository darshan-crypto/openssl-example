#include<stdio.h>
#include"openssl.h"

int encrypt(char *,size_t,BIO*);
EVP_PKEY *key ;
int main(int argc,char* argv[]){
key = EVP_PKEY_new();
BIO* b= BIO_new_file(argv[1],"r");
if(b==0)
{
printf("error in opening key ");
return -1;
}

PEM_read_bio_PUBKEY(b,&key,0,0);

BIO *b1 = BIO_new_file(argv[2],"r");
if(b1 ==0)
{
    printf("\n can not open source file");
return -1;
}
char name[255]={0};
strcat(name,argv[2]);
strcat(name,".renc");
printf("\n %s",name);
BIO *b2 = BIO_new_file(name,"a+b");
if(b2 ==0)
{
    printf("\n can not create encrypted file");
return -1;
}
char bu[4096];
size_t readded;
while ((BIO_read_ex(b1,bu,4096,&readded))!= 0)
{
    encrypt(bu,readded,b2);
}


    return 0;
}




int encrypt(char *data,size_t read,BIO *b){
EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(key,0);
EVP_PKEY_CTX_set1_id(ctx,EVP_PKEY_RSA,1);
EVP_PKEY_CTX_set_rsa_padding(ctx,RSA_PKCS1_PADDING);
if(ctx ==0){
    printf("error context");
    return -1;
}
size_t len;
EVP_PKEY_encrypt_init(ctx);
EVP_PKEY_encrypt(ctx,0,&len,(unsigned char*)data,read);
unsigned char *out = OPENSSL_malloc(len);
EVP_PKEY_encrypt(ctx,out,&len,(unsigned char*)data,read);
BIO_write(b,out,len);
}