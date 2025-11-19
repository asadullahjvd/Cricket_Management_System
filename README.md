# Cricket Match Simulator (C++) 🏏

A console-based Cricket Match Simulator written in C++.  
This program simulates limited-overs cricket matches between international teams defined in a local teams file. It supports both automatic and manual ball-by-ball scoring, maintains a player database, records match highlights,commentary,officials,sponsers and scorecards, and updates career statistics and all other aspects of a Cricket Match.

---
**👥 Contributors**

Special thanks to my amazing groupmates who contributed to the Cricket Match Simulator project:

🧑‍💻 Sana Saqib

🔗 GitHub: github.com/sana-saqib

🧑‍💻 Rida Amir

🔗 GitHub: github.com/TechQueen85

---

🎯 Table of Contents

- Overview
- Features
- Requirements
- Files created / expected
- Data formats
  - teams.txt
  - players_db.txt
  - matchhighlights.txt
- How the simulation works
  - Match flow
  - Automatic scoring model
  - Manual scoring model
  - Player performance tracking
- Building and running
- Usage / Menu options
- Input validation rules
- Code structure & important functions
- How to add or edit teams / players
- Troubleshooting & known limitations
- Suggested improvements
- License

---

📈 Overview

This program simulates a two-innings limited-overs cricket match (1–50 overs per innings). It uses text files to store teams and player career records. Users can:

- Choose teams and a venue.
- Decide overs and scoring mode (automatic / manual).
- Run innings ball-by-ball (simulated or user-influenced).
- Save highlights and a detailed scorecard to `matchhighlights.txt`.
- Update career records in `players_db.txt`.

The simulator includes basic commentary messages and randomly chooses match officials and sponsors.

---

🔥 Features

- Multiple pre-defined international teams (can be edited).
- Automatic mode — simulator picks outcomes with probabilities.
- Manual mode — user provides desired ball outcome (simulator may alter it slightly to introduce variety).
- Player performance tracking for each match (runs, wickets, balls).
- Persistent career database: `players_db.txt`.
- Highlights and full ball-by-ball scorecard saving to `matchhighlights.txt`.
- Input validation for venue, overs, match number, etc.
- Basic "Player of the Match" determination (bowling-weighted selection).
- Save and load of existing match numbers to prevent duplication.

---

⭕ Requirements

- C++ compiler supporting C++11 (or later).
- Standard library i/o and file operations.
- Works on Linux, macOS, Windows (with a compatible build environment).

---

🌀 Files created / expected

- `teams.txt` — team definitions and squads. Created automatically if not present.
- `players_db.txt` — career statistics database for players. Created/initialized automatically if not present.
- `matchhighlights.txt` — appended highlights and scorecards for each saved match.

The program executable (example `simulator`) is produced when you compile the C++ source.

---

💻 Data formats

### teams.txt
- Human-editable.
- Format:
  - "Team: <TeamName>"
  - "Players: <count>"
  - Next `<count>` lines: per-player info pipe-separated, e.g.
    ```
    Rohit Sharma|36|Batsman|248|10709|8
    ```
    (The file stores more info per player for human reference; the simulator uses the name and the role fields.)
  - "Captain: <CaptainName>"
- Example section:
  ```
  Team: India
  Players: 11
  Rohit Sharma|36|Batsman|248|10709|8
  ...
  Captain: Rohit Sharma
  ```

### players_db.txt
- Pipe-separated per player:  
  `Name|Age|Role|Matches|Runs|Wickets|Team`
- Used to load and update career stats after a match.

### matchhighlights.txt
- Appended by the program.
- Contains highlight blocks labeled:
  - `===== MATCH <number> HIGHLIGHTS =====`
  - And full scorecards under `===== MATCH <number> SCORECARD =====`
- Scorecards include ball-by-ball lines:
  ```
  Ball 1: Runs=0 Bowler=Jasprit Bumrah
  Ball 2: Runs=4 Bowler=Jasprit Bumrah
  Ball 3: Runs=0 [WICKET] Bowler=Jasprit Bumrah
  ```

---

🎮 How the simulation works

### Match flow
1. Load or create `teams.txt` and `players_db.txt`.
2. Choose two different teams.
3. Enter match details: venue and overs (1–50).
4. Decide scoring mode for each innings (automatic or manual).
5. Play innings 1 (batting first) and innings 2 (target chase).
6. After both innings:
   - Display result and player performances.
   - Update `players_db.txt` with the match contributions.
   - Request a unique match number from the user.
   - Save highlights and a full scorecard to `matchhighlights.txt`.

### Automatic scoring model
- Each ball outcome is randomly chosen using weighted probabilities:
o	40% chance of dot ball (0 runs)
o	25% chance of single (1 run)
o	15% chance of two runs
o	5% chance of three runs
o	10% chance of boundary (4 runs)
o	3% chance of six
o	2% chance of wicket
- The model is intentionally simple; bowlers are chosen randomly from the bowling pool.

