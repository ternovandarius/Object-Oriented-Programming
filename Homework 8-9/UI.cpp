//
// Created by terno on 3/25/2019.
//

#include "UI.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <shellapi.h>

void UI::run()
{
    int ok_mode=0;
    while (ok_mode==0) {
        int ok = 0;
        std::cout << "1. Administrator mode.\n2. User mode.\n3. Exit.";
        int x;
        std::cin >> x;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            x = 0;
        }
        if (x == 1) {
            while (ok == 0) {
                std::cout
                        << "--ADMINISTRATOR MODE--\n1.Add a movie\n2.Remove a movie.\n3.Display all movies.\n4.Update a movie.\n5.Lab 5 in-lab assignment (adds two entries of an element).\n6.Display sorted.\n7.Back to menu.";
                int y;
                std::cin >> y;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    y = 0;
                }
                if (y == 1) {
                    std::string title;
                    std::string genre;
                    std::string year1;
                    std::string likes1;
                    int year;
                    int likes;
                    std::string trailer;
                    std::cin.ignore();
                    std::cout << "Please input the title of the movie.";
                    getline(std::cin, title);
                    std::cout << "Please input the genre of the movie.";
                    getline(std::cin, genre);
                    std::cout << "Please input the year of release of the film.";
                    std::cin >> year;
                    std::cout << "Please input the number of likes of the movie.";
                    std::cin >> likes;
                    std::cout << "Please input the link for the trailer of the movie.";
                    std::cin.ignore();
                    getline(std::cin, trailer);
                    this->ctrl.addController(title, genre, year, likes, trailer);
                } else if (y == 2) {
                    std::string name;
                    std::cout << "Please input the title of the movie you want to remove.";
                    std::cin.ignore();
                    getline(std::cin, name);
                    try {
                        int z = this->ctrl.removeController(name);
                    } catch (RepoException e) {
                        std::cout << e.what();
                    }
                } else if (y == 3) {
                    Repository *t = this->ctrl.get_repo();
                    for (int i = 0; i < t->get_size(); i++)
                        std::cout << t->get_one(i) << "\n";
                } else if (y == 4) {
                    std::cout << "Please insert the title of the movie you want to update.\n";
                    std::string title;
                    std::cin.ignore();
                    getline(std::cin, title);
                    Repository *t = this->ctrl.get_repo();
                    try {
                        int pos = t->search_for_pos(title);
                        std::cout
                                << "--UPDATE MENU--\n1.Update title.\n2.Update genre.\n3.Update year.\n4.Update likes.\n5.Update trailer.";
                        int z;
                        std::cin >> z;
                        if (z == 1 || z == 2 || z == 5) {
                            std::string new_param;
                            std::cout << "Please enter the new value.";
                            std::cin.ignore();
                            getline(std::cin, new_param);
                            this->ctrl.update_by_pos_stringController(new_param, pos, z);
                        } else if (z == 3 || z == 4) {
                            int new_param;
                            std::cout << "Please enter the new value.";
                            std::cin >> new_param;
                            this->ctrl.update_by_pos_intController(new_param, pos, z);
                        }
                    } catch (RepoException &e) {
                        std::cout << e.what();
                    }
                } else if (y == 7)
                    ok = 1;
                else if (y == 5) {
                    std::string title;
                    std::string genre;
                    std::string year1;
                    std::string likes1;
                    int year;
                    int likes;
                    std::string trailer;
                    std::cin.ignore();
                    std::cout << "Please input the title of the movie.";
                    getline(std::cin, title);
                    std::cout << "Please input the genre of the movie.";
                    getline(std::cin, genre);
                    std::cout << "Please input the year of release of the film.";
                    std::cin >> year;
                    std::cout << "Please input the number of likes of the movie.";
                    std::cin >> likes;
                    std::cout << "Please input the link for the trailer of the movie.";
                    std::cin.ignore();
                    getline(std::cin, trailer);
                    this->ctrl.lab5Controller(title, genre, year, likes, trailer);
                } else if (y == 6)
                {
                    std::cout<<"1.Sorted by ascending year.\n2.Sorted by descending title.\n";
                    int g;
                    std::cin>>g;
                    if(std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore();
                        g=0;
                        std::cout<<"Invalid command!\n";
                    }
                    if(g==1)
                    {
                        std::vector<Movie> m=this->ctrl.getAllController();
                        Compare *c=new CompareAscendingByYear();
                        ctrl.compare(m, c);
                    }
                    else if (g==2)
                    {
                        std::vector<Movie> m=this->ctrl.getAllController();
                        Compare *c=new CompareDescendingByTitle();
                        ctrl.compare(m, c);
                    }
                }else
                    std::cout << "Invalid command!\n";
            }
        }
        else if (x == 2)
            while (ok == 0) {
                std::cout
                        << "\n--USER MODE--\n1.See all movies of a specific genre.\n2.Delete a movie from the watchlist.\n3.See the watchlist.\n4.See watchlist in format.\n5.Back to menu.";
                int y;
                std::cin >> y;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    y = 0;
                }
                if (y == 1) {
                    std::string genre;
                    std::cout << "Please insert the desired genre.\n";
                    std::cin.ignore();
                    getline(std::cin, genre);
                    this->ctrl.initiateIterator(genre);
                    this->ctrl.iterate();
                    int ok2 = 0;
                    while (ok2 == 0) {
                        std::cout << "\n1.Add to watchlist.\n2.Don't add to watchlist.\n3.Exit iterator.\n";
                        int z;
                        std::cin >> z;
                        if (z == 1) {
                            Movie m = this->ctrl.get_current();
                            this->ctrl.addWatchlist(m);
                            this->ctrl.next();
                        } else if (z == 2) {
                            this->ctrl.next();
                        }
                        if (z == 3)
                            ok2 = 1;
                    }
                } else if (y == 2) {
                    std::string name;
                    std::cout << "Please insert the name of the movie you want to delete. ";
                    std::cin.ignore();
                    getline(std::cin, name);
                    int z;
                    try {
                        z = this->ctrl.deleteWatchlist(name);
                        std::cout << "\nDid you like this movie?\n1.Yes\n2.No";
                        int l;
                        std::cin >> l;
                        if (l == 1) {
                            Repository *t = this->ctrl.get_repo();
                            int pos = t->search_for_pos(name);
                            int new_l;
                            int mode = 4;
                            new_l = t->get_likes(pos);
                            new_l++;
                            this->ctrl.update_by_pos_intController(new_l, pos, mode);
                        }
                    } catch (RepoException &e) {
                        std::cout << e.what();
                    }
                } else if (y == 3) {
                    Repository *t = this->ctrl.get_watchlist();
                    for (int i = 0; i < t->get_size(); i++)
                        std::cout << t->get_one(i) << "\n";
                } else if (y == 4){
                    if(this->mode==1)
                        ShellExecuteA(NULL, NULL, "notepad.exe", this->file_name.c_str(), NULL, SW_SHOWMAXIMIZED);
                    else {
                        std::string link = "http://localhost:63342/Assignment5_6/cmake-build-debug/" + this->file_name;
                        ShellExecuteA(NULL, NULL, "chrome.exe", link.c_str(), NULL, SW_SHOWMAXIMIZED);
                    }
                } else if (y == 5)
                    ok = 1;
                else
                    std::cout<<"Invalid command!";
            }
        else if (x==3)
            ok_mode=1;
        else
            std::cout<<"Invalid command!";
    }
}
