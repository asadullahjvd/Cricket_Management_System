#pragma once
#include <string>

using namespace std;

struct Venue{
    string stadiumName;
    string city;
    string country;
    int capacity;
};

struct Match{
    string team1;
    string team2;
    bool toss;
    int match_overs;
};

struct Team {
    string teamName;
    int n_players;
    string *players;
    string *roles;
    string captain;
};

struct PlayerRecord {
    string name;
    int age;
    string role;
    int matches;
    int runs;
    int wickets;
    string team;
};

struct PlayerPerformance {
    string playerName;
    int runsScored;
    int wicketsTaken;
    int ballsFaced;
    int ballsBowled;
    bool playedInMatch;
};

struct ball{
    int ballNumber;
    int runs;
    int isWicket;
    string bowlerName;   
};

struct Innings {
    int totalRuns = 0;
    int wicketsLost = 0;
    int totalBalls = 0;
    int overLimit;
    ball deliveries[300];
};

extern string bowlersTeam1[15];
extern string bowlersTeam2[15];
extern int bowlersCount1;
extern int bowlersCount2;

extern PlayerPerformance matchPerformances[22];
extern int performancesCount;

extern PlayerRecord allPlayers[110];
extern int totalPlayers;

extern int usedMatchNumbers[1000];
extern int usedMatchCount;