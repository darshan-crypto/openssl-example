//#define OPENSSL_API_COMPAT 0x10100000L
#define OPENSSL_NO_DEPRECATED
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>
#include<openssl/md5.h>


int main(int argc, char const *argv[])
{
    const EVP_MD *md;
    EVP_MD_CTX *ctx;
    char text[]="hello world";
    char text2[]=" darshan";
  unsigned  char digest[EVP_MAX_MD_SIZE],encode[100];
    ctx =  EVP_MD_CTX_new();
    unsigned int len;
    if (ctx == 0)
    {
     printf("\n ctx error");

    }

    md = EVP_get_digestbyname("sha256");
    if (md == 0)
    {
     printf("\nerror on md");
    }
    EVP_DigestInit_ex(ctx,md,0);
    EVP_DigestUpdate(ctx,text,strlen(text));
     EVP_DigestUpdate(ctx,text2,8);
    EVP_DigestFinal_ex(ctx,digest,&len);
printf("\n %d\n",len);
for(int i =0;i<len;i++)
{
    printf("%02x",digest[i]);
}
printf("\n");
EVP_ENCODE_CTX *c = EVP_ENCODE_CTX_new();
EVP_EncodeInit(c);
int leno;
EVP_EncodeUpdate(c,encode,&leno,digest,len);
EVP_EncodeFinal(c,encode,&leno);
for(int i =0;i<leno;i++)
{
    printf("%c",encode[i]);
}
    return 0;
}
