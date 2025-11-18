#include "scorecard_highlights.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void saveScorecard(const Innings &inn1, const Innings &inn2, const Match &m, int matchNumber) {
     ofstream file("matchhighlights.txt", ios::app);
    if (!file.is_open()) return;
    file << "\n\n===== MATCH " << matchNumber << " SCORECARD =====\n\n";
    file << "Match: " << m.team1 << " vs " << m.team2 << "\n\n";
    file << "--- Innings 1 (" << m.team1 << ") ---\n";
    file << "Total: " << inn1.totalRuns << "/" << inn1.wicketsLost << " in " << inn1.totalBalls / 6 << "." << inn1.totalBalls % 6 << " overs\n\n";
    file << "Ball-by-ball:\n";
    for (int i = 0; i < inn1.totalBalls && i < 300; ++i) {
        file << "Ball " << inn1.deliveries[i].ballNumber << ": Runs=" << inn1.deliveries[i].runs
             << (inn1.deliveries[i].isWicket ? " [WICKET]" : "") << " Bowler=" << inn1.deliveries[i].bowlerName << "\n";
    }
    file << "\n--- Innings 2 (" << m.team2 << ") ---\n";
    file << "Total: " << inn2.totalRuns << "/" << inn2.wicketsLost << " in " << inn2.totalBalls / 6 << "." << inn2.totalBalls % 6 << " overs\n\n";
    file << "Ball-by-ball:\n";
    for (int i = 0; i < inn2.totalBalls && i < 300; ++i) {
        file << "Ball " << inn2.deliveries[i].ballNumber << ": Runs=" << inn2.deliveries[i].runs
             << (inn2.deliveries[i].isWicket ? " [WICKET]" : "") << " Bowler=" << inn2.deliveries[i].bowlerName << "\n";
    }
    file << "==============================================\n";
    file.close();
    cout << "\nScorecard Saved!\n";
}

void saveHighlights(int matchNumber, string events[], int eventCount) {
    ofstream out("matchhighlights.txt", ios::app);
    out << "\n\n===== MATCH " << matchNumber << " HIGHLIGHTS =====\n";
    for (int i = 0; i < eventCount; i++) out << events[i] << "\n";
    out << "==============================================\n";
    out.close();
}

void viewHighlights(int matchNumber) {
   ifstream in("matchhighlights.txt");
    if (!in) { cout << "\nNo highlight file found!\n"; return; }
    string line;
    bool show = false;
    bool found = false;
    printColoredHeader("HIGHLIGHTS FOR MATCH " + to_string(matchNumber), 13);
    while (getline(in, line)) {
        if (line.find("MATCH " + to_string(matchNumber)) != string::npos && line.find("HIGHLIGHTS") != string::npos) {
            show = true; found = true; cout << line << "\n"; continue;
        }
        if (show && line.find("MATCH") != string::npos && line.find("HIGHLIGHTS") != string::npos && line.find("MATCH " + to_string(matchNumber)) == string::npos) break;
        if (show) cout << line << "\n";
    }
    if (!found) cout << "No highlights found for Match " << matchNumber << "!\n";
}

