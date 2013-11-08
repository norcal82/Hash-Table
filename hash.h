/* This assignment originated at UC Riverside. The hash table size
 should be defined at link time. Use -D HASH_TABLE_SIZE=X */

#ifndef __HASH_H
#define __HASH_H

#include <string>
#include <list>

using namespace std;

class Hash {

public:
  void remove ( string );
  void print ();
  void processFile ( string );
  bool search ( string );
  void output ( string );
  void printStats ();

private:
   list<string> hashTable [HASH_TABLE_SIZE];
   int collisions;
   int longestList;
   double avgLength;
   
private:
   int hf ( string );

// put additional variables/functions below
// do not change anything above!
// 
   void calcAvg();
   int arr[HASH_TABLE_SIZE];
   double newAvgListLen;
   
};

#endif
