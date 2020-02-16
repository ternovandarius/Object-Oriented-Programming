//
// Created by terno on 3/25/2019.
//
#include <iostream>
#include <algorithm>
#include "Repository.h"
#include <fstream>
#include <string.h>
#include <sstream>

void Repository::addRepo(Movie &m) {}
int Repository::removeRepo(std::string &name) {}
std::vector<Movie> Repository::get_allRepo() {}
void Repository::update_by_pos_stringRepo(std::string &name, int pos, int mode) {}
void Repository::update_by_pos_intRepo(int val, int pos, int mode) {}
int Repository::get_size() {}
std::string Repository::get_one(int pos) {}
int Repository::get_likes(int pos) {}
int Repository::search_for_pos(std::string name) {}
Movie& Repository::operator[](int pos) {}
std::string Repository::get_name(int pos) {}
void Repository::update_file() {}
void Repository::read_file() {}

void CSVRepository::addRepo(Movie &m) {
    /*
     * This function adds a movie to the repo.
     */
    int ok=1;
    for(Movie i : this->movie_repo)
        if (i.get_title()==m.get_title())
            ok=0;
    if(ok==1) {
        if (this->movie_repo.size() == this->movie_repo.max_size())
            this->movie_repo.resize(this->movie_repo.size() * 2);
        this->movie_repo.emplace_back(m);
        this->update_file();
    }
}

int CSVRepository::removeRepo(std::string &name) {
    /*
     * This function removes a movie from the repo, returning 1 if the remove process was successful.
     */
    int i, pos=-1;
    for(i=0; i<this->movie_repo.size(); i++)
        if(this->movie_repo[i].get_title()==name) {
            pos = i;
            break;
        }
    if (pos!=-1) {
        this->movie_repo.erase(this->movie_repo.begin()+pos);
        this->update_file();
        return 1;
    }
    throw RepoException("No such element!\n");
    //std::remove_if(this->movie_repo.begin(), this->movie_repo.end(), [name](Movie m){return m.get_title()==name;});
}

std::vector<Movie> CSVRepository::get_allRepo() {
    /*
     * This function returns the DynamicVector object containing all the movies of the repo.
     */
    return this->movie_repo;
}

void CSVRepository::update_by_pos_stringRepo(std::string &name, int pos, int mode) {
    /*
     * This function updates the string-based fields of a movie on position pos, replacing it with the value name.
     * If mode is 1, it updates the title; if it is 2 it updates the genre; if it is 5, it updates the trailer.
     */
    if(mode==1)
        this->movie_repo[pos].set_title(name);
    else if (mode==2)
        this->movie_repo[pos].set_genre(name);
    else if (mode==5)
        this->movie_repo[pos].set_trailer(name);
    this->update_file();
}

void CSVRepository::update_by_pos_intRepo(int val, int pos, int mode) {
    /*
     * This function updates the int-based fields of a movie on position pos, replacing it with the value val.
     * If mode is 3, it updates the year of release; if it is 4, it updates the number of likes.
     */
    if(mode==3)
        this->movie_repo[pos].set_year(val);
    else if (mode==4)
        this->movie_repo[pos].set_likes(val);
    this->update_file();
}

int CSVRepository::get_size() {
    return this->movie_repo.size();
}

std::string CSVRepository::get_one(int pos) {
    return this->movie_repo[pos].to_string();
}

int CSVRepository::get_likes(int pos) {
    return this->movie_repo[pos].get_likes();
}

int CSVRepository::search_for_pos(std::string name) {
    for(int i=0; i<this->movie_repo.size(); i++)
    {
        if(this->movie_repo[i].get_title()==name)
            return i;
    }
    throw RepoException("No such position!\n");
}

Movie& CSVRepository::operator[](int pos) {
    return this->movie_repo[pos];
}

std::string CSVRepository::get_name(int pos) {
    return this->movie_repo[pos].get_title();
}

std::vector<std::string> tokenize(std::string s, char d)
{
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string tok;
    while(getline(ss, tok, d))
    {
        result.push_back(tok);
    }
    return result;
}

std::istream & operator>>(std::istream &is, Movie &m)
{
    std::string l;
    char d=',';
    getline(is, l);
    std::vector<std::string> tok=tokenize(l, d);
    if(tok.size()==5) {
        m.set_title(tok[0]);
        m.set_genre(tok[1]);
        m.set_year(stoi(tok[2]));
        m.set_likes(stoi(tok[3]));
        m.set_trailer(tok[4]);
    }
    return is;
}

std::ostream &operator<<(std::ostream & os, Movie &m)
{
    os<<m.get_title()<<","<<m.get_genre()<<","<<std::to_string(m.get_year())<<","<<std::to_string(m.get_likes())<<","<<m.get_trailer();
    return os;
}

Repository::Repository(std::vector<Movie> &v, std::string &file): movie_repo{v}{
    this->file_name=file;
    //this->read_file();
}

