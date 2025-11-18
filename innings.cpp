#include "innings.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
void ballCommentary(string batsmanName, string input) {
    string validInputs[] = {"0", "1", "2", "3", "4", "6", "W", "w"};
    string messages[] = {"didn't score. Dot ball!", "takes a single.", "scores two runs.", "scores three runs!", "hits a FOUR! Brilliant shot!", "hits a SIX! What a shot!", "is OUT!", "is OUT!"};
    for (int i = 0; i < 8; i++) {
        if (input == validInputs[i]) {
            cout << batsmanName << " " << messages[i] << endl;
            return;
        }
    }
    cout << batsmanName << " scores " << input << " runs." << endl;
}

void playInningsAuto(Innings &inn, string battingTeam, int overs, string* batsmen, int n_players, const Match &m, string highlights[], int &hIndex, int target) {
   inn.overLimit = overs;
    int maxBalls = overs * 6;
    printColoredHeader(battingTeam + " is batting (AUTOMATIC MODE)", 10);
    if (target > 0) cout << "Target: " << target << " runs\n";
    int strikerIndex = 0;
    int nonStrikerIndex = 1;
    int nextBatterIndex = 2;
    for (int over = 0; over < overs; over++) {
        if (inn.wicketsLost >= n_players - 1) break;
        if (inn.totalBalls >= maxBalls) break;
        if (target > 0 && inn.totalRuns >= target) break;
        cout << "\nOver " << over + 1 << " begins.\n";
        string bowlerName = "Unknown";
        if (battingTeam == m.team1) {
            if (bowlersCount2 > 0) bowlerName = bowlersTeam2[rand() % bowlersCount2];
        } else {
            if (bowlersCount1 > 0) bowlerName = bowlersTeam1[rand() % bowlersCount1];
        }
        cout << "Bowling by: " << bowlerName << endl;
        for (int ballInOver = 0; ballInOver < 6; ballInOver++) {
            if (inn.wicketsLost >= n_players - 1) break;
            if (inn.totalBalls >= maxBalls) break;
            if (target > 0 && inn.totalRuns >= target) break;
            int idx = inn.totalBalls;
            inn.deliveries[idx].ballNumber = idx + 1;
            int x = rand() % 100;
            string outcome;
            if (x < 40) outcome = "0"; else if (x < 65) outcome = "1"; else if (x < 80) outcome = "2"; else if (x < 85) outcome = "3"; else if (x < 95) outcome = "4"; else if (x < 98) outcome = "6"; else outcome = "W";
            cout << "Ball " << (ballInOver + 1) << ": " << batsmen[strikerIndex] << " -> " << outcome << "\n";
            if (outcome == "W") {
                inn.deliveries[idx].runs = 0; inn.deliveries[idx].isWicket = 1; inn.deliveries[idx].bowlerName = bowlerName; 
                inn.wicketsLost++;
                cout << batsmen[strikerIndex] << " is OUT! Bowler: " << bowlerName << endl;
                ballCommentary(batsmen[strikerIndex], "W");
                updateBatsmanPerformance(batsmen[strikerIndex], 0, true);
                updateBowlerPerformance(bowlerName, 0, true);
                if (nextBatterIndex < n_players) strikerIndex = nextBatterIndex++;
                else { cout << battingTeam << " All Out!\n"; inn.totalBalls++; break; }
            } else {
                int runs = stoi(outcome);
                inn.deliveries[idx].runs = runs; inn.deliveries[idx].isWicket = 0; inn.deliveries[idx].bowlerName = bowlerName; 
                inn.totalRuns += runs;
                ballCommentary(batsmen[strikerIndex], outcome);
                updateBatsmanPerformance(batsmen[strikerIndex], runs, false);
                updateBowlerPerformance(bowlerName, runs, false);
                if (runs % 2 == 1) swap(strikerIndex, nonStrikerIndex);
            }
            inn.totalBalls++;
            if (target > 0 && inn.totalRuns >= target) { cout << "Target achieved! " << battingTeam << " wins!\n"; break; }
        }
        if (inn.wicketsLost >= n_players - 1) break;
        if (inn.totalBalls >= maxBalls) break;
        if (target > 0 && inn.totalRuns >= target) break;
        swap(strikerIndex, nonStrikerIndex);
        cout << "End of over " << over + 1 << ". Score: " << inn.totalRuns << "/" << inn.wicketsLost << " in " << inn.totalBalls / 6 << "." << inn.totalBalls % 6 << " overs\n";
    }
    printColoredSubHeader("End of Innings", 11);
    cout << battingTeam << " scored " << inn.totalRuns << "/" << inn.wicketsLost << "\n";
}

