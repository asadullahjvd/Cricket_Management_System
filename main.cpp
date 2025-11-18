#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>


#include "structs.h"
#include "main.h" 
#include "teams.h" 
#include "play_match.h" 
#include "scorecard_highlights.h" 
#include "match_number.h"
using namespace std;

string bowlersTeam1[15];
string bowlersTeam2[15];
int bowlersCount1 = 0;
int bowlersCount2 = 0;

PlayerPerformance matchPerformances[22];
int performancesCount = 0;

PlayerRecord allPlayers[110];
int totalPlayers = 0;

int usedMatchNumbers[1000];
int usedMatchCount = 0;


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printColoredHeader(const string& text, int color) {
    setColor(color);
    cout << "\n" << string(50, '=') << "\n";
    cout << "     " << text << "\n";
    cout << string(50, '=') << "\n";
    setColor(7); 
}

void printColoredSubHeader(const string& text, int color) {
    setColor(color);
    cout << "\n--- " << text << " ---\n";
    setColor(7);
}

void printColoredBorder(int color) {
    setColor(color);
    cout << string(50, '=') << "\n";
    setColor(7);
}

void clearLine() {
    cin.clear();
    cin.ignore(1000, '\n');
}
bool hasDigit(const string &s) {
    for (char c : s) if (isdigit(c)) return true;
    return false;
}

bool isOnlySpaces(const string &s) {
    for (char c : s) if (!isspace(c)) return false;
    return true;
}

