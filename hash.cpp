/**
 * @file Hash.cpp  The hash tables member function for the required program
 * 
 * @brief
 *      Processes files and creates a hash table from data and outputs 
 *      the hash table to a file. Keeps track of some list statistics too.
 * 
 * @author Clint Bettiga
 * @date 11/08/13
 */

#include "hash.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;



/**
 * remove
 *
 *  Removes a word from the hash table. And recalculates
 *  the average at each remove.
 *
 * @param word String from the parsed file.
 */

void Hash::remove(string word){
  
  int hashLocation = hf(word);

  if(!hashTable[hashLocation].empty() && hashLocation <= HASH_TABLE_SIZE){
    
    if(search(word)){
      
      hashTable[hashLocation].remove(word);
      
      arr[hf(word)]--;
      
      calcAvg(); 
    }
  
  }
}


/**
 * print
 *
 *  Prints the hash table listing in the required format.
 * 
 */

void Hash::print(){
    
    for(int i=0;i<HASH_TABLE_SIZE;i++){
        
        cout<<i<<":\t";
        
        for (list<string>::iterator it=hashTable[i].begin(); it != hashTable[i].end(); ++it)
          cout << *it << ", ";

        cout<<endl;

    }

}


/**
 * processFile
 *
 *  Opens a file and adds data to hash table. Keeps track of the collisions, 
 *  longestlist, and the average list size by using an array.
 *
 * @param filename Passes the filename to be opened for processing
 */

void Hash::processFile(string filename){

  ifstream file(filename.c_str());
  
  string word;
  
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
    arr[i] = 0;

  while (getline(file, word)){

      int hashLocation = hf(word);

      if(!hashTable[hashLocation].empty())
        collisions++;

      hashTable[hashLocation].push_back(word);
      
      arr[hashLocation]++;
      
      calcAvg();
  }
  
  longestList = *max_element(arr, arr + HASH_TABLE_SIZE);
}


/**
 * search
 *
 *  Searches the hash table to see if a word exists in the list.
 *  Returns true if found. If not returns false. 
 *
 * @param word String from the parsed file.
 */


bool Hash::search(string word){

  int hashLocation = hf(word);

  if(!hashTable[hashLocation].empty()){
    for (list<string>::iterator it=hashTable[hashLocation].begin(); it != hashTable[hashLocation].end(); ++it)
      if(*it == word)
        return 1;

  }
  
  else
    return 0;

  return 0;
}



/**
 * output
 *
 *  Writes the required output to file
 *  
 * @param filename The name of the output file.
 */

void Hash::output(string filename){
  
  ofstream myfile (filename.c_str());
  
  if (myfile.is_open()){

    for(int i=0;i<HASH_TABLE_SIZE;i++){
        
        myfile<<i<<":\t";
        
        for (list<string>::iterator it=hashTable[i].begin(); it != hashTable[i].end(); ++it)
          myfile << *it << ", ";

        myfile<<endl;

    }
    
    myfile.close();

  }

}

/**
 * printStats
 *
 *  Prints the hash table required calculations
 * 
 */

void Hash::printStats (){

  cout<<"Total collisions = "<<collisions<<endl;
  cout<<"Longest list = "<<longestList<<endl;
  cout<<"Average list length = "<<avgLength<<endl;
}

/**
 * calcAvg
 *
 *  Calculates the average size of collision lists
 *  in the hash table.
 * 
 */

void Hash::calcAvg(){
  
  double sum = 0.0;

  for (int i = 0; i < HASH_TABLE_SIZE; i++)
    sum += arr[i];

  newAvgListLen = sum/HASH_TABLE_SIZE;
  
  avgLength = (newAvgListLen + avgLength) / 2.0;

}
