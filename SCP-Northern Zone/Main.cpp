#include <iostream>
#include <conio.h>
#include <string>
#include <Math.h>
#include "Draw.h"
#include "Actors.h"
#include "Vectors.h"
#include "windows.h"
#include "Rooms.h"


using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");
    std::system("mode con cols=141 lines=55");


    
    Player player(0, 0, 5, 5, 3, 4, 3);
    player.hitPoints = (rand() % 6)+2;
    player.save = rand() % 6;
    player.strength = rand() % 6;
    player.toughness = rand() % 6;
    Enemy enemy(0, 0, 5, 5, 3, 4, 3, 4);
    bool gameIsActive = true;
    int steps = 0;
    while(gameIsActive)
    {
        
        std::system("cls");
        Sleep(200);
        string *command = new string;
        *command = "88";

        if(steps%2 == 0)
        while (*command == "88") {

            cout << "Вы попали в странное место и не помните, как. Перед Вами странная металлическая дверь с кнопкой" << endl;
            cout << "-1.Посмотреть рекорд" << endl;
            cout << "0.Сохранить свое положение" << endl;
            cout << "1.Посмотреть на дверь" << endl;
            cout << "2.Открыть дверь и пройти" << endl;
            cin >> *command;
            if(*command == "-1")
            Drawer::Draw("save.txt");
            if (*command == "0") {
                ofstream out;
                out.open("save.txt");
                if (out.is_open())
                {
                    out << steps + " комнат(ы) было пройдено мной" << endl;
                }
                out.close();
            }
            if (*command == "1")
                Drawer::Draw("door.txt");
            Sleep(2000);
            std::system("cls");
            }
            else {
            enemy.criticalChance = rand() % 6;
            enemy.hitPoints = rand() % 6;
            enemy.save = rand() % 6;
            enemy.strength = rand() % 6;
            enemy.toughness = rand() % 6;
            
            cout << "Вы попали в тенмый коридор и встретили страшное существо. Он явно натсроенно не дружелюбно." << endl;
            cout << "1.Посмотреть на существо" << endl;
            cout << "2.Сразиться" << endl;
            cout << "3.Бежать" << endl;
            cin >> *command;
            if (*command == "1")
                Drawer::Draw("enemy.txt");
            Sleep(2000);
            std::system("cls");
            if (*command == "2") {
                bool battel = true;
                while (battel) {
                    cout << "Происходит бой!" << endl;
                    if (rand() % 7 < enemy.save)
                        enemy.hitPoints = player.strength - enemy.toughness;
                    if (rand() % 7 < player.save)
                        player.hitPoints = enemy.strength - player.toughness;
                    if (player.hitPoints > 0 && enemy.hitPoints <= 0)
                        battel = false;
                    if (player.hitPoints < 0) {
                        battel = false;
                        cout << "Вы погибли"<< endl;
                        Sleep(4000);
                        player.hitPoints = (rand() % 6) + 2;
                        player.save = rand() % 6;
                        player.strength = rand() % 6;
                        player.toughness = rand() % 6; 
                        steps = 0;
                        enemy.criticalChance = rand() % 6;
                        enemy.hitPoints = rand() % 6;
                        enemy.save = rand() % 6;
                        enemy.strength = rand() % 6;
                        enemy.toughness = rand() % 6;
                    }
                }
            }
            if (*command == "3" && rand() % 7 > enemy.criticalChance) {
                cout << "Вы успешно избежали существо";
            }
            else {
                cout << "Вы погибли" << endl;
                Sleep(4000);
                player.hitPoints = (rand() % 6) + 2;
                player.save = rand() % 6;
                player.strength = rand() % 6;
                player.toughness = rand() % 6;
                steps = 0;
                enemy.criticalChance = rand() % 6;
                enemy.hitPoints = rand() % 6;
                enemy.save = rand() % 6;
                enemy.strength = rand() % 6;
                enemy.toughness = rand() % 6;
            }
            Sleep(2000);
            std::system("cls");
        }
        steps = steps + 1;
        delete command;
    }
}