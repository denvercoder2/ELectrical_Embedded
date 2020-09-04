/**
 * Anagram Generator:
 * Built and tested by River Holley
 * GPL Free Liscence
*/
#include <iostream> 
#include <string.h>
#include <vector>
#include <sstream>
#include <stdio.h>


/* May replace with a struct in the future */
std::vector<std::string> AlphabetFruits() {

    std::vector<std::string> Fruits_and_Common_Words = {
        "apple",
        "banana",
        "coconut",
        "dog",
        "egg",
        "fig",
        "go",
        "hex",
        "idaho",
        "jump",
        "kiwi",
        "lemon",
        "mango",
        "nice",
        "orange",
        "pizza",
        "quest",
        "river",
        "sweaty",
        "toes",
        "ugly",
        "vols",
        "water",
        "xeon",
        "yesterday",
        "zebra"
    };

    return Fruits_and_Common_Words; /* A vector containing the first characters of all words entered */
}


std::vector<std::string> getOriginPhrase() {

    std::string line;
    std::string word;
    std::vector<std::string> words;

    std::cout << "Enter the main words in the phrase separated by spaces in lowercase letters: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> word) {
        words.push_back(word);
    }

    return words;   /*words is a vector of words*/
} 

std::vector<char> setupAnagram(std::vector<std::string> phrase) {

    int i;
    char firstLetter;
    printf("Original Phrase: \n");
    std::vector<char> Anagrams;

    /* show the original phrase and pick out the first letter*/
    for (i = 0; i < phrase.size(); i++){
        printf("Word #%d: %s\n", i, phrase[i].c_str());
        firstLetter = phrase[i].at( 0 );
        Anagrams.push_back(firstLetter);
    }

    for (i = 0; i < Anagrams.size(); i++){
        printf("First letter of word #%d: %c\n", i, Anagrams[i]);
    }

    return Anagrams; /* A vector containing the first characters of all words entered */
}



std::vector<std::string> MakeAnagram(std::vector<char> FirstLetterVector){
    int i;
    std::vector<std::string> refrenceVector = AlphabetFruits();
    std::vector<std::string> CompletedAnagram;

    /**
     *  Get the first letter of elements in the reference vector
     *  to compare to the entered one and return the phrase of 
     *  anagrams that matches between the two vectors
     */
    
    for (i = 0; i < FirstLetterVector.size(); i++) {
        if (FirstLetterVector[i] == refrenceVector[i].at(0)) {
            printf("Matching letter %c to word: %s\n", FirstLetterVector[i], refrenceVector[i].c_str());
            CompletedAnagram.push_back(refrenceVector[i]);
        }
    }
    return CompletedAnagram;
}


int main(int argc, char** argv){
    int i;
    std::vector<std::string> phrase = getOriginPhrase();
    std::vector<char> FirstLetterInput = setupAnagram(phrase);

    std::vector<std::string> AnagramVector = MakeAnagram(FirstLetterInput);

    printf("Anagrammed phrase for entered words: \n");
    for (i = 0; i < AnagramVector.size(); i++) {
        printf("%s \n", AnagramVector[i].c_str());
    }

    system("pause");
}
