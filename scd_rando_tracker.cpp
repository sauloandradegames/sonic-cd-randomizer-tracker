// scd_rando_tracker.cpp
// Sonic CD Randomizer Tracker
// A tracker for Sonic CD Randomizer - Segments mode
// Author: Saulo Andrade
// Github: @sauloandradegames

#include <iostream>
#include <fstream>
#include <string>
#include "Stage.h"
#include "Segment.h"

using namespace std;

// ========================================
// =========== GLOBAL VARIABLES ===========
// ========================================

// List of integer identifiers for Sonic CD zones (Zone + Timeline)
enum zones
{
    pp1p,
    pp2p,
    cc1p,
    cc2p,
    tt1p,
    tt2p,
    qq1p,
    qq2p,
    ww1p,
    ww2p,
    ss1p,
    ss2p,
    mm1p,
    mm2p,
    pp1pr,
    pp2pr,
    cc1pr,
    cc2pr,
    tt1pr,
    tt2pr,
    qq1pr,
    qq2pr,
    ww1pr,
    ww2pr,
    ss1pr,
    ss2pr,
    mm1pr,
    mm2pr,
    pp1g,
    pp2g,
    pp3g,
    cc1g,
    cc2g,
    cc3g,
    tt1g,
    tt2g,
    tt3g,
    qq1g,
    qq2g,
    qq3g,
    ww1g,
    ww2g,
    ww3g,
    ss1g,
    ss2g,
    ss3g,
    mm1g,
    mm2g,
    mm3g,
    pp1b,
    pp2b,
    pp3b,
    cc1b,
    cc2b,
    cc3b,
    tt1b,
    tt2b,
    tt3b,
    qq1b,
    qq2b,
    qq3b,
    ww1b,
    ww2b,
    ww3b,
    ss1b,
    ss2b,
    ss3b,
    mm1b,
    mm2b,
    mm3b,
    gg
};

// ========================================
// ========= AUXILIARY FUNCTIONS ==========
// ========================================

// Convert user input string into integer value for zone identifier
int ConvertToZone(string z)
{
    if (z == "pp1p") {return pp1p;}
    else if (z == "pp2p") {return pp2p;}
    else if (z == "cc1p") {return cc1p;}
    else if (z == "cc2p") {return cc2p;}
    else if (z == "tt1p") {return tt1p;}
    else if (z == "tt2p") {return tt2p;}
    else if (z == "qq1p") {return qq1p;}
    else if (z == "qq2p") {return qq2p;}
    else if (z == "ww1p") {return ww1p;}
    else if (z == "ww2p") {return ww2p;}
    else if (z == "ss1p") {return ss1p;}
    else if (z == "ss2p") {return ss2p;}
    else if (z == "mm1p") {return mm1p;}
    else if (z == "mm2p") {return mm2p;}
    else if (z == "pp1pr") {return pp1pr;}
    else if (z == "pp2pr") {return pp2pr;}
    else if (z == "cc1pr") {return cc1pr;}
    else if (z == "cc2pr") {return cc2pr;}
    else if (z == "tt1pr") {return tt1pr;}
    else if (z == "tt2pr") {return tt2pr;}
    else if (z == "qq1pr") {return qq1pr;}
    else if (z == "qq2pr") {return qq2pr;}
    else if (z == "ww1pr") {return ww1pr;}
    else if (z == "ww2pr") {return ww2pr;}
    else if (z == "ss1pr") {return ss1pr;}
    else if (z == "ss2pr") {return ss2pr;}
    else if (z == "mm1pr") {return mm1pr;}
    else if (z == "mm2pr") {return mm2pr;}
    else if (z == "pp1g") {return pp1g;}
    else if (z == "pp2g") {return pp2g;}
    else if (z == "pp3g") {return pp3g;}
    else if (z == "cc1g") {return cc1g;}
    else if (z == "cc2g") {return cc2g;}
    else if (z == "cc3g") {return cc3g;}
    else if (z == "tt1g") {return tt1g;}
    else if (z == "tt2g") {return tt2g;}
    else if (z == "tt3g") {return tt3g;}
    else if (z == "qq1g") {return qq1g;}
    else if (z == "qq2g") {return qq2g;}
    else if (z == "qq3g") {return qq3g;}
    else if (z == "ww1g") {return ww1g;}
    else if (z == "ww2g") {return ww2g;}
    else if (z == "ww3g") {return ww3g;}
    else if (z == "ss1g") {return ss1g;}
    else if (z == "ss2g") {return ss2g;}
    else if (z == "ss3g") {return ss3g;}
    else if (z == "mm1g") {return mm1g;}
    else if (z == "mm2g") {return mm2g;}
    else if (z == "mm3g") {return mm3g;}
    else if (z == "pp1b") {return pp1b;}
    else if (z == "pp2b") {return pp2b;}
    else if (z == "pp3b") {return pp3b;}
    else if (z == "cc1b") {return cc1b;}
    else if (z == "cc2b") {return cc2b;}
    else if (z == "cc3b") {return cc3b;}
    else if (z == "tt1b") {return tt1b;}
    else if (z == "tt2b") {return tt2b;}
    else if (z == "tt3b") {return tt3b;}
    else if (z == "qq1b") {return qq1b;}
    else if (z == "qq2b") {return qq2b;}
    else if (z == "qq3b") {return qq3b;}
    else if (z == "ww1b") {return ww1b;}
    else if (z == "ww2b") {return ww2b;}
    else if (z == "ww3b") {return ww3b;}
    else if (z == "ss1b") {return ss1b;}
    else if (z == "ss2b") {return ss2b;}
    else if (z == "ss3b") {return ss3b;}
    else if (z == "mm1b") {return mm1b;}
    else if (z == "mm2b") {return mm2b;}
    else if (z == "mm3b") {return mm3b;}
    else if (z == "gg") {return gg;}
    else {return -1;}
}