void CSVRepository::read_file(){
    std::ifstream f;
    f.open(this->file_name, std::ios::in);
    Movie m{};
    while(f>>m)
        this->addRepo(m);
    f.close();
}

void CSVRepository::update_file() {
    std::ofstream ofs;
    ofs.open(this->file_name, std::ofstream::out | std::ofstream::trunc);
    for (Movie i : this->movie_repo)
        ofs<<i.to_file()<<std::endl;
    ofs.close();
}

RepoException::RepoException(std::string msg) {
    this->msg=msg;
}

const char* RepoException::what() const noexcept {
    return this->msg.c_str();
}

CSVRepository::CSVRepository(std::vector<Movie> &v, std::string &file):Repository(v, file){
    this->read_file();
}

HTMLRepository::HTMLRepository(std::vector<Movie> &v, std::string &file):Repository(v, file){
    //this->read_file();
}

void HTMLRepository::update_file() {
    std::ofstream ofs;
    ofs.open(this->file_name, std::ofstream::out | std::ofstream::trunc);
    ofs<<"<!DOCTYPE html>\n<html>\n<head>\n<title>Watchlist</title>\n</head>";
    ofs<<"<body>\n<table border=\"1\">";
    ofs<<"<tr>\n"
         "<td>Artist</td>\n<td>Title</td>\n<td>Duration</td>\n<td>Youtube link</td>\n</tr>";
    for(Movie i: this->movie_repo)
    {
        ofs<<"<tr>\n";
        ofs<<"<td>"<<i.get_title()<<"</td>\n";
        ofs<<"<td>"<<i.get_genre()<<"</td>\n";
        ofs<<"<td>"<<std::to_string(i.get_year())<<"</td>\n";
        ofs<<"<td>"<<std::to_string(i.get_likes())<<"</td>\n";
        ofs<<"<td><a href="<<i.get_trailer()<<">Link</a></td>\n";
        ofs<<"</tr>\n";
    }
    ofs<<"</table>\n</body>\n</html>";
    ofs.close();
}
void HTMLRepository::addRepo(Movie &m) {
    /*
     * This function adds a movie to the repo.
     */
    int ok=1;
    for(Movie i : this->movie_repo)
        if (i.get_title()==m.get_title())
            ok=0;
    if(ok==1) {
        if (this->movie_repo.size() == this->movie_repo.max_size())
            this->movie_repo.resize(this->movie_repo.size() * 2);
        this->movie_repo.emplace_back(m);
        this->update_file();
    }
}

int HTMLRepository::removeRepo(std::string &name) {
    /*
     * This function removes a movie from the repo, returning 1 if the remove process was successful.
     */
    int i, pos=-1;
    for(i=0; i<this->movie_repo.size(); i++)
        if(this->movie_repo[i].get_title()==name) {
            pos = i;
            break;
        }
    if (pos!=-1) {
        this->movie_repo.erase(this->movie_repo.begin()+pos);
        this->update_file();
        return 1;
    }
    throw RepoException("No such element!\n");
    //std::remove_if(this->movie_repo.begin(), this->movie_repo.end(), [name](Movie m){return m.get_title()==name;});
}

std::vector<Movie> HTMLRepository::get_allRepo() {
    /*
     * This function returns the DynamicVector object containing all the movies of the repo.
     */
    return this->movie_repo;
}

void HTMLRepository::update_by_pos_stringRepo(std::string &name, int pos, int mode) {
    /*
     * This function updates the string-based fields of a movie on position pos, replacing it with the value name.
     * If mode is 1, it updates the title; if it is 2 it updates the genre; if it is 5, it updates the trailer.
     */
    if(mode==1)
        this->movie_repo[pos].set_title(name);
    else if (mode==2)
        this->movie_repo[pos].set_genre(name);
    else if (mode==5)
        this->movie_repo[pos].set_trailer(name);
    this->update_file();
}

void HTMLRepository::update_by_pos_intRepo(int val, int pos, int mode) {
    /*
     * This function updates the int-based fields of a movie on position pos, replacing it with the value val.
     * If mode is 3, it updates the year of release; if it is 4, it updates the number of likes.
     */
    if(mode==3)
        this->movie_repo[pos].set_year(val);
    else if (mode==4)
        this->movie_repo[pos].set_likes(val);
    this->update_file();
}

int HTMLRepository::get_size() {
    return this->movie_repo.size();
}

std::string HTMLRepository::get_one(int pos) {
    return this->movie_repo[pos].to_string();
}

int HTMLRepository::get_likes(int pos) {
    return this->movie_repo[pos].get_likes();
}

int HTMLRepository::search_for_pos(std::string name) {
    for(int i=0; i<this->movie_repo.size(); i++)
    {
        if(this->movie_repo[i].get_title()==name)
            return i;
    }
    throw RepoException("No such position!\n");
}

Movie& HTMLRepository::operator[](int pos) {
    return this->movie_repo[pos];
}

std::string HTMLRepository::get_name(int pos) {
    return this->movie_repo[pos].get_title();
}