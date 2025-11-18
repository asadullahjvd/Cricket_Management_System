#include "teams.h"
#include "structs.h"
#include "main.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void createTeamsFile() {
    ofstream file("teams.txt");
    if (!file) {
        cout << "Error creating teams file!" << endl;
        return;
    }
    file << "Team: India\nPlayers: 11\nRohit Sharma|36|Batsman|248|10709|8\nVirat Kohli|35|Batsman|292|13848|4\nKL Rahul|31|Batsman|72|2781|0\nShreyas Iyer|29|Batsman|55|1841|0\nRishabh Pant|26|Keeper|54|1628|0\nHardik Pandya|30|Allrounder|87|1758|85\nRavindra Jadeja|35|Allrounder|197|2758|220\nJasprit Bumrah|30|Bowler|89|86|149\nMohammed Shami|33|Bowler|101|229|195\nKuldeep Yadav|29|Bowler|95|259|167\nMohammed Siraj|29|Bowler|43|55|78\nCaptain: Rohit Sharma\n\n";
    file << "Team: Australia\nPlayers: 11\nPat Cummins|30|Bowler|88|592|141\nSteve Smith|34|Batsman|155|5674|19\nDavid Warner|37|Batsman|161|6932|1\nMarnus Labuschagne|29|Batsman|44|2224|2\nGlenn Maxwell|35|Allrounder|136|3890|75\nMitchell Marsh|32|Allrounder|89|2213|59\nAlex Carey|32|Keeper|67|1325|0\nMitchell Starc|34|Bowler|121|675|236\nJosh Hazlewood|33|Bowler|85|249|138\nAdam Zampa|32|Bowler|89|159|146\nTravis Head|30|Batsman|67|2401|16\nCaptain: Pat Cummins\n\n";
    file << "Team: England\nPlayers: 11\nJos Buttler|33|Keeper|187|5527|0\nJonny Bairstow|34|Batsman|118|4298|0\nJoe Root|33|Batsman|172|9274|19\nBen Stokes|32|Allrounder|114|3985|93\nLiam Livingstone|30|Allrounder|45|894|32\nMoeen Ali|36|Allrounder|146|2314|127\nSam Curran|25|Allrounder|43|556|58\nChris Woakes|35|Bowler|122|1448|175\nMark Wood|34|Bowler|73|271|98\nAdil Rashid|35|Bowler|141|761|196\nJofra Archer|29|Bowler|21|66|42\nCaptain: Jos Buttler\n\n";
    file << "Team: Pakistan\nPlayers: 11\nBabar Azam|29|Batsman|117|5729|0\nMohammad Rizwan|31|Keeper|85|2797|0\nFakhar Zaman|34|Batsman|85|3365|0\nImam-ul-Haq|28|Batsman|72|2873|0\nShadab Khan|25|Allrounder|92|812|98\nMohammad Nawaz|29|Allrounder|62|628|69\nHaris Rauf|30|Bowler|45|78|83\nShaheen Afridi|24|Bowler|52|128|104\nNaseem Shah|21|Bowler|17|25|32\nHasan Ali|29|Bowler|70|329|96\nIftikhar Ahmed|33|Allrounder|45|806|8\nCaptain: Babar Azam\n\n";
    file << "Team: New Zealand\nPlayers: 11\nKane Williamson|33|Batsman|169|7022|43\nTrent Boult|34|Bowler|114|259|211\nTim Southee|35|Bowler|170|874|221\nDevon Conway|32|Batsman|32|1392|0\nDaryl Mitchell|32|Allrounder|41|1318|11\nGlenn Phillips|27|Batsman|41|1042|6\nMitchell Santner|32|Allrounder|109|1021|109\nIsh Sodhi|31|Bowler|96|289|129\nLockie Ferguson|32|Bowler|45|65|66\nTom Latham|31|Keeper|148|4430|0\nJames Neesham|33|Allrounder|82|1287|72\nCaptain: Kane Williamson\n\n";
    file << "Team: South Africa\nPlayers: 11\nTemba Bavuma|33|Batsman|38|1678|0\nQuinton de Kock|31|Keeper|155|6770|0\nAiden Markram|29|Batsman|68|2410|12\nDavid Miller|35|Batsman|172|4495|0\nHeinrich Klaasen|32|Keeper|47|1574|0\nMarco Jansen|24|Allrounder|25|324|38\nKagiso Rabada|28|Bowler|106|538|157\nLungi Ngidi|27|Bowler|53|103|86\nAnrich Nortje|30|Bowler|25|62|48\nTabraiz Shamsi|33|Bowler|75|96|98\nKeshav Maharaj|34|Bowler|49|258|62\nCaptain: Temba Bavuma\n\n";
    file << "Team: Sri Lanka\nPlayers: 11\nDasun Shanaka|32|Allrounder|66|1512|27\nPathum Nissanka|25|Batsman|39|1456|0\nKusal Mendis|29|Keeper|134|3985|0\nCharith Asalanka|26|Batsman|44|1428|6\nWanindu Hasaranga|26|Allrounder|58|892|91\nDhananjaya de Silva|32|Allrounder|101|2095|44\nMaheesh Theekshana|23|Bowler|42|65|55\nDushmantha Chameera|32|Bowler|54|98|68\nLahiru Kumara|27|Bowler|35|42|41\nKasun Rajitha|30|Bowler|32|47|38\nAngelo Mathews|36|Allrounder|248|5865|122\nCaptain: Dasun Shanaka\n\n";
    file << "Team: West Indies\nPlayers: 11\nNicholas Pooran|28|Keeper|71|2091|0\nShai Hope|30|Keeper|127|5266|0\nBrandon King|29|Batsman|42|1289|0\nShimron Hetmyer|27|Batsman|67|1797|0\nJason Holder|32|Allrounder|154|2809|163\nRovman Powell|30|Batsman|52|1148|6\nAlzarri Joseph|27|Bowler|47|102|73\nAkeal Hosein|30|Bowler|35|156|35\nGudakesh Motie|28|Bowler|12|24|16\nRomario Shepherd|29|Allrounder|21|238|24\nKyle Mayers|31|Allrounder|32|761|20\nCaptain: Nicholas Pooran\n\n";
    file << "Team: Bangladesh\nPlayers: 11\nShakib Al Hasan|36|Allrounder|247|7576|317\nLitton Das|29|Keeper|92|2764|0\nNajmul Hossain|24|Batsman|44|1494|0\nMushfiqur Rahim|36|Keeper|265|7396|2\nMahmudullah|38|Allrounder|228|5341|102\nMehidy Hasan|26|Allrounder|92|1048|87\nMustafizur Rahman|28|Bowler|101|156|154\nTaskin Ahmed|29|Bowler|52|88|59\nShoriful Islam|22|Bowler|25|22|34\nHasan Mahmud|24|Bowler|15|18|16\nTowhid Hridoy|23|Batsman|32|897|0\nCaptain: Shakib Al Hasan\n\n";
    file << "Team: Afghanistan\nPlayers: 11\nRashid Khan|25|Bowler|101|679|190\nMohammad Nabi|39|Allrounder|161|3345|158\nRahmanullah Gurbaz|22|Keeper|41|1354|0\nIbrahim Zadran|22|Batsman|32|1256|0\nRahmat Shah|30|Batsman|112|3456|12\nHashmatullah Shahidi|29|Batsman|78|2078|0\nNajibullah Zadran|30|Batsman|98|2278|0\nMujeeb Ur Rahman|23|Bowler|84|98|106\nFazalhaq Farooqi|23|Bowler|28|25|38\nNaveen-ul-Haq|24|Bowler|18|22|26\nAzmatullah Omarzai|24|Allrounder|25|487|12\nCaptain: Rashid Khan\n";
    file.close();
    cout << "Teams file created successfully!\n";
}

