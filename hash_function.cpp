/* This assignment originated at UC Riverside.*/
 
#include <string>
#include "hash.h"

using namespace std;


typedef unsigned int uint32;
#define FNV1_32A_INIT 0x811c9dc5
#define FNV_32_PRIME 0x01000193

int 
Hash::hf ( string ins ) {
  

 //  int hash = 5381;

 //  for(unsigned int i = 0; i < ins.length(); i++)
 //  	hash = ((hash << 5) + hash) + ins.at(i);
 //  // place your hash function here....
 //  return hash % HASH_TABLE_SIZE;

	// return ( (int) ins[0] ) % HASH_TABLE_SIZE;

	//REFRENCE
	//FNV-1a Hash (http://isthe.com/chongo/tech/comp/fnv/) in C++.

	uint32 hval = FNV1_32A_INIT;


	for(unsigned int i = 0; i < ins.length(); i++){
  	  hval ^= (uint32)ins.at(i);
      hval *= FNV_32_PRIME;
	}

	return hval % HASH_TABLE_SIZE;
}