bool isNumber(const string &s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) if (!isdigit(s[i])) return false;
    return true;
}
void createPlayerDatabase() {
    
    ofstream file("players_db.txt");
    if (!file) { cout << "Error creating player database!" << endl; return; }
   // ====================== INDIA ======================
    file << "Rohit Sharma|36|Batsman|248|10709|8|India\n";
    file << "Virat Kohli|35|Batsman|292|13848|4|India\n";
    file << "KL Rahul|31|Batsman|72|2781|0|India\n";
    file << "Shreyas Iyer|29|Batsman|55|1841|0|India\n";
    file << "Rishabh Pant|26|Keeper|54|1628|0|India\n";
    file << "Hardik Pandya|30|Allrounder|87|1758|85|India\n";
    file << "Ravindra Jadeja|35|Allrounder|197|2758|220|India\n";
    file << "Jasprit Bumrah|30|Bowler|89|86|149|India\n";
    file << "Mohammed Shami|33|Bowler|101|229|195|India\n";
    file << "Kuldeep Yadav|29|Bowler|95|259|167|India\n";
    file << "Mohammed Siraj|29|Bowler|43|55|78|India\n";

    // ====================== AUSTRALIA ======================
    file << "Pat Cummins|30|Bowler|88|592|141|Australia\n";
    file << "Steve Smith|34|Batsman|155|5674|19|Australia\n";
    file << "David Warner|37|Batsman|161|6932|1|Australia\n";
    file << "Marnus Labuschagne|29|Batsman|44|2224|2|Australia\n";
    file << "Glenn Maxwell|35|Allrounder|136|3890|75|Australia\n";
    file << "Mitchell Marsh|32|Allrounder|89|2213|59|Australia\n";
    file << "Alex Carey|32|Keeper|67|1325|0|Australia\n";
    file << "Mitchell Starc|34|Bowler|121|675|236|Australia\n";
    file << "Josh Hazlewood|33|Bowler|85|249|138|Australia\n";
    file << "Adam Zampa|32|Bowler|89|159|146|Australia\n";
    file << "Travis Head|30|Batsman|67|2401|16|Australia\n";

    // ====================== ENGLAND ======================
    file << "Jos Buttler|33|Keeper|187|5527|0|England\n";
    file << "Jonny Bairstow|34|Batsman|118|4298|0|England\n";
    file << "Joe Root|33|Batsman|172|9274|19|England\n";
    file << "Ben Stokes|32|Allrounder|114|3985|93|England\n";
    file << "Liam Livingstone|30|Allrounder|45|894|32|England\n";
    file << "Moeen Ali|36|Allrounder|146|2314|127|England\n";
    file << "Sam Curran|25|Allrounder|43|556|58|England\n";
    file << "Chris Woakes|35|Bowler|122|1448|175|England\n";
    file << "Mark Wood|34|Bowler|73|271|98|England\n";
    file << "Adil Rashid|35|Bowler|141|761|196|England\n";
    file << "Jofra Archer|29|Bowler|21|66|42|England\n";

    // ====================== PAKISTAN ======================
    file << "Babar Azam|29|Batsman|117|5729|0|Pakistan\n";
    file << "Mohammad Rizwan|31|Keeper|85|2797|0|Pakistan\n";
    file << "Fakhar Zaman|34|Batsman|85|3365|0|Pakistan\n";
    file << "Imam-ul-Haq|28|Batsman|72|2873|0|Pakistan\n";
    file << "Shadab Khan|25|Allrounder|92|812|98|Pakistan\n";
    file << "Mohammad Nawaz|29|Allrounder|62|628|69|Pakistan\n";
    file << "Haris Rauf|30|Bowler|45|78|83|Pakistan\n";
    file << "Shaheen Afridi|24|Bowler|52|128|104|Pakistan\n";
    file << "Naseem Shah|21|Bowler|17|25|32|Pakistan\n";
    file << "Hasan Ali|29|Bowler|70|329|96|Pakistan\n";
    file << "Iftikhar Ahmed|33|Allrounder|45|806|8|Pakistan\n";

    // ====================== NEW ZEALAND ======================
    file << "Kane Williamson|33|Batsman|169|7022|43|New Zealand\n";
    file << "Trent Boult|34|Bowler|114|259|211|New Zealand\n";
    file << "Tim Southee|35|Bowler|170|874|221|New Zealand\n";
    file << "Devon Conway|32|Batsman|32|1392|0|New Zealand\n";
    file << "Daryl Mitchell|32|Allrounder|41|1318|11|New Zealand\n";
    file << "Glenn Phillips|27|Batsman|41|1042|6|New Zealand\n";
    file << "Mitchell Santner|32|Allrounder|109|1021|109|New Zealand\n";
    file << "Ish Sodhi|31|Bowler|96|289|129|New Zealand\n";
    file << "Lockie Ferguson|32|Bowler|45|65|66|New Zealand\n";
    file << "Tom Latham|31|Keeper|148|4430|0|New Zealand\n";
    file << "James Neesham|33|Allrounder|82|1287|72|New Zealand\n";

    // ====================== SOUTH AFRICA ======================
    file << "Temba Bavuma|33|Batsman|38|1678|0|South Africa\n";
    file << "Quinton de Kock|31|Keeper|155|6770|0|South Africa\n";
    file << "Aiden Markram|29|Batsman|68|2410|12|South Africa\n";
    file << "David Miller|35|Batsman|172|4495|0|South Africa\n";
    file << "Heinrich Klaasen|32|Keeper|47|1574|0|South Africa\n";
    file << "Marco Jansen|24|Allrounder|25|324|38|South Africa\n";
    file << "Kagiso Rabada|28|Bowler|106|538|157|South Africa\n";
    file << "Lungi Ngidi|27|Bowler|53|103|86|South Africa\n";
    file << "Anrich Nortje|30|Bowler|25|62|48|South Africa\n";
    file << "Tabraiz Shamsi|33|Bowler|75|96|98|South Africa\n";
    file << "Keshav Maharaj|34|Bowler|49|258|62|South Africa\n";

    // ====================== SRI LANKA ======================
    file << "Dasun Shanaka|32|Allrounder|66|1512|27|Sri Lanka\n";
    file << "Pathum Nissanka|25|Batsman|39|1456|0|Sri Lanka\n";
    file << "Kusal Mendis|29|Keeper|134|3985|0|Sri Lanka\n";
    file << "Charith Asalanka|26|Batsman|44|1428|6|Sri Lanka\n";
    file << "Wanindu Hasaranga|26|Allrounder|58|892|91|Sri Lanka\n";
    file << "Dhananjaya de Silva|32|Allrounder|101|2095|44|Sri Lanka\n";
    file << "Maheesh Theekshana|23|Bowler|42|65|55|Sri Lanka\n";
    file << "Dushmantha Chameera|32|Bowler|54|98|68|Sri Lanka\n";
    file << "Lahiru Kumara|27|Bowler|35|42|41|Sri Lanka\n";
    file << "Kasun Rajitha|30|Bowler|32|47|38|Sri Lanka\n";
    file << "Angelo Mathews|36|Allrounder|248|5865|122|Sri Lanka\n";

    // ====================== WEST INDIES ======================
    file << "Nicholas Pooran|28|Keeper|71|2091|0|West Indies\n";
    file << "Shai Hope|30|Keeper|127|5266|0|West Indies\n";
    file << "Brandon King|29|Batsman|42|1289|0|West Indies\n";
    file << "Shimron Hetmyer|27|Batsman|67|1797|0|West Indies\n";
    file << "Jason Holder|32|Allrounder|154|2809|163|West Indies\n";
    file << "Rovman Powell|30|Batsman|52|1148|6|West Indies\n";
    file << "Alzarri Joseph|27|Bowler|47|102|73|West Indies\n";
    file << "Akeal Hosein|30|Bowler|35|156|35|West Indies\n";
    file << "Gudakesh Motie|28|Bowler|12|24|16|West Indies\n";
    file << "Romario Shepherd|29|Allrounder|21|238|24|West Indies\n";
    file << "Kyle Mayers|31|Allrounder|32|761|20|West Indies\n";

    // ====================== BANGLADESH ======================
    file << "Shakib Al Hasan|36|Allrounder|247|7576|317|Bangladesh\n";
    file << "Litton Das|29|Keeper|92|2764|0|Bangladesh\n";
    file << "Najmul Hossain|24|Batsman|44|1494|0|Bangladesh\n";
    file << "Mushfiqur Rahim|36|Keeper|265|7396|2|Bangladesh\n";
    file << "Mahmudullah|38|Allrounder|228|5341|102|Bangladesh\n";
    file << "Mehidy Hasan|26|Allrounder|92|1048|87|Bangladesh\n";
    file << "Mustafizur Rahman|28|Bowler|101|156|154|Bangladesh\n";
    file << "Taskin Ahmed|29|Bowler|52|88|59|Bangladesh\n";
    file << "Shoriful Islam|22|Bowler|25|22|34|Bangladesh\n";
    file << "Hasan Mahmud|24|Bowler|15|18|16|Bangladesh\n";
    file << "Towhid Hridoy|23|Batsman|32|897|0|Bangladesh\n";

    // ====================== AFGHANISTAN ======================
    file << "Rashid Khan|25|Bowler|101|679|190|Afghanistan\n";
    file << "Mohammad Nabi|39|Allrounder|161|3345|158|Afghanistan\n";
    file << "Rahmanullah Gurbaz|22|Keeper|41|1354|0|Afghanistan\n";
    file << "Ibrahim Zadran|22|Batsman|32|1256|0|Afghanistan\n";
    file << "Rahmat Shah|30|Batsman|112|3456|12|Afghanistan\n";
    file << "Hashmatullah Shahidi|29|Batsman|78|2078|0|Afghanistan\n";
    file << "Najibullah Zadran|30|Batsman|98|2278|0|Afghanistan\n";
    file << "Mujeeb Ur Rahman|23|Bowler|84|98|106|Afghanistan\n";
    file << "Fazalhaq Farooqi|23|Bowler|28|25|38|Afghanistan\n";
    file << "Naveen-ul-Haq|24|Bowler|18|22|26|Afghanistan\n";
    file << "Azmatullah Omarzai|24|Allrounder|25|487|12|Afghanistan\n";

    file.close();
    cout << "Player database created successfully!\n";
}

