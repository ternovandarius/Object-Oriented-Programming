#pragma once
#include <cstring>
#include "DynamicVector.h"

class Movie
{
private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;
public:
    Movie();
    Movie(const std::string &title, const std::string &genre, const int &year, const int &likes, const std::string &trailer);
    std::string get_title();
    std::string get_genre();
    int get_year();
    int get_likes();
    std::string get_trailer();
    std::string to_string();
    void set_title(std::string new_title);
    void set_genre(std::string new_genre);
    void set_year(int new_year);
    void set_likes(int new_likes);
    void set_trailer(std::string new_trailer);
    void display();
};

void test_movie();