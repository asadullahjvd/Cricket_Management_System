#pragma once
#include <string>
#include "structs.h"

using namespace std;

void saveScorecard(const Innings &inn1, const Innings &inn2, const Match &m, int matchNumber);
void saveHighlights(int matchNumber, string events[], int eventCount);
void viewHighlights(int matchNumber);