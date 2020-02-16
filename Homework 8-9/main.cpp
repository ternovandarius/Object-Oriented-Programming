#include <iostream>
#include "UI.cpp"


void test_all()
{
    //test_movie();
    //test_dynamicvector();
    //test_repository();
    //test_iterator();
    //test_controller();
}

int main() {
    //test_all();
    Iterator i;
    std::vector<Movie> v1;
    std::vector<Movie> vector;
    std::string file1="a.txt";
    Repository* r=NULL;
    Repository* w=NULL;
    int ok_file=0;
    while(ok_file==0)
    {
        std::cout<<"Please select your desired file type for the watchlist:\n1.CSV\n2.HTML\n3.Exit program.";
        int x;
        std::cin>>x;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            x=0;
        }
        if(x==1)
        {
            std::string file2="b.csv";
            CSVRepository w1{vector, file2};
            w=&w1;
            CSVRepository r1{v1, file1};
            r=&r1;
            ok_file=1;
            Controller c{r, w, i};
            UI ui(c, file2, x);
            ui.run();
        }
        else if(x==2)
        {
            std::string file2="b.html";
            HTMLRepository w1{vector, file2};
            w=&w1;
            CSVRepository r1{v1, file1};
            r=&r1;
            ok_file=1;
            Controller c{r, w, i};
            UI ui(c, file2, x);
            ui.run();
        }
        else{
            std::cout<<"Invalid command!\n";
        }
    }
}