#include <iostream>
#include "UI.cpp"


void test_all()
{
    test_movie();
    test_dynamicvector();
    test_repository();
    test_iterator();
    test_controller();
}

int main() {
    test_all();
    Iterator i;
    DynamicVector<Movie> v;
    DynamicVector<Movie> v2;
    Repository r{v};
    Repository w{v2};
    Controller c{r, w, i};
    c.addController("The Room", "Drama", 2003, -20, "https://www.youtube.com/watch?v=9-dIdFXeFhs");
    c.addController("Birdemic: Shock and Terror", "Action", 2010, -50, "https://www.youtube.com/watch?v=jE5dJDgZ644");
    c.addController("The Godfather", "Drama", 1972, 2000, "https://www.youtube.com/watch?v=sY1S34973zA");
    c.addController("Star Wars IV: A New Hope", "Science Fiction", 1977, 1500, "https://www.youtube.com/watch?v=9gvqpFbRKtQ");
    c.addController("The Lord of the Rings: The Fellowship of the Ring", "Fantasy", 2002, 3000, "https://www.youtube.com/watch?v=Pki6jbSbXIY");
    c.addController("Harry Potter and the Philosopher's Stone", "Fantasy", 2001, 1000, "https://www.youtube.com/watch?v=eKSB0gXl9dw");
    c.addController("Ocean's Eleven", "Thriller", 2001, 5000, "https://www.youtube.com/watch?v=imm6OR605UI");
    c.addController("Now You See Me", "Thriller", 2013, 500, "https://www.youtube.com/watch?v=4OtM9j2lcUA");
    c.addController("Interstellar", "Science Fiction", 2014, 4000, "https://www.youtube.com/watch?v=zSWdZVtXT7E");
    c.addController("John Wick", "Action", 2014, 5000, "https://www.youtube.com/watch?v=2AUmvWm5ZDQ");
    UI ui(c);
    ui.run();
}