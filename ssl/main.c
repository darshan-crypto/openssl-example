#include"common.h"

#define FAIL    -1

int main()

{   SSL_CTX *ctx;
    int server;
    SSL *ssl;
    char buf[100024];
    int bytes;
	BIO *b;
    char hostname[]="www.openssl.org";
    char portnum[]="443";
	
    char CertFile[] = "cert.crt";
    char KeyFile[] = "key.pem";
load();
    SSL_library_init();

    ctx = InitCTX();
    LoadCertificates(ctx, CertFile, KeyFile, "12345678");
    SSL_CTX_set_client_hello_cb(ctx,hellocallback,b);   
 //       printf("%s",ERR_error_string(ERR_get_error(), 0));

    ssl = SSL_new(ctx);     
   SSL_set_connect_state(ssl);
SSL_CTX_set_ssl_version(ctx,SSLv23_method());
  server = OpenConnection(hostname,atoi(portnum));
    SSL_set_fd(ssl, server);
    
       
  //    printf("%s",ERR_error_string(ERR_get_error(), 0));
	//BIO_get_ssl(b,& ssl);//, BIO_CLOSE);
    if ( SSL_connect(ssl) == FAIL )   /* perform the connection */
        ERR_print_errors_fp(stderr);
    else



    { 
      // int x = SSL_want(ssl);
        switch (SSL_want(ssl))
        {
        case SSL_WRITING:
        printf("helllo write");
            /* code */
            break;
        case SSL_READING:
        printf("helllo read");
            /* code */
            break;
        
        default:
         printf("%d",SSL_want(ssl));
            break;
        }
        
          char *msg = "GET / HTTP/1.1 \r\n"
"Host: www.openssl.org \r\n"
"User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:88.0) Gecko/20100101 Firefox/88.0 \r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8 \r\n"
"Accept-Language: en-US,en;q=0.5 \r\n"
//"Accept-Encoding:   gzip, deflate, br \r\n"
"Connection: close \r\n"
//"Cookie: NID=218=LJiYn5YphYie3QiObimGHuQHs4Aen8JJzBpdlNhLzFn5RP6XxPCGpDZXYqc-Gj8MczSZ0cGmzdktDEqzcL0Wcl9qAdj_PdSmURvSy1VXaQMbY87P_tcNKPxP934qwDF0vXp3yAthMoO8Deo172IAq_iPc5hh06mBqgQw8HgXFs23HCQQpGvyLyQYKUC4EOHdJ631JTk1xJW1-a8EcEqU00yk68r15STMy6mxq9j3EQsVC-bbqenjZKW56oSdrK5YLbXO; 1P_JAR=2021-07-02-07; ANID=AHWqTUkEP5bRCyYRnCdC2kdCwxlT2zkhwQI7nYSu0QDYplvfl4djmVxaPRVcstl6; SID=_Af1ngEiaSy2m8cGzn2C2J_EQdUaBXjQxrPpGyhFjcvyqolHw9PG5twihIJoVwv87tbcrQ.; __Secure-3PSID=_Af1ngEiaSy2m8cGzn2C2J_EQdUaBXjQxrPpGyhFjcvyqolHJAd0dTh7CDWOB3HgSgC95g.; HSID=A0Nw6k6c_vPXVVDbV; SSID=Ajp7MwOKewmtdrm0W; APISID=6SJ6csylXsyUnHe0/A4GC8I3wZ3Tw1EtUJ; SAPISID=Gp1en7YHnDh_-hwU/A_MOY-V4ZW_EEFuBv; __Secure-3PAPISID=Gp1en7YHnDh_-hwU/A_MOY-V4ZW_EEFuBv; SIDCC=AJi4QfGIh58GE_eVbD7tnqTkKf6VPlfIzoF-YhHQnSWwg5-84A3mwJLdh3po3KLn1gslc8oUxQ; __Secure-3PSIDCC=AJi4QfFkcyEJdNiPOsUHZ3qjCVfQcvm1HcMOzoSV5plHNMbAaywQtUCSw_9kpHoI3sJcldArtw; SEARCH_SAMESITE=CgQI-pIB; OGPC=19022552-1:19022519-2:; OGP=-19022519: \r\n"
"Upgrade-Insecure-Requests: 1 \r\n"
"If-Modified-Since: Thu, 17 Oct 2019 07:18:26 GMT \r\n"
//"If-None-Match: \"3147526947\" \r\n"
"Cache-Control: max-age=0 \r\n"
"TE: Trailers \r\n\r\n";

        printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
        ShowCerts(ssl);        /* get any certs */
        SSL_write(ssl, msg, strlen(msg));   /* encrypt & send message */
        
          switch (SSL_want(ssl))
        {
        case SSL_WRITING:
        printf("\nhelllo write");
            /* code */
            break;
        case SSL_READING:
        printf("\nhelllo read");
            /* code */
            break;
        
        default:
         printf("%d",SSL_want(ssl));
            break;
        }
        bytes = SSL_read(ssl, buf, sizeof(buf));
         bytes = SSL_read(ssl, buf+bytes, sizeof(buf));
         /* get reply & decrypt */
        //buf[bytes] = 0;
        printf("Received: %s \n", buf);
        SSL_free(ssl);        /* release connection state */
    }
    close(server);         /* close socket */
    SSL_CTX_free(ctx);     
       /* release context */
    printf("%ld",strlen(buf));
    
    // STACK_OF(X509_NAME) *m =  SSL_get0_peer_CA_list(ssl);
    // for(int i=0;i<sk_X509_NAME_num(m);i++){

    //     X509_NAME *n = sk_X509_NAME_VALUE_value(m,i);
    //      printf("\n %s",X509_NAME_oneline(n,0,0));
    // }

//   int xdd =  SSL_is_dtls(ssl);
  printf("\n%s",SSL_get_version(ssl));
  
  switch (SSL_version(ssl))
  {
  case SSL3_VERSION:
      printf("v3");
      break;
  case SSL3_VERSION_MAJOR:
     printf("wd");
     break;
  default:
 // TLS1_VERSION
 //SSL_version_str()
    printf("\n%d",SSL_version(ssl));
      break;
  }
  // printf("%d",x);
  //  return 0;
 printf("%s",ERR_error_string(ERR_get_error(), 0));
return 0;
}
