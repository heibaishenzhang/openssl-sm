#include <string.h>
#include <stdio.h>
#include "sm3.h"

//Testing data from SM3 Standards
//http://www.oscca.gov.cn/News/201012/News_1199.htm 
// Sample 1
// Input:"abc"  
// Output:66c7f0f4 62eeedd9 d1f2d46b dc10e4e2 4167c487 5cf2f7a2 297da02b 8f4ba8e0

// Sample 2 
// Input:"abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd"
// Outpuf:debe9ff9 2275b8a1 38604889 c18e5a4d 6fdb70e5 387e5765 293dcba3 9c0c5732

int main( int argc, char *argv[] )
{
	unsigned char *input = "abc";
	int ilen = 3;
	unsigned char output[32];
	int i;
	SM3_ctx ctx;

	printf("Input: %s\n",input);

	SM3(input, ilen, output);
	
	printf("Hash:\n   ");
	for(i=0; i<32; i++) {
		printf("%02x",output[i]);
		if (((i+1) % 4 ) == 0) printf(" ");
	}
	printf("\n");

	printf("Message:\n");
	for(i=0; i < 16; i++)
		printf("abcd");
	printf("\n");

    SM3_Init( &ctx );
    for(i=0; i < 16; i++)
        SM3_Update( &ctx, "abcd", 4 );
    SM3_Final( &ctx, output );
    memset( &ctx, 0, sizeof( SM3_ctx ) );

	printf("Hash:\n   ");
	for(i=0; i<32; i++) {
		printf("%02x",output[i]);
		if (((i+1) % 4 ) == 0) printf(" ");
	}
	printf("\n");
	
	return 0;
}
