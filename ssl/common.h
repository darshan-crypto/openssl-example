#include<stdio.h>
#include<unistd.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
#include<string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include<openssl/x509.h>
#include<openssl/stack.h>
#include<openssl/safestack.h>
void load(){
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
     ERR_load_ERR_strings();
      ERR_load_SSL_strings();
    SSL_library_init();
}
SSL_CTX* InitCTX(void)
{
	const SSL_METHOD *method;
	SSL_CTX *ctx;

	OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
	SSL_load_error_strings();   /* Bring in and register error messages */
     
	method = SSLv23_client_method();
	ctx = SSL_CTX_new(method);   /* Create new context */
	if ( ctx == NULL )
	{
		ERR_print_errors_fp(stderr);
		abort();
	}
	return ctx;
}void ShowCerts(SSL* ssl)
{   X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);       /* free the malloc'ed string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);       /* free the malloc'ed string */
        X509_free(cert);     /* free the malloc'ed certificate copy */
    }
    else
        printf("No certificates.\n");
}
BIO* openbio(SSL_CTX *ctx,char* host ,char* port){

BIO *b = BIO_new_ssl(ctx,1);
char x[260]={0};
strcat(x,host);
strcat(x,":");
strcat(x,port);
if(b==0)printf("\n bio error");
BIO_set_conn_hostname(b,x);

return b;
}

int OpenConnection(const char *hostname, int port)
{   int sd;
    struct hostent *host;
    struct sockaddr_in addr;

    if ( (host = gethostbyname(hostname)) == NULL )
    {
        perror(hostname);
        abort();
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        close(sd);
        perror(hostname);
        abort();
    }
    return sd;
}
void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile, char* password)
{
	/* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
	
	/* set the private key from KeyFile (may be the same as CertFile) */
	SSL_CTX_set_default_passwd_cb_userdata(ctx, password);
    if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
	
    /* verify private key */
    if ( !SSL_CTX_check_private_key(ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}
int hellocallback(SSL *ssl,int *al,void *arg){


printf("\n callback\n\n\n");

//exit(1);
return SSL_CLIENT_HELLO_SUCCESS;
}