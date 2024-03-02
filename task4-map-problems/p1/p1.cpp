#include "p1.h"
using namespace std;

bool ransom_note(string ransomNote, string magazine){
   map <char , int> mag ;
   for (auto it : magazine){
    mag[it]++;
   }
   for (auto it : ransomNote){
    if (!mag[it]--)
    {
        return false;
    }
   }
   return true ; 
};
