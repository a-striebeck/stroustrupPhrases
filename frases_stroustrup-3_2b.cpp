#include <iostream>
#include <fstream>
#include <string>

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
    closeFile(textFile);

    return 0;
}
