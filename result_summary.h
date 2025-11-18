#pragma once
#include <string>
#include "structs.h"

using namespace std;

void showResult(Innings &inn1, Innings &inn2, string teamBat1, string teamBat2);
void displayFinalSummary(const Innings &inn1, const Innings &inn2, const Match &m, const Venue &v);