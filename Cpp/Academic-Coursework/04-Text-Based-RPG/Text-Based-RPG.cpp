#include <iostream> 
#include <string> 
using namespace std;
#include <cstdlib>  
#include <ctime>    
#include <limits>   

/* Author: Usman O. Olanrewaju (Blu3 Sky) 
 * Title: Text-Based-RPG 
 */
int getRandomInt(int min, int max) {
    
    return min + (rand() % (max - min + 1));
}


struct Player {
    int health;
    int strength;
    int agility;
    int level;
    int gold;
    int experience; 
    int maxHealth;  
};

class GameEngine{
   public: 
void displayStatus(const Player& player) {
    cout << "\nPlayer Status:\n";
    cout << "  Level: " << player.level << "\n";
    cout << "  Health: " << player.health << "/" << player.maxHealth << "\n";
    cout << "  Strength: " << player.strength << "\n";
    cout << "  Agility: " << player.agility << "\n";
    cout << "  Gold: " << player.gold << "\n";
   
}


void encounterEnemy(Player& player) {
    cout << "You encounter a fearsome enemy!\n";
    cout << "Prepare for battle...\n";

    
    int enemyStrength = getRandomInt(1, 20);
    cout << "The enemy has strength: " << enemyStrength << "\n";

    
    if (player.strength > enemyStrength) {
        cout << "You defeated the enemy and gained experience points!\n";
        int xpGained = getRandomInt(5, 15);
        player.experience += xpGained;
      

        
        if (player.experience >= 20) {
             player.level++;
             player.experience -= 20; 
             player.strength++;
             player.agility++;
             player.maxHealth += 10;
             player.health = player.maxHealth; 
             cout << "*** LEVEL UP! You are now Level " << player.level << "! Stats improved. ***\n";
        }
    } else {
        cout << "The enemy was too strong! You lose some health.\n";
        int damageTaken = getRandomInt(5, 15); 
        player.health -= damageTaken;
        cout << "You lost " << damageTaken << " health points.\n";

        
        if (player.health <= 0) {
            cout << "You have fallen in battle! Game Over.\n";
            player.health = 0; 
        }
    }
}


void findTreasure(Player& player) {
    cout << "You stumble upon a hidden treasure!\n";
    int goldFound = getRandomInt(1, 100); 
    player.gold += goldFound;
    cout << "You found " << goldFound << " gold coins.\n";
}

void restAndHeal(Player& player) {
    cout << "You find a peaceful resting spot.\n";
    cout << "You rest and heal your wounds.\n";
    int healthRestored = getRandomInt(10, 40); 
    player.health += healthRestored;

 
    if (player.health > player.maxHealth) {
        player.health = player.maxHealth;
    }
    cout << "You restored " << healthRestored << " health points (up to your max).\n";
}


void runFantasyGame() {
    cout << "\n--- Starting Fantasy Adventure Game (Question 1) ---\n";

   
    Player player = {100, 10, 10, 1, 0, 0, 100};
    cout << "Welcome to the Mystical Field, brave adventurer!\n";
    displayStatus(player);

    
    for (int l = 1; l <= 3; ++l) {
       
        if (player.health <= 0) {
            cout << "\nYour journey ended prematurely.\n";
            break; 
        }

    cout << "\n-------------------------------------\n";
        cout << "Exploring Location " << l << "\n";

        
        int choice = 0;
        cout << "Choose a path to explore (Enter 1, 2, or 3): ";
        
        while (!(cin >> choice) || choice < 1 || choice > 3) {
             cout << "Invalid choice. Please enter 1, 2, or 3: ";
             cin.clear(); 
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "You venture down path " << choice << "...\n";

      
        int eventType = getRandomInt(1, 3);

        
        switch (eventType) {
            case 1:
                encounterEnemy(player);
                break;
            case 2:
                findTreasure(player);
                break;
            case 3:
                restAndHeal(player);
                break;
            default:
                cout << "The path is uneventful...\n";
                break;
        }

        
        if (player.health > 0) {
             displayStatus(player);
        }

    }
    if (player.health > 0) {
       cout << "\n-------------------------------------\n";
       cout << "You have finished exploring these initial locations.\n";
    }

     cout << "--- End of Fantasy Adventure Game ---\n";
}

};

int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    GameEngine lord;
    
    lord.runFantasyGame();


}
