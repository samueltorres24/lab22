#include <stdio.h>
#define MAX_WORD_LEN 15
#define MAX_NUM_WORDS 300

/* @brief open a file saftly
 * @param fName the name of the file to open
 * @param fMode the mode to open the file in (e.g., "r")
 * @return file pointer of the open file
 * @pre none
 * @post the file is open, or the program terminates
 */
FILE* openFile(char fName[], char fMode[]);

/* @brief clean a string leaving only words
 * @param word - a string to clean
 * @return true of a word is returned in word
 * @pre word is null-terminated string
 * @post word is null-terminated, lowercase, no puctuation, no numbers
 * 
 * if the input string has a number, return false
 * the string is terminated where any non-alpha is found
 * "Yay!" --> "yay"
 * "fo0l" --> ""
 * "MuEy" --> "muey"
 */
bool cleanString(char word[]);

/* @brief read a string from a file
 * @param inFile the file to read from
 * @param word the char array to read into
 * @return true if a word was read from file
 * @pre the file is open
 * @post the array word has a string if return was true
 */
bool getStringFromFile(FILE* inFile, char word[MAX_WORD_LEN]);

/* @brief append a word to an array of strings
 * @param word the word to append to list
 * @param wordList an array of strings
 * @param words the count of words already in the array
 * @return the new cound of words (incremented)
 * @pre count is not negative
 * @post the list is one string longer
 */
int addStringToList(char word[], char wordList[][MAX_WORD_LEN], int words);

/* @brief append a word to an array of strings, if not already in the list
 * @param word the word to append to list
 * @param wordList an array of strings
 * @param words the count of words already in the array
 * @return the new cound of words (incremented if string is appended)
 * @pre count is not negative
 * @post the list contains no duplicate strings
 */
int addUniqueStringToList(char word[], char wordList[][MAX_WORD_LEN], int words);

/* @brief search array for string 
 * @param word the word to search for
 * @param wordList the list of words to search
 * @param length the length of the list of words
 * @return index value
 * @pre the word is int the list
 * @post the list is unchanged
 */
int getWordListNum(char word[], char wordList[][MAX_WORD_LEN], int length);

/* @brief count the number of word-pairs
 * @param bGram 2D array that holds word pair counts
 * @param wordList 1D array of strings (2D char array) of words to add
 * @param masterWordList 1D array of strings providing indexing
 * @param wordCount number of words in fileWord array
 * @param masterCount number of words in masterList
 * @pre wordList and masterWordList are populated, counts are not negative
 * @post bGram array has count of bigram instances
 */
void countBiGrams(int bGrams[MAX_NUM_WORDS][MAX_NUM_WORDS], char wordList[][MAX_WORD_LEN], char masterWordList[][MAX_WORD_LEN], int wordCount, int masterCount);

/* @brief compare two biGram arrays producing a similarity measure
 * @param bGram1 one biGram array
 * @param bGram2 another biGram array
 * @wordCount size of biGram arrays
 * @pre biGram arrays have been computed, wordCount is right
 * @post none
 */
double compareBiGrams(int bGram1[][MAX_NUM_WORDS], int bGram2[][MAX_NUM_WORDS], int wordCount);

void displayWordList(char wordList[][MAX_WORD_LEN], int length);

void displayBiGrams(int biGrams[][MAX_NUM_WORDS], int size);