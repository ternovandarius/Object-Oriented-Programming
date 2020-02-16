//
// Created by terno on 3/25/2019.
//

#include "Domain.h"
#include <windows.h>
#include <assert.h>
#include <shellapi.h>

Movie::Movie() {
    this->title="";
    this->genre="";
    this->year=0;
    this->likes=0;
    this->trailer="";
}

Movie::Movie(const std::string &title, const std::string &genre, const int &year, const int &likes, const std::string &trailer){
    this->title=title;
    this->genre=genre;
    this->year=year;
    this->likes=likes;
    this->trailer=trailer;
}
std::string Movie::get_title() {
    return this->title;
}
std::string Movie::get_genre() {
    return this->genre;
}
int Movie::get_year() {
    return this->year;
}
int Movie::get_likes() {
    return this->likes;
}
std::string Movie::get_trailer() {
    return this->trailer;
}
std::string Movie::to_string() {
    std::string t;
    t="Title: "+this->title+", Genre: "+this->genre+", Year of Release: "+std::to_string(this->year)+", Likes: "+std::to_string(this->likes)+", Trailer: "+this->trailer;
    return t;
}

void Movie::set_title(std::string new_title)
{
    this->title=new_title;
}

void Movie::set_genre(std::string new_genre)
{
    this->genre=new_genre;
}

void Movie::set_year(int new_year)
{
    this->year=new_year;
}

void Movie::set_likes(int new_likes)
{
    this->likes=new_likes;
}

void Movie::set_trailer(std::string new_trailer)
{
    this->trailer=new_trailer;
}

void Movie::display() {
    ShellExecuteA(NULL, NULL, "chrome.exe", this->get_trailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void test_movie()
{
    Movie m;
    assert(m.get_title()=="");
    m.set_title("TEST");
    assert(m.get_title()=="TEST");
    m.set_genre("GENRE");
    assert(m.get_genre()=="GENRE");
    m.set_likes(10);
    assert(m.get_likes()==10);
    m.set_year(2004);
    assert(m.get_year()==2004);
    m.set_trailer("www");
    assert(m.get_trailer()=="www");
    assert(m.to_string()=="Title: TEST, Genre: GENRE, Year of Release: 2004, Likes: 10, Trailer: www");
}