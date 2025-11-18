#pragma once
#include <string>
#include <vector>
#include "structs.h"

using namespace std;

void createTeamsFile();
void loadTeams(Team teams[], int &teamCount);
void displayAllTeams(const Team teams[], int teamCount);
void displayTeamDetails(const Team teams[], int teamCount);
void displayAllPlayersStats();
Team selectTeam(const Team teams[], int teamCount, const string &prompt);