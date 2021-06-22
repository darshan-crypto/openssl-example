
#include <iostream>

#include<openssl/evp.h>
#include<cstring>
#include <openssl/err.h>
using namespace std;
int main()
{
;
    ERR_load_BIO_strings();
    ERR_load_ERR_strings();

  EVP_CIPHER_CTX *ctx =  EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX *ctx2 =  EVP_CIPHER_CTX_new();
  const  EVP_CIPHER* cipher = EVP_bf_ecb();
  
  
  
    unsigned char *key = (unsigned char *)"0123456789";

  char* data =(char*)"hello darshan";
  unsigned char* iv = (unsigned char*)"0123456789";
  unsigned char  encrypted[1024];
  unsigned char   text[1024];
  int enclen,temp;
  int decryptedlen;
  
  
  EVP_EncryptInit_ex(ctx, cipher,NULL, key,0);
  EVP_EncryptUpdate(ctx, encrypted, &enclen, (unsigned char*)data, strlen((const char*)data));
  
  EVP_EncryptFinal(ctx, encrypted + enclen, &temp);
  enclen += temp;
  
  for (int i = 0; i <enclen; i++) {
	  printf("%02x", encrypted[i]);

  }
//   int temp2;
//   EVP_DecryptInit_ex(ctx2, cipher,NULL, key,0);
//   EVP_DecryptUpdate(ctx2, text, &decryptedlen, encrypted,strlen((char*)encrypted));
//   EVP_DecryptFinal_ex(ctx2, text + decryptedlen, &temp2);
//   decryptedlen += temp2;
//   cout << endl;
  
//   for (int i = 0; i < decryptedlen/2; i++) {
// 	  printf("%c", encrypted[i]);
	   
//   }
int len,plaintext_len;
   EVP_DecryptInit_ex(ctx2, EVP_bf_ecb(), NULL, key, 0);
        //  cout << endl
      //    << ERR_error_string(ERR_get_error(), 0);
   cout << endl <<endl
          << ERR_reason_error_string(ERR_get_error());
  
   
EVP_DecryptUpdate(ctx2,text, &len, encrypted,enclen);
    
    plaintext_len = len;
    
   EVP_DecryptFinal_ex(ctx2, text + len, &len);
    
    plaintext_len += len;
    text[plaintext_len]= '\0';
	  printf("%s",text); 
  //}
}
