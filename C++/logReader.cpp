// Simple program to read a given file and output the number of times an error is found
// Planned: Expand functionality -- can be expanded to capture more types of errors/attention items found in logs\
// Also considering: Notifications, automated detection of log file location 
// currently tested against logs produced by Unix based systems

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileLogReader
{
    public:
    FileLogReader(string filePath)
    {
        processFile(filePath);
    }
    int GeterrCount()
    {
        return errcount;
    }

    private:
        int errcount{0};
        void processFile(string file);
        vector<string> split (string str, string delimiter);
};

void FileLogReader::processFile(string file)
{
    string rawData;
    ifstream input_file(file);
    if (!input_file.is_open()) 
    {
        cerr << "Could not open file - '"
             << file << "'" << endl;
        exit(EXIT_FAILURE);
    }
    rawData = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    auto words = split(rawData,"\n");
    for(auto word : words)
    {   
        if(word.find("Failed password") != string::npos || word.find("authentication failure") != string::npos)
            ++errcount;
    }
}

vector<string> FileLogReader::split (string str, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = str.find (delimiter, pos_start)) != string::npos) 
    {
        token = str.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (str.substr (pos_start));
    return res;
}


int main()
{
    FileLogReader fileLogR("C:\\Users\\Jeff\\Downloads\\Authlogs\\auth.log");
    cout<<"Error Count: "<<fileLogR.GeterrCount()<<endl;
}