void loadPlayerDatabase() {
    ifstream file("players_db.txt");
    if (!file) {
        createPlayerDatabase();
        file.open("players_db.txt");
        if (!file) return;
    }
    string line; totalPlayers = 0;
    while (getline(file, line) && totalPlayers < 110) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|'); size_t pos2 = line.find('|', pos1 + 1); size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1); size_t pos5 = line.find('|', pos4 + 1); size_t pos6 = line.find('|', pos5 + 1);
        if (pos1 != string::npos && pos6 != string::npos) {
            allPlayers[totalPlayers].name = line.substr(0, pos1);
            allPlayers[totalPlayers].age = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            allPlayers[totalPlayers].role = line.substr(pos2 + 1, pos3 - pos2 - 1);
            allPlayers[totalPlayers].matches = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
            allPlayers[totalPlayers].runs = stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));
            allPlayers[totalPlayers].wickets = stoi(line.substr(pos5 + 1, pos6 - pos5 - 1));
            allPlayers[totalPlayers].team = line.substr(pos6 + 1);
            totalPlayers++;
        }
    }
    file.close();
}

void updateCareerRecords() {
    ofstream file("players_db.txt");
    if (!file) return;
    for (int i = 0; i < totalPlayers; i++) {
        for (int j = 0; j < performancesCount; j++) {
            if (matchPerformances[j].playedInMatch && allPlayers[i].name == matchPerformances[j].playerName) {
                allPlayers[i].matches += 1;
                allPlayers[i].runs += matchPerformances[j].runsScored;
                allPlayers[i].wickets += matchPerformances[j].wicketsTaken;
                break;
            }
        }
        file << allPlayers[i].name << "|" << allPlayers[i].age << "|" << allPlayers[i].role << "|"
             << allPlayers[i].matches << "|" << allPlayers[i].runs << "|" << allPlayers[i].wickets 
             << "|" << allPlayers[i].team << "\n";
    }
    file.close();
    cout << "Player records updated!\n";
}

