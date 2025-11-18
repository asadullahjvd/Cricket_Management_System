#include "match_number.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void loadExistingMatchNumbers() {
     ifstream file("matchhighlights.txt");
    if (!file) return;
    string line;
    usedMatchCount = 0;
    while (getline(file, line) && usedMatchCount < 1000) {
        if (line.find("MATCH ") != string::npos && line.find("HIGHLIGHTS") != string::npos) {
            size_t matchPos = line.find("MATCH ");
            if (matchPos != string::npos) {
                size_t numStart = matchPos + 6;
                size_t numEnd = line.find(" ", numStart);
                if (numEnd == string::npos) numEnd = line.find("=", numStart);
                if (numEnd != string::npos) {
                    string numStr = line.substr(numStart, numEnd - numStart);
                    try { usedMatchNumbers[usedMatchCount++] = stoi(numStr); } catch (...) {}
                }
            }
        }
    }
    file.close();
}

bool isMatchNumberUnique(int matchNumber) {
    for (int i = 0; i < usedMatchCount; i++) {
        if (usedMatchNumbers[i] == matchNumber) return false;
    }
    return true;
}

void saveMatchNumber(int matchNumber) {
    if (usedMatchCount < 1000) {
        usedMatchNumbers[usedMatchCount++] = matchNumber;
    }
}