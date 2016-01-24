#ifndef SM3_H_
#define SM3_H_


#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__LP32__)
#define SM3_LONG unsigned long
#elif defined(OPENSSL_SYS_CRAY) || defined(__ILP64__)
#define SM3_LONG unsigned long
#define SM3_LONG_LOG2 3
#else
#define SM3_LONG unsigned int
#endif

#define SM3_LBLOCK 16
#define SM3_CBLOCK (SM3_LBLOCK*4)
#define SM3_LAST_BLOCK  (SM3_CBLOCK-8)
#define SM3_DIGEST_LENGTH 32 /*SM3 is 256bits vs sha1 160bits*/

typedef struct SM3state_st
{
    unsigned long total[2];
    unsigned long state[8];
    unsigned char buffer[64];
    unsigned char ipad[64];
    unsigned char opad[64];
} SM3_CTX;

int SM3_Init(SM3_CTX *c);
int SM3_Update(SM3_CTX *c, const void *data, size_t len);
int SM3_Final(SM3_CTX *c, unsigned char *md);
unsigned char* SM3(const unsigned char *d, size_t n, unsigned char *md);
int SM3_Transform(SM3_CTX *c, const unsigned char *data);

void SM3_HMAC_Init( SM3_CTX *ctx, unsigned char *key, int keylen);
void SM3_HMAC_Update( SM3_CTX *ctx, unsigned char *input, int ilen );
void SM3_HMAC_Final( SM3_CTX *ctx, unsigned char output[32] );
void SM3_HMAC( unsigned char *key, int keylen, unsigned char *input, int ilen, unsigned char output[32] );

#ifdef __cplusplus
}
#endif

#endif//SM3_H_
