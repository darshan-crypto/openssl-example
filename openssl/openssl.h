#include<openssl/evp.h>
#include<openssl/rsa.h>
#include<openssl/err.h>
#include<openssl/pem.h>
#include<openssl/bio.h>
#include<string.h>
void load(){
      ERR_load_ERR_strings();
    ERR_load_RSA_strings();
    ERR_load_CRYPTO_strings();
    ERR_load_EVP_strings();
    OpenSSL_add_all_algorithms();
}
union _union_271 {
    char * ptr;
    struct rsa_st * rsa;
    struct dsa_st * dsa;
    struct dh_st * dh;
    struct ec_key_st * ec;
};
struct evp_pkey_st {
    int type;
    int save_type;
    int references;
    EVP_PKEY_ASN1_METHOD * ameth;
    ENGINE * engine;
    union _union_271 pkey;
    int save_parameters;
    struct stack_st_X509_ATTRIBUTE * attributes;
};
void  error(){

    printf("\n%s",ERR_error_string(ERR_get_error(),0));
}