// Return the corresponding string name of the integer zone identifier
string GetZone(int z)
{
    switch(z)
    {
        case (pp1p): return "Palmtree Panic 1 Past";
        case (pp2p): return "Palmtree Panic 2 Past";
        case (cc1p): return "Collision Chaos 1 Past";
        case (cc2p): return "Collision Chaos 2 Past";
        case (tt1p): return "Tidal Tempest 1 Past";
        case (tt2p): return "Tidal Tempest 2 Past";
        case (qq1p): return "Quartz Quadrant 1 Past";
        case (qq2p): return "Quartz Quadrant 2 Past";
        case (ww1p): return "Wacky Workbench 1 Past";
        case (ww2p): return "Wacky Workbench 2 Past";
        case (ss1p): return "Stardust Speedway 1 Past";
        case (ss2p): return "Stardust Speedway 2 Past";
        case (mm1p): return "Metallic Madness 1 Past";
        case (mm2p): return "Metallic Madness 2 Past";
        case (pp1pr): return "Palmtree Panic 1 Present";
        case (pp2pr): return "Palmtree Panic 2 Present";
        case (cc1pr): return "Collision Chaos 1 Present";
        case (cc2pr): return "Collision Chaos 2 Present";
        case (tt1pr): return "Tidal Tempest 1 Present";
        case (tt2pr): return "Tidal Tempest 2 Present";
        case (qq1pr): return "Quartz Quadrant 1 Present";
        case (qq2pr): return "Quartz Quadrant 2 Present";
        case (ww1pr): return "Wacky Workbench 1 Present";
        case (ww2pr): return "Wacky Workbench 2 Present";
        case (ss1pr): return "Stardust Speedway 1 Present";
        case (ss2pr): return "Stardust Speedway 2 Present";
        case (mm1pr): return "Metallic Madness 1 Present";
        case (mm2pr): return "Metallic Madness 2 Present";
        case (pp1g): return "Palmtree Panic 1 Good Future";
        case (pp2g): return "Palmtree Panic 2 Good Future";
        case (pp3g): return "Palmtree Panic 3 Good Future";
        case (cc1g): return "Collision Chaos 1 Good Future";
        case (cc2g): return "Collision Chaos 2 Good Future";
        case (cc3g): return "Collision Chaos 3 Good Future";
        case (tt1g): return "Tidal Tempest 1 Good Future";
        case (tt2g): return "Tidal Tempest 2 Good Future";
        case (tt3g): return "Tidal Tempest 3 Good Future";
        case (qq1g): return "Quartz Quadrant 1 Good Future";
        case (qq2g): return "Quartz Quadrant 2 Good Future";
        case (qq3g): return "Quartz Quadrant 3 Good Future";
        case (ww1g): return "Wacky Workbench 1 Good Future";
        case (ww2g): return "Wacky Workbench 2 Good Future";
        case (ww3g): return "Wacky Workbench 3 Good Future";
        case (ss1g): return "Stardust Speedway 1 Good Future";
        case (ss2g): return "Stardust Speedway 2 Good Future";
        case (ss3g): return "Stardust Speedway 3 Good Future";
        case (mm1g): return "Metallic Madness 1 Good Future";
        case (mm2g): return "Metallic Madness 2 Good Future";
        case (mm3g): return "Metallic Madness 3 Good Future";
        case (pp1b): return "Palmtree Panic 1 Bad Future";
        case (pp2b): return "Palmtree Panic 2 Bad Future";
        case (pp3b): return "Palmtree Panic 3 Bad Future";
        case (cc1b): return "Collision Chaos 1 Bad Future";
        case (cc2b): return "Collision Chaos 2 Bad Future";
        case (cc3b): return "Collision Chaos 3 Bad Future";
        case (tt1b): return "Tidal Tempest 1 Bad Future";
        case (tt2b): return "Tidal Tempest 2 Bad Future";
        case (tt3b): return "Tidal Tempest 3 Bad Future";
        case (qq1b): return "Quartz Quadrant 1 Bad Future";
        case (qq2b): return "Quartz Quadrant 2 Bad Future";
        case (qq3b): return "Quartz Quadrant 3 Bad Future";
        case (ww1b): return "Wacky Workbench 1 Bad Future";
        case (ww2b): return "Wacky Workbench 2 Bad Future";
        case (ww3b): return "Wacky Workbench 3 Bad Future";
        case (ss1b): return "Stardust Speedway 1 Bad Future";
        case (ss2b): return "Stardust Speedway 2 Bad Future";
        case (ss3b): return "Stardust Speedway 3 Bad Future";
        case (mm1b): return "Metallic Madness 1 Bad Future";
        case (mm2b): return "Metallic Madness 2 Bad Future";
        case (mm3b): return "Metallic Madness 3 Bad Future";
        case (gg): return "Final Fever";
        default: return "";
    }
}