void initializeMatchPerformances(const Team &team1, const Team &team2) {
    performancesCount = 0;
    for (int i = 0; i < team1.n_players && performancesCount < 22; i++) {
        matchPerformances[performancesCount].playerName = team1.players[i];
        matchPerformances[performancesCount].runsScored = 0; matchPerformances[performancesCount].wicketsTaken = 0;
        matchPerformances[performancesCount].ballsFaced = 0; matchPerformances[performancesCount].ballsBowled = 0;
        matchPerformances[performancesCount].playedInMatch = false; performancesCount++;
    }
    for (int i = 0; i < team2.n_players && performancesCount < 22; i++) {
        matchPerformances[performancesCount].playerName = team2.players[i];
        matchPerformances[performancesCount].runsScored = 0; matchPerformances[performancesCount].wicketsTaken = 0;
        matchPerformances[performancesCount].ballsFaced = 0; matchPerformances[performancesCount].ballsBowled = 0;
        matchPerformances[performancesCount].playedInMatch = false; performancesCount++;
    }
}

void updateBatsmanPerformance(const string &batsmanName, int runs, bool isWicket) {
     for (int i = 0; i < performancesCount; i++) {
        if (matchPerformances[i].playerName == batsmanName) {
            matchPerformances[i].runsScored += runs;
            matchPerformances[i].ballsFaced++;
            matchPerformances[i].playedInMatch = true;
            break;
        }
    }
}

void updateBowlerPerformance(const string &bowlerName, int runs, bool isWicket) {
   for (int i = 0; i < performancesCount; i++) {
        if (matchPerformances[i].playerName == bowlerName) {
            matchPerformances[i].ballsBowled++;
            if (isWicket) matchPerformances[i].wicketsTaken++;
            matchPerformances[i].playedInMatch = true;
            break;
        }
    }
}

void displayMatchPerformances(const Match &m) {
     printColoredHeader("MATCH PERFORMANCES", 10);
    printColoredSubHeader(m.team1, 11);
    for (int i = 0; i < performancesCount; i++) {
        if (matchPerformances[i].playedInMatch) {
            cout << matchPerformances[i].playerName << ": " << matchPerformances[i].runsScored << " runs";
            if (matchPerformances[i].wicketsTaken > 0) cout << ", " << matchPerformances[i].wicketsTaken << " wickets";
            cout << " (" << matchPerformances[i].ballsFaced << " balls";
            if (matchPerformances[i].ballsBowled > 0) cout << ", " << matchPerformances[i].ballsBowled << " bowled";
            cout << ")\n";
        }
    }
    printColoredSubHeader(m.team2, 11);
    for (int i = 0; i < performancesCount; i++) {
        if (matchPerformances[i].playedInMatch) {
            cout << matchPerformances[i].playerName << ": " << matchPerformances[i].runsScored << " runs";
            if (matchPerformances[i].wicketsTaken > 0) cout << ", " << matchPerformances[i].wicketsTaken << " wickets";
            cout << " (" << matchPerformances[i].ballsFaced << " balls";
            if (matchPerformances[i].ballsBowled > 0) cout << ", " << matchPerformances[i].ballsBowled << " bowled";
            cout << ")\n";
        }
    }
}

