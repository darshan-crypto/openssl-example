#include<iostream>
#include<openssl/evp.h>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned char* text= (unsigned char *)"hello i am a darshan openssl cryptography api hello i am a darshan openssl cryptography api hello i am a darshan openssl cryptography api";
    unsigned char  encodetext[1024];
    int len,len2;
    EVP_ENCODE_CTX *ctx = EVP_ENCODE_CTX_new();
        EVP_ENCODE_CTX *ctx2 = EVP_ENCODE_CTX_new();
    EVP_EncodeInit(ctx);
    EVP_EncodeUpdate(ctx,encodetext,&len,text,strlen((char*)text));
    cout  << len<<endl;
    EVP_EncodeFinal(ctx,encodetext+len,&len2);
    len += len2;

    for(int i=0;i<len;i++){
        printf("%c",encodetext[i]);
    }
cout << endl;    
    EVP_DecodeInit(ctx2);
    int d1,d2;
    unsigned char decode[1024];
    EVP_DecodeUpdate(ctx,decode,&d1,encodetext,len);
    EVP_DecodeFinal(ctx,decode+d1,&d2);
     d1+=d2;

     printf("%s",decode);
        return 0;
}

