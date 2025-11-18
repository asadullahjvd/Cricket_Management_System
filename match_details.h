#pragma once
#include <string>
#include "structs.h"

using namespace std;

void inputVenue(Venue &v);
void displayVenue(const Venue &v);
void inputMatch(Match &m, const Team &t1, const Team &t2);
void displayMatch(const Match &m);
void displayTeam(const Team &T);
