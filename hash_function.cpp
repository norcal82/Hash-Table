/* This assignment originated at UC Riverside.*/
 
#include <string>
#include "hash.h"

using namespace std;


typedef unsigned int uint32;
#define FNV1_32A_INIT 0x811c9dc5
#define FNV_32_PRIME 0x01000193

int 
Hash::hf ( string ins ) {
  


	//REFRENCE
	//FNV-1a Hash (http://isthe.com/chongo/tech/comp/fnv/) in C++.
	
	uint32 hval = FNV1_32A_INIT;
	
	
	for(unsigned int i = 0; i < ins.length(); i++){
		hval ^= (uint32)ins.at(i);
		hval *= FNV_32_PRIME;
	}
	
	return hval % HASH_TABLE_SIZE;
}

