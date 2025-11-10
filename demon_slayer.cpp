#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;

int main() {
    int slayerLevel,
        hp,
        hasTalisman,
        demonPresence,
        demonRank,
        allyCount,
        bossHP,
        totalDamage,
        specialMoveReady;
    double
        breathingMastery,
        swordSharpness;
    char
        timeOfDay;
    string
        b;
    {
        cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank
            >> swordSharpness >> allyCount >> bossHP >> totalDamage >> specialMoveReady;
    }
    {
        cout << fixed << setprecision(1);
        // Scene 1
        double power = slayerLevel * 10 + (hp / 10.0) + breathingMastery * 50;
        if (power >= 120) { b = "Hashira"; }
        else if (power >= 80) { b = " Elite"; }
        else { b = "Novice"; }
        cout << "[Scene 1] Rank: " << b << " (power = " << power << ")" << endl;

        // Scene 2
        if (timeOfDay != 'D' && timeOfDay != 'N') {
            b = "Warning: invalid timeOfDay.";
        } else if (hasTalisman == 0) {
            b = "Denied: No talisman.";
        } else if (timeOfDay == 'N' && demonPresence) {
            b = "Open silently.";
        } else {
            b = "Open cautiously.";
        }
        cout << "[Scene 2] " << b << endl;

        // Scene 3
        double adv = (101 - demonRank * 15) + swordSharpness * 0.4 + allyCount * 5;
        if (adv >= 100) { b = "Engage head-on"; }
        else if (adv >= 60) {
            b = "Harass and probe";
        }
        else {
            b = "Retreat and regroup";
        }
        cout << "[Scene 3] " << b << " (adv = " << adv << ")" << endl;

        // Scene 4
        int finalHP = bossHP - totalDamage;
        if (finalHP <= 0) {
            b = "Boss defeated! (finalHP = 0)";
        } else if (finalHP > 0 && specialMoveReady == 1 && finalHP <= 50) {
            b = "Use special move to finish! (finalHP = " + to_string(finalHP) + ")";
        } else {
            b = "Withdraw to heal. (finalHP = " + to_string(finalHP) + ")";
        }
        cout << "[Scene 4] " << b << endl;
    }
    return 0;
}
