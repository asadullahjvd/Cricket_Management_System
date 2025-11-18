#include "play_match.h"
#include "structs.h"

#include "main.h"           
#include "match_details.h"    
#include "teams.h"   
#include "match_number.h"
#include "innings.h"   
#include "scorecard_highlights.h"
#include"result_summary.h"
#include <iostream>


using namespace std;

void playMatch(Team teams[], int teamCount) {
     Venue v;
    Match m;
    string highlights[2000];
    int hIndex = 0;
    cin.ignore(1000, '\n');
    inputVenue(v); 
    printColoredHeader("SELECT TEAMS FOR MATCH", 13); 
    displayAllTeams(teams, teamCount); 
    Team team1 = selectTeam(teams, teamCount, "Select Team 1 (enter number): "); 
    Team team2 = selectTeam(teams, teamCount, "Select Team 2 (enter number): "); 
    while (team1.teamName == team2.teamName) {
        cout << "Please select two different teams!\n";
        team2 = selectTeam(teams, teamCount, "Select Team 2 (enter number): "); 
    }
    printColoredHeader("ENTER MATCH DETAILS", 13); 
    inputMatch(m, team1, team2); 
    initializeBowlers(team1, team2); 
    initializeMatchPerformances(team1, team2); 
    printColoredHeader("DISPLAYING ALL DETAILS", 13); 
    displayVenue(v); 
    showOfficials(); 
    showSponsors(); 
    displayMatch(m); 
    displayTeam(team1); 
    displayTeam(team2); 
    printColoredHeader("MATCH STARTED", 10); 
    string battingFirst, battingSecond;
    if (m.toss) { battingFirst = m.team1; battingSecond = m.team2; } else { battingFirst = m.team2; battingSecond = m.team1; }
    highlights[hIndex++] = "Toss won by: " + battingFirst;
    highlights[hIndex++] = "Batting first: " + battingFirst;
    highlights[hIndex++] = "Bowling first: " + battingSecond;
    Innings innings1, innings2;
    int choice;
    cout << "\nSelect scoring mode for first innings:\n1. Automatic\n2. Manual\n";
    while (true) {
        cout << "Enter choice: ";
        if (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cin.clear(); cin.ignore(1000, '\n'); cout << "Enter 1 or 2 only.\n"; continue;
        } break;
    }
    if (battingFirst == m.team1) {
        if (choice == 1) playInningsAuto(innings1, battingFirst, m.match_overs, team1.players, team1.n_players, m, highlights, hIndex, 0); 
        else playInningsManual(innings1, battingFirst, m.match_overs, team1.players, team1.n_players, m, highlights, hIndex, 0); 
    } else {
        if (choice == 1) playInningsAuto(innings1, battingFirst, m.match_overs, team2.players, team2.n_players, m, highlights, hIndex, 0); 
        else playInningsManual(innings1, battingFirst, m.match_overs, team2.players, team2.n_players, m, highlights, hIndex, 0); 
    }
    highlights[hIndex++] = battingFirst + " scored " + to_string(innings1.totalRuns) + "/" + to_string(innings1.wicketsLost);
    int target = innings1.totalRuns + 1;
    cout << "\nTarget for " << battingSecond << " is " << target << endl;
    int choice2;
    cout << "\nSelect scoring mode for second innings:\n1. Automatic\n2. Manual\n";
    while (true) {
        cout << "Enter choice: ";
        if (!(cin >> choice2) || (choice2 != 1 && choice2 != 2)) {
            cin.clear(); clearLine(); cout << "Enter 1 or 2 only.\n"; continue;
        } clearLine(); break;
    }
    if (battingSecond == m.team1) {
        if (choice2 == 1) playInningsAuto(innings2, battingSecond, m.match_overs, team1.players, team1.n_players, m, highlights, hIndex, target); 
        else playInningsManual(innings2, battingSecond, m.match_overs, team1.players, team1.n_players, m, highlights, hIndex, target); 
    } else {
        if (choice2 == 1) playInningsAuto(innings2, battingSecond, m.match_overs, team2.players, team2.n_players, m, highlights, hIndex, target); 
        else playInningsManual(innings2, battingSecond, m.match_overs, team2.players, team2.n_players, m, highlights, hIndex, target); 
    }
    highlights[hIndex++] = battingSecond + " scored " + to_string(innings2.totalRuns) + "/" + to_string(innings2.wicketsLost);
    showResult(innings1, innings2, battingFirst, battingSecond); 
    if (innings1.totalRuns > innings2.totalRuns) highlights[hIndex++] = battingFirst + " WON the match";
    else if (innings2.totalRuns > innings1.totalRuns) highlights[hIndex++] = battingSecond + " WON the match";
    else highlights[hIndex++] = "Match TIED.";
    displayMatchPerformances(m); 
    updateCareerRecords(); 
    int matchNumber;
    while (true) {
        cout << "Enter Match Number: ";
        if (!(cin >> matchNumber) || matchNumber <= 0) {
            cin.clear(); cin.ignore(1000, '\n'); cout << "Match number must be positive.\n"; continue;
        }
        if (!isMatchNumberUnique(matchNumber)) { 
            cout << "Match number " << matchNumber << " already exists!\n"; continue;
        } break;
    }
    saveMatchNumber(matchNumber); 
    saveHighlights(matchNumber, highlights, hIndex); 
    saveScorecard(innings1, innings2, m, matchNumber); 
    cout << "Highlights and Scorecard saved!\n";
    displayFinalSummary(innings1, innings2, m, v); 
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}