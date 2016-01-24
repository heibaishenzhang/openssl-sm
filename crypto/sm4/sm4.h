/**
 * \file sm4.h
 */
#ifndef SM4_H
#define SM4_H

#define SM4_ENCRYPT     1
#define SM4_DECRYPT     0

#ifdef __cplusplus
extern "C" {
#endif

void SMS4_crypt(unsigned char *input, unsigned char *output, unsigned int *rk) ;

void SMS4_key_init(unsigned char *key, unsigned int *rk, unsigned int cryptFlag) ;

#ifdef __cplusplus
}
#endif

#endif//SM4_H
