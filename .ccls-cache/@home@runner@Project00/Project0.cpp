//Cameron Garcia & Justin Crittenden
#include "MediaLibrary.h"
#include "Music.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// This program will...shit on em
void Menu(MediaLibrary&);

int main() {
  MediaLibrary songList; 
  Menu(songList);
  return 0;
}

void Menu(MediaLibrary& s){
  int choice;
  do {
    cout << " MUSIC MANAGEMENT SYSTEM \n";
    cout << setfill('-') << setw(28) << "-" << endl;
    cout << "1. DISPLAY Songs\n";
    cout << "2. ADD Song\n";
    cout << "3. DELETE Song\n";
    cout << "4. Exit\n\n";
    cout << "Enter Selection: ";
    cin >> choice;
    switch (choice){
      case 1:
        s.display();
      break;
      case 2:
        s.addSong();
        s.fileUpdate();
      break;
      case 3:
        s.deleteSong();
        s.fileUpdate();
      break;
      case 4:
       cout << "Exiting program...\n";
      return;
      default:
        cout << "You entered an invalid number.";
        cout << " Please enter a valid choice\n";
      break;
    }
 } while (choice != 4);
}