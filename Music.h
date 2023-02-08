//Cameron Garcia & Justin Crittenden
#include <string>
#include <iostream>
#ifndef MUSIC_H
#define MUSIC_H
using namespace std;

class Music {
private:
  string name;    // Retains the name of the song
  string album;   // Retains the name of the album
  string artist;  // Retains the name of the artist
  string year;    // Retains the year

public:
Music() {         // Default Constructor
  name = " ";
  album = " ";
  artist = " ";
  year = " ";
}
// Mutator methods
void setName(string nam)
{name = nam;}
void setAlbum(string alb)
{album = alb;}
void setArtist(string art)
{artist = art;}
void setYear(string yr)
{year = yr;}
// Accessor methods
string getName()
{return name;}
string getAlbum()
{return album;}
string getArtist()
{return artist;}
string getYear()
{return year;} 
}; 
#endif