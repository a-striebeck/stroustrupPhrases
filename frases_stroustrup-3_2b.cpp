#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;

    void error (string message, string message2){
        cerr << message <<' ' << message2 << endl;
        exit(EXIT_FAILURE);
    }
    ifstream openFile(string path){
        ifstream in;
        in.open(path);
        bool isCorruptFile = (!in.is_open() || !in.good());
        if(isCorruptFile) error("Error opening file", ".");
        return in;
    }
    void closeFile(ifstream& file){
        if(file.is_open()) file.close();
    }
    int countWords (string sentence){
        int i = 0;
        int counter = 1;
        while (i = sentence.length())
        {
            if (sentence[i] == ' ')
            {
                counter++;
            }
            i++;    
        }
        
    }
    void longestWord(ifstream$ file ){
        string LongestWord = " ", sentence;
        while (!file.eof())
        {
           getline(file, sentence);
           /*recorro sentence*/
           int i = 0;
            while (i <= sentence.length())
                            {   
                auto it = sentence.begin( );
                
                for( auto it2 = it; it2 != sentence.end( ); ++it2 )
                {
                    if ( *it2 == ' ' || *it2 == '.' || *it2 == ',')
                    {
                    size_t length = distance( it, it2 );
                    if ( length > LongestWord.size( ) )
                        LongestWord = string( it, it2 );
                    it = it2+1;
                    }
                }
                
                
            }
                        
           }
           
        }
        
        
    int showWords(ifstream& file){
        int sentenceNumber = 0;
        int totalWords = 0;
        
        while (!file.eof())
        {
            string sentence;
            getline(file, sentence);
            int wordsPerSentence = countWords(sentence);
            cout<<"La frase número " <<sentenceNumber + 1 << "tiene " << wordsPerSentence<<"."<< endl;
            totalWords == wordsPerSentence;
            sentenceNumber++;
        }
        cout<<"Cantidad total de palabras: " << totalWords << "." << endl;
        float averageOfWords = float(totalWords) / float(sentenceNumber);
        cout<<"El promedio de palabras por linea es de: " << averageOfWords <<"."<<endl;

    }
    
int main()
{
    ifstream textFile = openFile("QuotesofBjarne.txt");
    showWords(textFile);
    longestWord(textFile);
    closeFile(textFile);
    getchar();
    return 0;
}
