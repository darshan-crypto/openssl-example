#include<stdio.h>
#include<openssl/bio.h>
#include<pcap/pcap.h>

#include<pcapplusplus/
#include<openssl/buffer.h>
int main(int argc, char const *argv[])
{
    BIO *b  ;
    BUF_MEM em;
    em.data="darshan9089";
    em.length=11;
    em.flags=BIO_FLAGS_NONCLEAR_RST;
    em.max=10;
    b = BIO_new(BIO_s_mem());
    char m[10];
    BIO_set_buffer_size(b,2);
   // BIO_set_mem_eof_return(b,100);
BIO_set_mem_buf(b,&em,BIO_CLOSE);
 // BIO_puts(b,"hello");
    BIO_read(b,m,10);
   //printf("%d\n",BIO_eof(b));
    printf("%s",m);
    return 0;
}
