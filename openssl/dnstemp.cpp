#include<iostream>
#include<string.h>
using namespace std;

void ChangetoDnsNameFormat(unsigned char* dns,unsigned char* host) 
{
    int lock = 0 , i;
    strcat((char*)host,".");
    // cout << host ;
    // for(i = 0 ; i < strlen((char*)host) ; i++) 
    // {
    //     if(host[i]=='.') 
    //     {
    //         *dns++ = i-lock;
    //         for(;lock<i;lock++) 
    //         {
    //             *dns++=host[lock];
    //         }
    //         lock++; //or lock=i+1;
    //     }
    // }
    // *dns++='\0';
}
int main(int argc, char const *argv[])
{
  unsigned  char dns[100];
   unsigned char *host=(unsigned char*)"www.google.com";
   ChangetoDnsNameFormat(dns,host);
//cout << dns;
    return 0;
}
