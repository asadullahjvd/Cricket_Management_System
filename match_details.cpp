#include "match_details.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <cstdlib>

using namespace std;

void inputVenue(Venue &v) {
    while (true) {
        cout << "Enter Stadium Name: ";
        getline(cin, v.stadiumName);
        if (v.stadiumName.empty() || isOnlySpaces(v.stadiumName) || hasDigit(v.stadiumName)) {
            cout << "Invalid stadium name!\n";
            continue;
        }
        break;
    }
    
    while (true) {
        cout << "Enter City: ";
        getline(cin, v.city);
        if (v.city.empty() || isOnlySpaces(v.city) || hasDigit(v.city)) {
            cout << "Invalid city!\n";
            continue;
        }
        break;
    }
    while (true) {
        cout << "Enter Country: ";
        getline(cin, v.country);
        if (v.country.empty() || isOnlySpaces(v.country) || hasDigit(v.country)) {
            cout << "Invalid country!\n";
            continue;
        }
        break;
    }
    while (true) {
        cout << "Enter Capacity: ";
        cin >> v.capacity;
        if (cin.fail() || v.capacity <= 0 || v.capacity > 132000) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Capacity must be 1-132000!\n";
            continue;
        }
        cin.ignore(1000, '\n');
        break;
    }
}

void displayVenue(const Venue &v) {
    printColoredSubHeader("Venue Details", 11);
    cout << "Stadium: " << v.stadiumName << endl;
    cout << "City: " << v.city << endl;
    cout << "Country: " << v.country << endl;
    cout << "Capacity: " << v.capacity << endl;
}

void inputMatch(Match &m, const Team &t1, const Team &t2) {
    m.team1 = t1.teamName;
    m.team2 = t2.teamName;
    string oversInput;
    while (true) {
        cout << "Enter Total Overs (1-50): ";
        getline(cin, oversInput);
        if (oversInput.empty() || oversInput[0] == '-' || !isNumber(oversInput)) {
            cout << "Invalid overs!\n";
            continue;
        }
        m.match_overs = stoi(oversInput);
        if (m.match_overs < 1 || m.match_overs > 50) {
            cout << "Overs must be 1-50!\n";
            continue;
        }
        break;
    }
}

void displayMatch(const Match &m) {
    printColoredSubHeader("Match Details", 11);
    cout << "Team 1: " << m.team1 << endl;
    cout << "Team 2: " << m.team2 << endl;
    cout << "Total Overs: " << m.match_overs << endl;
    cout << "Toss Winner: " << (m.toss ? m.team1 : m.team2) << endl;
}

void displayTeam(const Team &T) {
    printColoredHeader(T.teamName + " SQUAD", 13);
    cout << "Captain: " << T.captain << endl;
    for (int i = 0; i < T.n_players; i++) {
        cout << i + 1 << ". " << T.players[i] << " (" << T.roles[i] << ")" << endl;
    }
}