### Manual scoring model
- User inputs a desired outcome for each ball (0,1,2,3,4,6). The program may randomly alter the outcome to a plausible alternative sometimes, to simulate real-match variability.
- Wicket outcomes are triggered only by the program (in manual mode the user doesn't directly type 'W' as an outcome prompt).

### Player performance tracking
- For each match, a `PlayerPerformance` entry stores runs, wickets, balls faced, balls bowled.
- After match end, career stats in `players_db.txt` are incremented:
  - Matches +1 for players who played.
  - Runs and wickets are added based on match contributions.

---

🧊 Building and running

1. Save the source (for example `main.cpp`) with the provided program.
2. Compile:

On Linux / macOS:
```bash
g++ main.cpp teams.cpp play_match.cpp scorecard_highlights.cpp match_details.cpp innings.cpp result_summary.cpp match_number.cpp -o main```

On Windows with MinGW:
```bash
g++ main.cpp teams.cpp play_match.cpp scorecard_highlights.cpp match_details.cpp innings.cpp result_summary.cpp match_number.cpp -o main```

3. Run:
```bash
./main
```
(or `simulator.exe` on Windows)

When you first run the program it will create `teams.txt` and `players_db.txt` if they do not exist.

---

📝 Usage / Menu options

Main menu options:
1. Play New Match — start the whole match setup and simulation.
2. View Match Highlights — view highlights and scorecards for a saved match number.
3. View Team Details — see squads and roles for all teams.
4. View All Players Statistics — show every player's career stats loaded from `players_db.txt`.
5. View Available Teams — list team names only.
6. Exit — quit program.

When prompted during Play New Match:
- Enter venue (stadium, city, country) and capacity (1–132000).
- Select Team 1 and Team 2 by number (must be different).
- Enter total overs for the match (1–50).
- Choose scoring mode for each innings (Automatic / Manual).
- During manual mode, input 0/1/2/3/4/6 when prompted for each ball.
- At the end, provide a unique positive match number (used to index highlights/scorecards).

---

📜 Input validation rules

- Stadium / City / Country: cannot be blank or contain digits.
- Capacity: must be integer 1–132000.
- Overs: integer 1–50.
- Team selection: integer within available teams list.
- Match number: positive integer that has not been used before (program checks `matchhighlights.txt`).

---

🧮 Code structure & important functions

High-level structures:
- Venue, Match, Team, PlayerRecord, PlayerPerformance, ball, Innings.

Key functions:
- createTeamsFile() — create `teams.txt` with default teams (called if file missing).
- createPlayerDatabase() — create `players_db.txt` with default player records.
- loadPlayerDatabase() — parse `players_db.txt` into memory.
- loadTeams() — parse `teams.txt` into Team structs.
- initializeMatchPerformances() — prepare per-match performance entries.
- initializeBowlers() — build bowler pools for each team.
- playInningsAuto() — simulate innings automatically ball-by-ball.
- playInningsManual() — manual ball-by-ball interaction.
- updateBatsmanPerformance() / updateBowlerPerformance() — increment match stats.
- updateCareerRecords() — write updated career totals to `players_db.txt`.
- saveHighlights(), saveScorecard() — append match info to `matchhighlights.txt`.
- viewHighlights(matchNumber) — locate and display highlights for a match.
- showResult() / displayFinalSummary() — determine winner and display summary.

Files are read/written using standard `ifstream`/`ofstream` calls. The program uses simple arrays and C++ strings (no external libs).

---

🎙️ How to add or edit teams / players

- teams: Edit `teams.txt` manually. Follow existing formatting:
  - For each team:
    - `Team: <Name>`
    - `Players: <n>`
    - Then n player lines; each line can be: `Name|Age|Role|Matches|Runs|Wickets` (the simulator uses `Name` and `Role`)
    - `Captain: <Name>`
- players_db.txt: Add or edit lines with:
  `Name|Age|Role|Matches|Runs|Wickets|Team`
  — the program will read these and update career totals after matches.

Important: Keep pipe-separated fields and ensure the player name exactly matches the name used in `teams.txt` to allow proper stats update.

---

🧤 Troubleshooting & known limitations

- If `teams.txt` or `players_db.txt` are malformed (missing fields, wrong counts) the loader may mis-parse or skip entries.
- The match simulation uses a simplified probability model for outcomes — not a full cricket engine.
- The "Player of the Match" logic is basic and focused more on wickets then runs. It may yield unexpected choices in edge cases.
- Manual mode does not support manually entering "W" for wicket; the program controls wickets to preserve realism and prevent abuse.
- Bowling selection is random from the selected bowlers pool; there is no bowling-overs-limitation enforcement (e.g., max 10 overs per bowler) in the current implementation.
- Only basic error handling; if file I/O fails (permissions, disk full) the program may not run as intended.
- Fixed-size arrays are used in places; very large matches are not expected (overs capped 50), and arrays are sized accordingly.

---

📌✔️ Suggested improvements / future enhancements

- Add per-bowler over limit enforcement.
- More advanced probability model using player-specific batting/bowling skills.
- Full batting order rotation and strike-rate-driven batting probabilities.
- Better selection and enforcement of bowlers, and realistic bowling changes.
- Persistent storage in JSON or a small embedded DB for more robust parsing.
- Unit tests and CI integration.
- GUI or web front-end for improved UX.
- Multiplayer or networked match management.

---

📝🔍 License

This simulator example is provided as-is for learning and small-scale use. Modify and reuse as you wish. No warranty.

---



```
