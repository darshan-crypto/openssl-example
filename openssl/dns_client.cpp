// #define OPENSSL_API_COMPAT
// #define OPENSSL_NO_SOCK
#include<iostream>
#include"dns.h"
#include<unistd.h>
#include<arpa/inet.h>
#include<openssl/bio.h>
using namespace std;
  unsigned char buf[65536],*qname,*reader;
    int i , j , stop , s;
 
    
 
    struct RES_RECORD answers[20],auth[20],addit[20]; //the replies from the DNS server
   
 
    struct DNS_HEADER *dns = NULL;
    struct QUESTION *qinfo = NULL;
 
int main(int argc, char const *argv[])
{
    BIO *bio;
    char res[100];
    bio  = BIO_new_connect("8.8.8.8:53");
 dns = (struct DNS_HEADER *)&buf;

    dns->id = (unsigned short) htons(getpid());
    dns->qr = 0; //This is a query
    dns->opcode = 0; //This is a standard query
    dns->aa = 0; //Not Authoritative
    dns->tc = 0; //This message is not truncated
    dns->rd = 1; //Recursion Desired
    dns->ra = 0; //Recursion not available! hey we dont have it (lol)
    dns->z = 0;
    dns->ad = 0;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1); //we have only 1 question
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;
  if(  BIO_do_connect(bio) !=1)cout << "\nerror while connecting ";
    BIO_puts(bio,"www.google.com");
    BIO_read(bio,res,100);
    cout << res;


        return 0;
}

