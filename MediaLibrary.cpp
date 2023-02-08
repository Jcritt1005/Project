//Cameron Garcia & Justin Crittenden
#include "MediaLibrary.h"

//************************************************
//  MediaLibrary() constuctor: creates and       *
//  populates a dynamic array of Music objects   *
//************************************************
MediaLibrary::MediaLibrary() {
  string tempString;            //Counts lines in file
  dataIn.open("Songs.txt");
  if(!dataIn)                   // Error check
    cout << "Could not open file\n";
  while (!dataIn.eof()) {      // Read until end of file
    getline(dataIn,tempString);
    count++;
    }
  songs = new Music[count];
  dataIn.close();
  readFile();
}

//************************************************ 
//  addSong() function: Adds songs to the Array  *    
//************************************************    
void MediaLibrary :: addSong() {
  string tSong;          // Temporary song
  string tArtist;        // Temporary artist
  string tAlbum;         // Temporary album
  string tYear;          // Temporary year
  Music addEntry;        // Entry to be added
  bool verify = false;   // True for valid year

  // Allocate a new array
  temp = new Music[count];
  for (int i = 0; i < count; i++) {
    temp[i] = songs[i];
  }
  delete[] songs;
  songs = new Music[count+1];
  for (int i = 0; i < count; i++) {
    songs[i] = temp[i];
  }
  cin.ignore();
  
  // Prompt for next entry
  cout << "\nPlease enter the title of the song: ";    // FIX: make
  getline(cin,tSong);                                  // into a menu
  addEntry.setName(tSong);                             // function
  
  cout << "\nPlease enter the artist of the song: ";
  getline(cin,tArtist);
  addEntry.setArtist(tArtist);

  cout << "\nPlease enter the album of the song: ";
  getline(cin,tAlbum);
  addEntry.setAlbum(tAlbum);

  cout << "\nPlease enter the year released: ";
  while (verify == false) {
    getline(cin,tYear);
    for (int i = 0; i < tYear.length(); i++) {
      if (isalpha(tYear[i]) || ispunct(tYear[i])){
        cout << "You entered an invalid year\n";
        cout << "Please enter a 4-digit year: ";
        break;    // Needed to break from the
      }
      else if (tYear.length() != 4) {
        cout << "You entered an invalid year\n";
        cout << "Please enter a 4-digit year: ";
        break;
      }
      else if (tYear.length() == 4 && isdigit(tYear[i]) && i == 3) {
        verify = true;
        break;
      }
    }
  }
  cout << endl << tSong << " has been added to the list.\n\n";
  addEntry.setYear(tYear);
  songs[count] = addEntry;
  count++;
  delete[] temp;
}

//************************************************
//  deleteSong() function: Deletes songs from    *  FIX: Add a menu
//************************************************  
void MediaLibrary :: deleteSong() {
  int choice;
  cout << "Enter the number of the song";
  cout << " you would like to delete: ";
  
  do {
  cin >> choice;
  if (choice > count) 
    cout << "You reached out of bounds please try again\n";
    } while (choice > count);
    
  temp = new Music[count];
  for (int i = 0; i < count; i++) {
    temp[i] = songs[i];
  }
  delete[] songs;
  songs = new Music[count-1];
  int j = 0;
  // Filling new array
    for (int i = 0; i < count; i++){
      if (i + 1  != choice){
        songs[j] = temp[i];
        j++;
      }
    }
  cout << endl << temp[choice - 1].getName() << 
  " has been deleted from the list.\n\n";
  cin.ignore();
  count--;
  delete[] temp;
}

//************************************************
//  readFile() function: Reads from text file    *
//************************************************
void MediaLibrary :: readFile() {
   dataIn.open("Songs.txt");
  for (int i = 0; i < count; i++) {
    getline(dataIn,tempName,'%');
    getline(dataIn,tempArtist,'%');
    getline(dataIn,tempAlbum,'%');
    getline(dataIn,tempYear);
    songs[i].setName(tempName);
    songs[i].setArtist(tempArtist);
    songs[i].setAlbum(tempAlbum);
    songs[i].setYear(tempYear);
    }
  dataIn.close();
}

//************************************************
//  display() function: Displays list of songs   *
//************************************************
void MediaLibrary::display() {
  cout << endl;
  cout << setfill(' ') << "    TITLE";
  cout << setw(33) << right << "ARTIST\n";
  cout << setw(46) << setfill('*') << " \n";
  cout << setfill(' ');
  //cout << setfill(' ') << "   *******";
  //cout << setw(32) << right << "********\n";
  for (int i = 0; i < count; i++) {
    cout << setw(3) << right << i + 1 << "."; 
    cout << setw(30) << left << songs[i].getName() << " ";
    cout << setw(25) << left << songs[i].getArtist() << endl;
  }
  cout << endl;
}
//************************************************
//  fileUpdate() function: Updates Entries in    *
//  Songs.txt                                    *
//************************************************
void MediaLibrary::fileUpdate() {           
  dataOut.open("Songs.txt");              
  for (int i = 0; i < count; i++) {
    dataOut << songs[i].getName() << "%";
    dataOut << songs[i].getArtist() << "%";
    dataOut<< songs[i].getAlbum() << "%";
    dataOut<< songs[i].getYear();
    if(i == count - 1) {
      dataOut.close();
    }
    else {
      dataOut << endl;
    }
  }
  dataOut.close();
}