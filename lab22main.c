#include <stdio.h>
#include "lab22functs.h"
#define FILE_NAME_LEN 100


int main(void) {

   char fileName1[FILE_NAME_LEN] = "";
   char fileName2[FILE_NAME_LEN] = "";

   char wordList[MAX_NUM_WORDS][MAX_WORD_LEN];

   printf("enter the first filename: ");
   scanf("%s", fileName1);
   printf("enter the first filename: ");
   scanf("%s", fileName2);
 
   FILE* inFile = NULL;
   char word[MAX_WORD_LEN] = "";
   char wordListMaster[MAX_NUM_WORDS][MAX_WORD_LEN];
   int wlmListCount = 0;
   char wordList1[MAX_NUM_WORDS][MAX_WORD_LEN];
   int wl1ListCount = 0;
   char wordList2[MAX_NUM_WORDS][MAX_WORD_LEN];
   int wl2ListCount = 0;
   int bGrams1[MAX_NUM_WORDS][MAX_NUM_WORDS];
   int bGrams2[MAX_NUM_WORDS][MAX_NUM_WORDS];

   // open file 1
   inFile = openFile(fileName1, "r");

   // for each string in file 1
   while(!feof(inFile)){
       if(getStringFromFile(inFile, word)){
           if(cleanString(word)){
               // add to master word list
               wlmListCount = addUniqueStringToList(word, wordListMaster, wlmListCount);
               // add to file word list
               wl1ListCount = addStringToList(word, wordList1, wl1ListCount);
           }
       }
   }
   fclose(inFile);

   // same as above for file 2
   inFile = openFile(fileName2, "r");
   while(!feof(inFile)){
       if(getStringFromFile(inFile, word)){
           if(cleanString(word)){
               // add to master word list
               wlmListCount = addUniqueStringToList(word, wordListMaster, wlmListCount);
               // add to file word list
               wl2ListCount = addStringToList(word, wordList2, wl2ListCount);
           }
       }
   }
   fclose(inFile);

// displayWordList(wordList1, wl1ListCount);
// displayWordList(wordList2, wl2ListCount);
// displayWordList(wordListMaster, wlmListCount);

   // compute bigram 1 using file1 word list
   countBiGrams(bGrams1, wordList1, wordListMaster, wl1ListCount, wlmListCount);

   // compute bigram 2 using file2 word list
   countBiGrams(bGrams2, wordList2, wordListMaster, wl1ListCount, wlmListCount);

   // compare bigrams
   double result = compareBiGrams(bGrams1, bGrams2,  wlmListCount);

   printf("%lf\n", result);

}