void playInningsManual(Innings &inn, string battingTeam, int overs, string* batsmen, int n_players, const Match &m, string highlights[], int &hIndex, int target) {
    inn.overLimit = overs;
    int maxBalls = overs * 6;
    printColoredHeader(battingTeam + " is batting (MANUAL MODE)", 10);
    if (target > 0) cout << "Target: " << target << " runs\n";
    int strikerIndex = 0;
    int nonStrikerIndex = 1;
    int nextBatterIndex = 2;
    for (int over = 0; over < overs; over++) {
        if (inn.wicketsLost >= n_players - 1) break;
        if (inn.totalBalls >= maxBalls) break;
        if (target > 0 && inn.totalRuns >= target) break;
        cout << "\nOver " << over + 1 << " begins.\n";
        string bowlerName = "Unknown";
        if (battingTeam == m.team1) {
            if (bowlersCount2 > 0) bowlerName = bowlersTeam2[rand() % bowlersCount2];
        } else {
            if (bowlersCount1 > 0) bowlerName = bowlersTeam1[rand() % bowlersCount1];
        }
        cout << "Bowling by: " << bowlerName << endl;
        for (int ballInOver = 0; ballInOver < 6; ballInOver++) {
            if (inn.wicketsLost >= n_players - 1) break;
            if (inn.totalBalls >= maxBalls) break;
            if (target > 0 && inn.totalRuns >= target) break;
            int idx = inn.totalBalls;
            inn.deliveries[idx].ballNumber = idx + 1;
            string userOutcome;
            while (true) {
                cout << "Enter outcome for ball " << (ballInOver + 1) << " (0,1,2,3,4,6) for " << batsmen[strikerIndex] << ": ";
                cin >> userOutcome;
                if (userOutcome == "0" || userOutcome == "1" || userOutcome == "2" || userOutcome == "3" || userOutcome == "4" || userOutcome == "6") break;
                cout << "Invalid input! Please enter only 0,1,2,3,4,6.\n";
            }
            string randomOutcome;
            if (userOutcome == "W") {
                string outcomes[] = {"0", "1", "2", "3", "4", "6"};
                randomOutcome = outcomes[rand() % 6];
            } else {
                int userRuns = stoi(userOutcome);
                string possibleOutcomes[7];
                int count = 0;
                string outcomes[] = {"0", "1", "2", "3", "4", "6", "W"};
                for (int i = 0; i < 7; i++) {
                    if (outcomes[i] == "W") possibleOutcomes[count++] = outcomes[i];
                    else if (stoi(outcomes[i]) <= userRuns) possibleOutcomes[count++] = outcomes[i];
                }
                randomOutcome = possibleOutcomes[rand() % count];
            }
            string finalOutcome = (rand() % 2 == 0) ? userOutcome : randomOutcome;
            cout << "Ball " << (ballInOver + 1) << ": " << batsmen[strikerIndex] << " -> " << finalOutcome << "\n";
            if (finalOutcome == "W") {
                inn.deliveries[idx].runs = 0; inn.deliveries[idx].isWicket = 1; inn.deliveries[idx].bowlerName = bowlerName; 
                inn.wicketsLost++;
                cout << batsmen[strikerIndex] << " is OUT! Bowler: " << bowlerName << endl;
                ballCommentary(batsmen[strikerIndex], "W");
                updateBatsmanPerformance(batsmen[strikerIndex], 0, true);
                updateBowlerPerformance(bowlerName, 0, true);
                if (nextBatterIndex < n_players) strikerIndex = nextBatterIndex++;
                else { cout << battingTeam << " All Out!\n"; inn.totalBalls++; break; }
            } else {
                int runs = stoi(finalOutcome);
                inn.deliveries[idx].runs = runs; inn.deliveries[idx].isWicket = 0; inn.deliveries[idx].bowlerName = bowlerName; 
                inn.totalRuns += runs;
                ballCommentary(batsmen[strikerIndex], finalOutcome);
                updateBatsmanPerformance(batsmen[strikerIndex], runs, false);
                updateBowlerPerformance(bowlerName, runs, false);
                if (runs % 2 == 1) swap(strikerIndex, nonStrikerIndex);
            }
            inn.totalBalls++;
            if (target > 0 && inn.totalRuns >= target) { cout << "Target achieved! " << battingTeam << " wins!\n"; break; }
        }
        if (inn.wicketsLost >= n_players - 1) break;
        if (inn.totalBalls >= maxBalls) break;
        if (target > 0 && inn.totalRuns >= target) break;
        swap(strikerIndex, nonStrikerIndex);
        cout << "End of over " << over + 1 << ". Score: " << inn.totalRuns << "/" << inn.wicketsLost << " in " << inn.totalBalls / 6 << "." << inn.totalBalls % 6 << " overs\n";
    }
    printColoredSubHeader("End of Innings", 11);
    cout << battingTeam << " scored " << inn.totalRuns << "/" << inn.wicketsLost << "\n";
}