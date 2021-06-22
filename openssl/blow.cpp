#include<iostream>
#define OPENSSL_API_COMPAT 1
#include<string.h>
#include<openssl/evp.h>
#include<openssl/blowfish.h>
using namespace std;
int main(int argc, char const *argv[])
{
  EVP_add_cipher(EVP_bf_ecb());
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    unsigned const char *iv = (unsigned char*)"0123456789012345";
    unsigned char encrypted[100];

    int cipherl,len;
//unsigned char* const plaintext = "hello data is to"; 
  unsigned const char * plaintext =(unsigned char *) "hello123";
    unsigned const char *key =  (unsigned char*)"aaaaaaaa";
   const EVP_CIPHER *cipher  = EVP_bf_ecb();
   EVP_EncryptInit_ex(ctx,cipher,0,key,0);
   EVP_EncryptUpdate(ctx,encrypted,&len,plaintext,strlen((char*)plaintext));
   cipherl = len;
      EVP_EncryptFinal(ctx,encrypted+len,&len);
cipherl += len;
    //out << (char*)encrypted
    encrypted[cipherl+1] ='\0';
    
;    BIO_dump_fp (stdout, (const char *)encrypted,cipherl);



EVP_CIPHER_CTX *dec;
dec = EVP_CIPHER_CTX_new();
  int dlen;

    int dplaintext_len;

  
 
  EVP_DecryptInit_ex(dec, EVP_bf_ecb(), NULL, key,0 );
      
unsigned char  dectext[10];    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    EVP_DecryptUpdate(dec, dectext, &dlen, encrypted, cipherl);
    dplaintext_len = len;

    /*
     * Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
 EVP_DecryptFinal_ex(ctx, dectext + dlen, &dlen);
       
    dplaintext_len += len;
 dectext[dplaintext_len] = '\0';
    /* Clean up */

//BIO_dump_fp (stdout, (const char *)plaintext, dplaintext_len);
printf("%s",dectext);
    return 0;
}
