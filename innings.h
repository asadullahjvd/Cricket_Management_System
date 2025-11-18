#pragma once
#include <string>
#include "structs.h"

using namespace std;
void ballCommentary(string batsmanName, string input);
void playInningsAuto(Innings &inn, string battingTeam, int overs, string* batsmen, int n_players, const Match &m, string highlights[], int &hIndex, int target = 0);
void playInningsManual(Innings &inn, string battingTeam, int overs, string* batsmen, int n_players, const Match &m, string highlights[], int &hIndex, int target = 0);