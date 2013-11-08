#include "hash.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void Hash::remove(string word){
  
  int hashLocation = hf(word);

  if(!hashTable[hashLocation].empty() && hashLocation <= HASH_TABLE_SIZE){ // if table exists
    if(search(word)){
      hashTable[hashLocation].remove(word);
      arr[hf(word)]--; // decrement the list count
      calcAvg(); 
    }
  }
}

void Hash::print(){
    
    for(int i=0;i<HASH_TABLE_SIZE;i++){
        
        cout<<i<<":\t";
        
        //print line from 
        for (list<string>::iterator it=hashTable[i].begin(); it != hashTable[i].end(); ++it)
          cout << *it << ", ";

        cout<<endl;

    }

}


void Hash::processFile(string filename){

  ifstream file(filename.c_str());
  
  string word;
  
  for (int i = 0; i < HASH_TABLE_SIZE; i++){
    arr[i] = 0;
  }

  while (getline(file, word)){

      int hashLocation = hf(word);
      if(!hashTable[hashLocation].empty()){
        collisions++;
      }
      //call hashing function for location and push_back data at index
      hashTable[hashLocation].push_back(word);
      arr[hashLocation]++;
      calcAvg();
  }
  longestList = *max_element(arr, arr + HASH_TABLE_SIZE);
}

bool Hash::search(string word){

  int hashLocation = hf(word);

  if(!hashTable[hashLocation].empty()){ // if table exists 
    for (list<string>::iterator it=hashTable[hashLocation].begin(); it != hashTable[hashLocation].end(); ++it) //iterate through the list and check
      if(*it == word)
        return 1;

  }
  
  else
    return 0;

  return 0;
}

void Hash::output(string filename){
  
  // open file with filename passed
  ofstream myfile (filename.c_str());
  
  if (myfile.is_open()){ // make sure its open and writeable

    for(int i=0;i<HASH_TABLE_SIZE;i++){
        
        myfile<<i<<":\t";
        
        //print line from 
        for (list<string>::iterator it=hashTable[i].begin(); it != hashTable[i].end(); ++it)
          myfile << *it << ", ";

        myfile<<endl;

    }
    
    myfile.close(); //close the file when fished writing to

  }

}

void Hash::printStats (){

  cout<<"Total collisions = "<<collisions<<endl;
  cout<<"Longest list = "<<longestList<<endl;
  cout<<"Average list length = "<<avgLength<<endl;
}

void Hash::calcAvg(){
  
  double sum = 0.0;

  for (int i = 0; i < HASH_TABLE_SIZE; i++){
    sum += arr[i];
  }

  newAvgListLen = sum/HASH_TABLE_SIZE;
  
  avgLength = (newAvgListLen + avgLength) / 2.0;
  
  //cout<<newAvgListLen<<" : "<<avgLength<<endl;
  // for (int i = 0; i < HASH_TABLE_SIZE; i++)
  //   cout<<arr[i]<<", ";
  // cout<<endl;

}