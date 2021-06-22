#include<stdio.h>
#include<openssl/evp.h>
#include<openssl/bio.h>
void setup(){

}
void help(){
   printf("Usage: [HASH Function] [FILE NAME]");
   printf("\nGenerate hash from file");
   printf("\nHASH FUNCTION : ");
   printf("MD5\n");
}
int main(int argc,char* argv[]){
setup();
FILE *input;

char c;
EVP_MD_CTX *ctx;
const EVP_MD *md;
unsigned char digest[EVP_MAX_MD_SIZE];
ctx = EVP_MD_CTX_new();
md = EVP_get_digestbyname(argv[1]);
if (md==0){help();return 1;}

input = fopen(argv[2],"r");
BIO *b = BIO_new_fp(input,1);
EVP_DigestInit_ex(ctx,md,0);
BIO_read(b,&c,1);
 while (!BIO_eof(b))
 {
    
    EVP_DigestUpdate(ctx,&c,1);
    
    BIO_read(b,&c,1);
 }
 int len;
 EVP_DigestFinal_ex(ctx,digest,&len);
for(int i =0;i<len;i++){
   printf("%02x",digest[i]);
}
printf("\n");
}