#include<stdio.h>
#include<openssl/evp.h>
#include<string.h>

int main(int argc, char  *argv[])
{
    BIO *b = BIO_new_file(argv[1],"r");
 
    int enclen,temp,readed;
    if (b==NULL)
    {
       printf("error");
       return 101;
    }
    
 char new[255]="";
  strcat(new,argv[1]);
 strcat(new,".denc");
// printf("\n %s",new);
 unsigned char* key ="0123456789";
BIO *nb = BIO_new_file(new,"a+");
const EVP_CIPHER *cipher =EVP_bf_ecb();
EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
if (nb=NULL)
{
    printf("\nerror");
    return 101;
}

   FILE *x=    fopen(new,"ab");
    while (BIO_eof(b) != 1)
    {
 int enclen=0,temp,readed;
    unsigned char encrypted[1024];
   unsigned char plaintext[1024];
     int read =  BIO_read(b,(char *)plaintext,1024);
  //   printf("\n %d %s",read,plaintext);
     EVP_EncryptInit(ctx,cipher,key,0);
     EVP_EncryptUpdate(ctx,encrypted,&temp,plaintext,read);
     enclen+=temp;
    // printf("%d",temp);
     EVP_EncryptFinal(ctx,encrypted+temp,&temp);
     enclen+=temp;
      //   printf("\n%d\n",enclen);
    
    
    
  fwrite(encrypted,sizeof(unsigned char),enclen,x);
   //for(int i=0;i<enclen;i++){
     // char m[1024];
      //  printf("%02x",encrypted[i]);
    //BIO_snprintf(m,1024,"%02x",encrypted[i]);
    // printf( "\n %d",BIO_write(b,m,2));
  //  fwrite(decrypted[i],1,2,x);
    //printf("%s",m);
  //  }

  
  //  printf("%s",m);

// 
    }
    



    return 0;
}
