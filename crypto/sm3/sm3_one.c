#include <stdio.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/sm3.h>

#ifndef OPENSSL_NO_SM3
unsigned char *SM3(const unsigned char *d, size_t n, unsigned char *md)
{
    SM3_CTX c;
    static unsigned char m[32];

    if (md == NULL)
        md = m;
    if (!SM3_Init(&c))
        return NULL;
    SM3_Update(&c, d, n);
    SM3_Final(&c, md);
    OPENSSL_cleanse(&c, sizeof(c));
    return (md);
}
#endif
