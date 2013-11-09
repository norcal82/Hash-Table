/* This assignment originated at UC Riverside.*/

/**
 * @file hash_function.cpp  hashing function for our table.
 * 
 * @brief
 *    Is the FNV-1a hashing function. Differs from the FNV-1 becuase of the order of the XOR and multiply step.
 *    It's a well known hash and is reliable (http://isthe.com/chongo/tech/comp/fnv/#history).
 *
 *    REFERENCE:
 *    (http://isthe.com/chongo/tech/comp/fnv/)
 *
 * @author Clint Bettiga
 * @date 11/08/13
 */


#include <string>
#include "hash.h"

using namespace std;


typedef unsigned int uint32;

#define FNV1_32A_INIT 0x811c9dc5
#define FNV_32_PRIME 0x01000193

int 
Hash::hf ( string ins ) {

	uint32 hval = FNV1_32A_INIT;


	for(unsigned int i = 0; i < ins.length(); i++){
  	  hval ^= (uint32)ins.at(i);
      hval *= FNV_32_PRIME;
	}

	return hval % HASH_TABLE_SIZE;
}

