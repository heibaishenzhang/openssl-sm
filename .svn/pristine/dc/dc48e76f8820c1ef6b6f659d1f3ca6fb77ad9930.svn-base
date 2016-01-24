#include <string.h>
#include <stdio.h>
#include "sm4.h"

int main(int argc, char* argv[])
{
    muint8 key[16]={0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 ,0x0,0x0,0x0,0x00};
    muint8 m[16]={0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98 ,0x76,0x54,0x32,0x10};
    muint8 c[16];
    muint32 rk[32];

    for (int mn=0;mn<1;mn++) {

        SMS4_init_key( (muint8 *)key, rk, ENCRYPT);
        SMS4_crypt(m,c,rk);

        for(int i=0;i<16;i++)
            printf("%x ",c[i]);

        printf("\n");

        SMS4_init_key( (muint8 *)key, rk, DECRYPT);
        SMS4_crypt(c,m,rk);

        for(i=0;i<16;i++)
            printf("%x ",m[i]);
    }
}