// Return a shorter text for the corresponding string name of the integer zone identifier
string GetZoneShort(int z)
{
    switch(z)
    {
        case (pp1p): return "PP1 Past   ";
        case (pp2p): return "PP2 Past   ";
        case (cc1p): return "CC1 Past   ";
        case (cc2p): return "CC2 Past   ";
        case (tt1p): return "TT1 Past   ";
        case (tt2p): return "TT2 Past   ";
        case (qq1p): return "QQ1 Past   ";
        case (qq2p): return "QQ2 Past   ";
        case (ww1p): return "WW1 Past   ";
        case (ww2p): return "WW2 Past   ";
        case (ss1p): return "SS1 Past   ";
        case (ss2p): return "SS2 Past   ";
        case (mm1p): return "MM1 Past   ";
        case (mm2p): return "MM2 Past   ";
        case (pp1pr): return "PP1 Present";
        case (pp2pr): return "PP2 Present";
        case (cc1pr): return "CC1 Present";
        case (cc2pr): return "CC2 Present";
        case (tt1pr): return "TT1 Present";
        case (tt2pr): return "TT2 Present";
        case (qq1pr): return "QQ1 Present";
        case (qq2pr): return "QQ2 Present";
        case (ww1pr): return "WW1 Present";
        case (ww2pr): return "WW2 Present";
        case (ss1pr): return "SS1 Present";
        case (ss2pr): return "SS2 Present";
        case (mm1pr): return "MM1 Present";
        case (mm2pr): return "MM2 Present";
        case (pp1g): return "PP1 Good Ft";
        case (pp2g): return "PP2 Good Ft";
        case (pp3g): return "PP3 Good Ft";
        case (cc1g): return "CC1 Good Ft";
        case (cc2g): return "CC2 Good Ft";
        case (cc3g): return "CC3 Good Ft";
        case (tt1g): return "TT1 Good Ft";
        case (tt2g): return "TT2 Good Ft";
        case (tt3g): return "TT3 Good Ft";
        case (qq1g): return "QQ1 Good Ft";
        case (qq2g): return "QQ2 Good Ft";
        case (qq3g): return "QQ3 Good Ft";
        case (ww1g): return "WW1 Good Ft";
        case (ww2g): return "WW2 Good Ft";
        case (ww3g): return "WW3 Good Ft";
        case (ss1g): return "SS1 Good Ft";
        case (ss2g): return "SS2 Good Ft";
        case (ss3g): return "SS3 Good Ft";
        case (mm1g): return "MM1 Good Ft";
        case (mm2g): return "MM2 Good Ft";
        case (mm3g): return "MM3 Good Ft";
        case (pp1b): return "PP1 Bad Ft ";
        case (pp2b): return "PP2 Bad Ft ";
        case (pp3b): return "PP3 Bad Ft ";
        case (cc1b): return "CC1 Bad Ft ";
        case (cc2b): return "CC2 Bad Ft ";
        case (cc3b): return "CC3 Bad Ft ";
        case (tt1b): return "TT1 Bad Ft ";
        case (tt2b): return "TT2 Bad Ft ";
        case (tt3b): return "TT3 Bad Ft ";
        case (qq1b): return "QQ1 Bad Ft ";
        case (qq2b): return "QQ2 Bad Ft ";
        case (qq3b): return "QQ3 Bad Ft ";
        case (ww1b): return "WW1 Bad Ft ";
        case (ww2b): return "WW2 Bad Ft ";
        case (ww3b): return "WW3 Bad Ft ";
        case (ss1b): return "SS1 Bad Ft ";
        case (ss2b): return "SS2 Bad Ft ";
        case (ss3b): return "SS3 Bad Ft ";
        case (mm1b): return "MM1 Bad Ft ";
        case (mm2b): return "MM2 Bad Ft ";
        case (mm3b): return "MM3 Bad Ft ";
        case (gg): return "Final Fever";
        default: return "";
    }
}

