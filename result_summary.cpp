#include "result_summary.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <string>

using namespace std;

void showResult(Innings &inn1, Innings &inn2, string teamBat1, string teamBat2) {
  printColoredHeader("MATCH RESULT", 12);
    cout << teamBat1 << ": " << inn1.totalRuns << "/" << inn1.wicketsLost << endl;
    cout << teamBat2 << ": " << inn2.totalRuns << "/" << inn2.wicketsLost << endl;
    if (inn2.totalRuns > inn1.totalRuns) { cout << teamBat2 << " WON by " << (10 - inn2.wicketsLost) << " wickets!\n"; } 
    else if (inn1.totalRuns > inn2.totalRuns) { cout << teamBat1 << " WON by " << (inn1.totalRuns - inn2.totalRuns) << " runs!\n"; } 
    else { cout << "MATCH TIED!\n"; }
    string players[300]; int runs[300]; int wkts[300]; int count = 0;
     for (int i = 0; i < inn1.totalBalls; i++) {
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (players[j] == inn1.deliveries[i].bowlerName) { runs[j] += inn1.deliveries[i].runs; if (inn1.deliveries[i].isWicket == 1) wkts[j]++; found = true; break; }
        }
        if (!found) { players[count] = inn1.deliveries[i].bowlerName; runs[count] = inn1.deliveries[i].runs; wkts[count] = inn1.deliveries[i].isWicket; count++; }
    }
    for (int i = 0; i < inn2.totalBalls; i++) {
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (players[j] == inn2.deliveries[i].bowlerName) { runs[j] += inn2.deliveries[i].runs; if (inn2.deliveries[i].isWicket == 1) wkts[j]++; found = true; break; }
        }
        if (!found) { players[count] = inn2.deliveries[i].bowlerName; runs[count] = inn2.deliveries[i].runs; wkts[count] = inn2.deliveries[i].isWicket; count++; }
    }
    string bestPlayer = ""; int maxRuns = 0, maxWkts = 0;
    for (int i = 0; i < count; i++) {
        if (wkts[i] > maxWkts || (wkts[i] == maxWkts && runs[i] > maxRuns)) { maxWkts = wkts[i]; maxRuns = runs[i]; bestPlayer = players[i]; }
    }
    cout << "Player of the Match: " << bestPlayer << " (Runs: " << maxRuns << ", Wickets: " << maxWkts << ")\n";
}

void displayFinalSummary(const Innings &inn1, const Innings &inn2, const Match &m, const Venue &v) {
    printColoredHeader("FINAL MATCH SUMMARY", 13);
    cout << "Venue: " << v.stadiumName << ", " << v.city << ", " << v.country << endl;
    cout << "Match: " << m.team1 << " vs " << m.team2 << endl;
    cout << "Overs: " << m.match_overs << endl;
    printColoredSubHeader("SCORECARD", 11);
    cout << m.team1 << ": " << inn1.totalRuns << "/" << inn1.wicketsLost << " in " << inn1.totalBalls / 6 << "." << inn1.totalBalls % 6 << " overs\n";
    cout << m.team2 << ": " << inn2.totalRuns << "/" << inn2.wicketsLost << " in " << inn2.totalBalls / 6 << "." << inn2.totalBalls % 6 << " overs\n";
    
    if (inn1.totalRuns > inn2.totalRuns) { cout << "\nRESULT: " << m.team1 << " WON by " << (inn1.totalRuns - inn2.totalRuns) << " runs!\n"; } 
    else if (inn2.totalRuns > inn1.totalRuns) { cout << "\nRESULT: " << m.team2 << " WON by " << (10 - inn2.wicketsLost) << " wickets!\n"; } 
    else { cout << "\nRESULT: MATCH TIED!\n"; }
}