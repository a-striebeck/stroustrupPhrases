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

string showFile(ifstream& file){
while (!file.eof())
    {
        string line;
        getline(file, line);
        cout << line << endl;
        cout << endl;
    }
}



int main()
{
    ifstream inputFile;
    openFile("QuotesofBjarne.txt");    
    showFile(inputFile);
    closeFile(inputFile);

    return 0;
}