// ========================================
// ===== MAIN FUNCTION: TRACKER LOGIC =====
// ========================================

int main()
{
    /* String variables for user input */
    string input_goal = "";
    string input_zone = "";
    string input_time = "";

    /* Integer variables for input conversion */
    int input;

    /* Segment stuff */
    // A "Segment" is a set of 9 stages
    // The eight first stages can be any act 1 or 2, in any time zone
    // The final stage is an act 3 boss stage
    Segment segment = Segment();
    int current_segment = 0; // Index for current segment
    int total_segment = 7;   // How many segments we have in this randomizer?

    /* OBS Integration stuff */
    // Visual tracker for OBS.
    // Setting things up on OBS can be a bit messy, but it works
    // Trust me ;)
    bool isBossActive[7] = {true, true, true, true, true, true, true};
    string file_name = "track";
    string file_index[7] = {"PP", "CC", "TT", "QQ", "WW", "SS", "MM"};
    string file_ext = ".txt";
    ofstream file_pointer;

    // Initialization OBS integration
    for (int i = 0; i < 7; i++)
    {
        file_pointer.open(file_name + file_index[i] + file_ext);
        file_pointer << "XX";
        file_pointer.close();
    }

    /* ============= */
    /* Program Start */
    /* ============= */
    cout << "=======================================================" << endl;
    cout << "Welcome to SauloAndrade's Sonic CD Randomizer Tracker" << endl;
    cout << "Type any of the following during [Goal?] prompt:" << endl;
    cout << "- 'g' for Stage Clear (Goal)" << endl;
    cout << "- 'p' for Time Travel (Past)" << endl;
    cout << "- 'f' for Time Travel (Future)" << endl;
    cout << "- 'gg' to end the tracker" << endl;
    cout << endl;
    cout << "Type an abbreviation of zone name," << endl;
    cout << "followed by zone number during [Zone?] prompt." << endl;
    cout << "- Ex.: type 'pp2' for Palmtree Panic 2" << endl;
    cout << "- or type 'mm1' for Metallic Madness 1" << endl;
    cout << endl;
    cout << "Type any of the following during [Time?] prompt:" << endl;
    cout << "- 'p' for Past" << endl;
    cout << "- 'pr' for Present" << endl;
    cout << "- 'g' for Good Future" << endl;
    cout << "- 'b' for Bad Future" << endl;
    cout << "=======================================================" << endl;

    // First user input
    cout << ">> Randomizer start!" << endl;
    input_goal = "g";

    cout << "[Starting Zone?] ";
    cin >> input_zone;

    cout << "[Starting Time?] ";
    cin >> input_time;

    // Convert user input from string to int
    input = ConvertToZone(input_zone + input_time);

    // Type "gg" during [Goal?] prompt to close the tracker
    while (input_goal != "gg")
    {
        // Add stage to segment
        if (GetZone(input) != "")
        {
            if (input_goal == "g")
            {
                segment.insert(0, input);
            }
            else if (input_goal == "p")
            {
                segment.insert(1, input);
            }
            else if (input_goal == "f")
            {
                segment.insert(2, input);
            }
            else
            {
                cout << "ERROR: Invalid Goal" << endl;
            }
        }

        // Print out info about current stage
        system("clear");
        cout << "=============== " << "SEGMENT " << current_segment+1 << " of " << total_segment << " ===============" << endl;
        cout << "NOW ENTERING: " << GetZone(segment.getCurr()->getName()) << endl;
        cout << "GOAL  : ";
        if (segment.getCurr()->getGoal() == NULL)
        {
            cout << " " << endl;
        }
        else
        {
            cout << GetZone(segment.getCurr()->getGoal()->getName()) << endl;
        }
        cout << "PAST  : ";
        if (segment.getCurr()->getPast() == NULL)
        {
            cout << " " << endl;
        }
        else
        {
            cout << GetZone(segment.getCurr()->getPast()->getName()) << endl;
        }
        cout << "FUTURE: ";
        if (segment.getCurr()->getFuture() == NULL)
        {
            cout << " " << endl;
        }
        else
        {
            cout << GetZone(segment.getCurr()->getFuture()->getName()) << endl;
        }
        cout << endl;

        // Print out all stages in current segment
        // Print out their destinations for time travels
        cout << "    " << "|   PAST    |" << " <<< " << "|   GOAL    |" << " >>> " << "|  FUTURE   |" << endl;
        for (int i = 0; i < segment.getNumStages(); i++)
        {
            if (segment.getStageByIndex(i) == segment.getCurr())
            {
                cout << "    ";
                if (segment.getStageByIndex(i)->getPast() != NULL)
                {
                    cout << "|" << GetZoneShort(segment.getStageByIndex(i)->getPast()->getName()) << "|";
                }
                else
                {
                    cout << "|" << "-----------" << "|";
                }
                
                cout << " <<< " << "|" << GetZoneShort(segment.getStageByIndex(i)->getName()) << "|" << " >>> ";

                if (segment.getStageByIndex(i)->getFuture() != NULL)
                {
                    cout << "|" << GetZoneShort(segment.getStageByIndex(i)->getFuture()->getName()) << "|";
                }
                else
                {
                    cout << "|" << "-----------" << "|";
                }
                cout << endl;
            }
            else
            {
                cout << "    ";
                if (segment.getStageByIndex(i)->getPast() != NULL)
                {
                    cout << " " << GetZoneShort(segment.getStageByIndex(i)->getPast()->getName()) << " ";
                }
                else
                {
                    cout << " " << "-----------" << " ";
                }
                
                cout << "     " << " " << GetZoneShort(segment.getStageByIndex(i)->getName()) << " " << "     ";

                if (segment.getStageByIndex(i)->getFuture() != NULL)
                {
                    cout << " " << GetZoneShort(segment.getStageByIndex(i)->getFuture()->getName()) << " ";
                }
                else
                {
                    cout << " " << "-----------" << " ";
                }
                cout << endl;
            }
        }
        cout << endl;

        // If player enters a boss stage, clear the segment tracker
        // Increment current_segment counter
        // Update OBS integration
        if (input == pp3g || input == cc3g || input == tt3g || input == qq3g || input == ww3g || input == ss3g || input == mm3g || input == pp3b || input == cc3b || input == tt3b || input == qq3b || input == ww3b || input == ss3b || input == mm3b)
        {
            segment.clearSegment();
            current_segment++;

            if (input == pp3g || input == pp3b) {isBossActive[0] = false;}
            else if (input == cc3g || input == cc3b) {isBossActive[1] = false;}
            else if (input == tt3g || input == tt3b) {isBossActive[2] = false;}
            else if (input == qq3g || input == qq3b) {isBossActive[3] = false;}
            else if (input == ww3g || input == ww3b) {isBossActive[4] = false;}
            else if (input == ss3g || input == ss3b) {isBossActive[5] = false;}
            else if (input == mm3g || input == mm3b) {isBossActive[6] = false;}

            for (int i = 0; i < 7; i++)
            {
                file_pointer.open(file_name + file_index[i] + file_ext);
                if (isBossActive[i])
                {
                    file_pointer << "XX";
                }
                else
                {
                    file_pointer << "";
                }
                file_pointer.close();
            }
        }

        // Wait for next user input
        cout << "[Goal?] ";
        cin >> input_goal;
        if (input_goal != "gg")
        {
            cout << "[Zone?] ";
            cin >> input_zone;
            cout << "[Time?] ";
            cin >> input_time;
            input = ConvertToZone(input_zone + input_time);
        }
    }
    return 0;
}