void initializeBowlers(const Team &team1, const Team &team2) {
     bowlersCount1 = 0; bowlersCount2 = 0;
    for (int i = 0; i < team1.n_players && bowlersCount1 < 15; i++) {
        if (team1.roles[i] == "Bowler" || team1.roles[i] == "Allrounder") {
            bowlersTeam1[bowlersCount1++] = team1.players[i];
        }
    }
    if (bowlersCount1 == 0 && team1.n_players > 0) bowlersTeam1[bowlersCount1++] = team1.players[0];
    for (int i = 0; i < team2.n_players && bowlersCount2 < 15; i++) {
        if (team2.roles[i] == "Bowler" || team2.roles[i] == "Allrounder") {
            bowlersTeam2[bowlersCount2++] = team2.players[i];
        }
    }
    if (bowlersCount2 == 0 && team2.n_players > 0) bowlersTeam2[bowlersCount2++] = team2.players[0];
}
void showOfficials() {
    const char* umpires[] = {"Aleem Dar", "Richard Illingworth", "Javagal Srinath", "Rod Tucker", "Marais Erasmus", "Kumar Dharmasena", "Paul Reiffel"};
    printColoredSubHeader("Match officials", 11);
    cout << "Umpire: " << umpires[rand()%7] << endl;
    cout << "Third Umpire: " << umpires[rand()%7] << endl;
    cout << "Match Referee: " << umpires[rand()%7] << endl;
}

void showSponsors() {
    const char* sponsors[] = { "Pepsi", "TCS", "HBL", "Jazz", "KFC" };
    printColoredSubHeader("Match Sponsors", 11);
    for (int i = 0; i < 5; i++) cout << i + 1 << ". " << sponsors[i] << endl;
}
void showMainMenu() {
    printColoredBorder(13);
    setColor(13);
    cout << "      CRICKET MATCH SIMULATOR\n";
    printColoredBorder(13);
    setColor(7);
    cout << "1. Play New Match\n";
    cout << "2. View Match Highlights\n";
    cout << "3. View Team Details\n";
    cout << "4. View All Players Statistics\n";
    cout << "5. View Available Teams\n";
    cout << "6. Exit\n";
    printColoredBorder(13);
    cout << "Enter your choice (1-6): ";
}

int main() {
    srand((unsigned)time(0));
    
    Team teams[10];
    int teamCount = 0;

    printColoredHeader("CRICKET MATCH SIMULATOR", 13);
    cout << "Loading teams...\n";
    loadTeams(teams, teamCount); 
    loadPlayerDatabase(); 
    
    if (teamCount == 0) {
        cout << "No teams found! Exiting...\n";
        return 1;
    }

    loadExistingMatchNumbers(); 

    int choice;
    do {
        showMainMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;
        }

        switch(choice) {
            case 1:
                playMatch(teams, teamCount); 
                break;
            case 2:
                {
                    int matchNum;
                    cout << "Enter match number to view highlights: ";
                    if (!(cin >> matchNum)) { 
                        cin.clear();
                        cin.ignore(1000, '\n');
                        break;
                    }
                    viewHighlights(matchNum); 
                }
                break;
            case 3:
                displayTeamDetails(teams, teamCount); 
                break;
            case 4:
                displayAllPlayersStats(); 
                break;
            case 5:
                displayAllTeams(teams, teamCount); 
                break;
            case 6:
                cout << "Thank you for using Cricket Match Simulator!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        if (choice != 6) {
            cout << "\nPress Enter to continue...";
            cin.ignore(1000, '\n');
            cin.get();
        }
    } while (choice != 6);

    for (int i = 0; i < teamCount; i++) {
        delete[] teams[i].players;
        delete[] teams[i].roles;
    }

    return 0;
}