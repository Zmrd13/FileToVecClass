//
// Created by Weder on 06.11.2022.
//

#ifndef FILETOVECCLASS_FILEVEC_H
#define FILETOVECCLASS_FILEVEC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using lli = long long int;
using namespace std;
/**
 * Class for keeping file as vector<long long int>
 */
class FileVec {
private:
    vector<lli> bytes;
public:
    explicit FileVec(const string &name = "foo", const string &path = "", bool enc = false) {
        ifstream input(name, std::ios::binary);
        if (!input.is_open()) {
            return ;
        }
        char temp;
        string tempStr;
        input >> std::noskipws;
        if (!enc) {
            while (input >> temp) {
                bytes.push_back(temp);
            }
        } else {
            while (getline(input, tempStr, ',')) {
                //    cout<<tempStr;
                bytes.push_back(atoll(tempStr.c_str()));
            }
        }
        input.close();
        if (input.is_open()) {
            return ;
        }
    }

    FileVec(vector<lli> in) {
        bytes = std::move(in);
    }
/**
 * print content of inner vector (std::cout)
 */
    void show() {
        for (auto &i: bytes) {
            cout << i;
        }
    }
/**
 * @return  inner vector
 */
    vector<lli> getVector() {
        return bytes;
    }
/**
 * write to file as long long int with delimiter ","
 *  * @return 0/1 as done/error
 */
    int outToFile(const string &name = "foo") {
        ofstream outputFile(name, ios::binary | ios::out);
        if (!outputFile.is_open()) {
            return 1;
        }
        ostream_iterator<lli> outputIter(outputFile, ",");
        copy(bytes.begin(), bytes.end(), outputIter);
        outputFile.close();
        if (outputFile.is_open()) {
            return 1;
        }
        return 0;
    }
/**
 * write to file as char without delimiter
 * @return 0/1 as done/error
 */
    int decToFile(const string &name = "foo") {
        ofstream outputFile(name, ios::binary | ios::out);
        if (!outputFile.is_open()) {
            return 1;
        }
        ostream_iterator<char> outputIter(outputFile, "");
        copy(bytes.begin(), bytes.end(), outputIter);
        outputFile.close();
        if (outputFile.is_open()) {
            return 1;
        }
        return 0;
    }

};

#endif //FILETOVECCLASS_FILEVEC_H
