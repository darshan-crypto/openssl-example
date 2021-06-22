#include<stdio.h>
#include<openssl/hmac.h>
void main(){
const EVP_MD *md = EVP_get_digestbyname("md5");
 char* key = "hello";
 unsigned char * data = "darshan";
HMAC_CTX *ctx  = HMAC_CTX_new();
HMAC_Init_ex(ctx,key,5,md,0);
HMAC_Update(ctx,data,7);
unsigned char mdhash[1024];
int len;
HMAC_Final(ctx,mdhash,&len);
for(int i=0;i<len;i++)
{
    printf("%02x",mdhash[i]);
}






}
