#pragma once
#include <string>
#include "structs.h"

using namespace std;

void setColor(int color);
void printColoredHeader(const string& text, int color = 13);
void printColoredSubHeader(const string& text, int color = 11);
void printColoredBorder(int color = 13);
void clearLine();

bool hasDigit(const string &s);
bool isOnlySpaces(const string &s);
bool isNumber(const string &s);

void createPlayerDatabase();
void loadPlayerDatabase();
void updateCareerRecords();
void initializeMatchPerformances(const Team &team1, const Team &team2);
void updateBatsmanPerformance(const string &batsmanName, int runs, bool isWicket);
void updateBowlerPerformance(const string &bowlerName, int runs, bool isWicket);
void displayMatchPerformances(const Match &m);

void initializeBowlers(const Team &team1, const Team &team2);

void showOfficials();
void showSponsors();

void showMainMenu();
