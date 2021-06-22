#include<iostream>
#include<openssl/async.h>
#include<openssl/err.h>
using namespace std;
int async(void*){

    for(int i =0;i<=10;i++)cout << "\n"<<i;
    return ASYNC_FINISH;
}

int main(){
ASYNC_JOB *m;
ASYNC_WAIT_CTX *c  = ASYNC_WAIT_CTX_new();
OPENSSL_init();
if( ASYNC_init_thread(0,0) !=1){
    cout << "init error";
}
try
{
    /* code */
//ASYNC_start_job(0,c,0,&async,0,0);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

 cout << endl <<  ERR_error_string(ERR_get_error(),0);
     cout << endl << ERR_reason_error_string(ERR_get_error());
 
    return 0;
}