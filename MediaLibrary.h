//Cameron Garcia & Justin Crittenden
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Music.h"
#include <iomanip>
#ifndef MEDIALIBRARY_H
#define MEDIALIBRARY_H
using namespace std;

class MediaLibrary
{
private:
Music* songs = nullptr;   // Dynamic array used to carry songs info
Music* temp = nullptr;    // Temporary array used to make changes
ifstream dataIn;          // Infile stream
ofstream dataOut;         // Outfile stream
string tempName;          //Temporarily holds title
string tempArtist;        //Temporarily holds artist
string tempAlbum;         //Temporarily holds album
string tempYear;          //Temporarily holds year
int count = 0;
public:
// Default Constructor
MediaLibrary();
// Adding method
void addSong();
// Deleting method
void deleteSong();
// Reads file
void readFile();
// Displays song list
void display();
// Updates File
void fileUpdate();
};
#endif