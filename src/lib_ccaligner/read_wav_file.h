/*
 * Author   : Saurabh Shrivastava
 * Email    : saurabh.shrivastava54@gmail.com
 * Link     : https://github.com/saurabhshri
*/

#ifndef CCALIGNER_READ_WAV_FILE_H
#define CCALIGNER_READ_WAV_FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int findIndex(std::vector<char>& fileData, std::vector<char>& searchString);

class WaveFileData
{
    std::string _fileName;
    std::vector<unsigned char> _fileData;
    std::vector<std::vector<double>> _samples;

    bool checkValidWave (std::vector<unsigned char>& fileData);
    bool parse();

    unsigned long fourBytesToInt (std::vector<unsigned char>& fileData, int index);
    int twoBytesToInt (std::vector<unsigned char>& fileData, int index);
    double twoBytesToDouble (int sample);

public:
    WaveFileData(std::string fileName);
    bool openFile();
    ~WaveFileData();
};

#endif //CCALIGNER_READ_WAV_FILE_H