void loadTeams(Team teams[], int &teamCount) {
    ifstream file("teams.txt");
    if (!file) {
        createTeamsFile();
        file.open("teams.txt");
        if (!file) return;
    }
    string line;
    Team currentTeam;
    bool readingPlayers = false;
    int playersRead = 0;
    teamCount = 0;
    while (getline(file, line) && teamCount < 10) {
        if (line.empty()) continue;
        if (line.find("Team: ") == 0) {
            if (!currentTeam.teamName.empty()) { teams[teamCount++] = currentTeam; }
            currentTeam.teamName = line.substr(6);
            readingPlayers = false;
        }
        else if (line.find("Players: ") == 0) {
            currentTeam.n_players = stoi(line.substr(9));
            currentTeam.players = new string[currentTeam.n_players];
            currentTeam.roles = new string[currentTeam.n_players];
            playersRead = 0;
            readingPlayers = true;
        }
        else if (line.find("Captain: ") == 0) {
            currentTeam.captain = line.substr(9);
            readingPlayers = false;
        }
        else if (readingPlayers && playersRead < currentTeam.n_players) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            if (pos1 != string::npos && pos2 != string::npos) {
                string playerName = line.substr(0, pos1);
                string role = line.substr(pos2 + 1);
                size_t pos3 = role.find('|');
                if (pos3 != string::npos) role = role.substr(0, pos3);
                currentTeam.players[playersRead] = playerName;
                currentTeam.roles[playersRead] = role;
                playersRead++;
            }
        }
    }
    if (!currentTeam.teamName.empty()) { teams[teamCount++] = currentTeam; }
    file.close();
}

void displayAllTeams(const Team teams[], int teamCount) {
    printColoredHeader("AVAILABLE TEAMS", 13);
    for (int i = 0; i < teamCount; i++) {
        cout << i + 1 << ". " << teams[i].teamName << endl;
    }
}

void displayTeamDetails(const Team teams[], int teamCount) {
    printColoredHeader("TEAM DETAILS", 13);
    for (int i = 0; i < teamCount; i++) {
        printColoredSubHeader(teams[i].teamName, 11);
        cout << "Captain: " << teams[i].captain << endl;
        cout << "Squad:\n";
        for (int j = 0; j < teams[i].n_players; j++) {
            cout << "  " << j + 1 << ". " << teams[i].players[j] << " (" << teams[i].roles[j] << ")" << endl;
        }
    }
}

void displayAllPlayersStats() {
    printColoredHeader("ALL PLAYERS STATISTICS", 13);
    for (int i = 0; i < totalPlayers; i++) {
        cout << allPlayers[i].name << " | Age: " << allPlayers[i].age << " | Role: " << allPlayers[i].role 
             << " | Matches: " << allPlayers[i].matches << " | Runs: " << allPlayers[i].runs 
             << " | Wickets: " << allPlayers[i].wickets << " | Team: " << allPlayers[i].team << endl;
    }
}

Team selectTeam(const Team teams[], int teamCount, const string &prompt) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > teamCount) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter 1-" << teamCount << ".\n";
            continue;
        }
        cin.ignore(1000, '\n');
        break;
    }
    return teams[choice - 1];
}