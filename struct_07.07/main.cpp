#include <iostream>
#include <string>

using namespace std;

const int MAX_MOVIES = 100;

struct VideoStore {
    string movieName;
    string director;
    string genre;
    int popularityRating;
    double price;
    int quantity;
};

int movieCount = 0;
VideoStore store[MAX_MOVIES];

void addMovie(const VideoStore& movie) {
    if (movieCount < MAX_MOVIES) {
        store[movieCount++] = movie;
    }
    else {
        cout << "Storage is full" << endl;
    }
}

void showMovies() {
    for (int i = 0; i < movieCount; ++i) {
        cout << "Film name: " << store[i].movieName << endl;
        cout << "Director: " << store[i].director << endl;
        cout << "Genre: " << store[i].genre << endl;
        cout << "Rating: " << store[i].popularityRating << endl;
        cout << "Price: " << store[i].price << endl;
        cout << "Amount of disks: " << store[i].quantity << endl;
        cout << "------------------------" << endl;
    }
}

void searchByTitle(const string& title) {
    bool found = false;
    for (int i = 0; i < movieCount; ++i) {
        if (store[i].movieName == title) {
            cout << "Film nem: " << store[i].movieName << endl;
            cout << "Director: " << store[i].director << endl;
            cout << "Genre: " << store[i].genre << endl;
            cout << "Rating: " << store[i].popularityRating << endl;
            cout << "Price: " << store[i].price << endl;
            cout << "Amount of discs: " << store[i].quantity << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Your film are not found." << endl;
    }
}

void searchByGenre(const string& genre) {
    bool found = false;
    for (int i = 0; i < movieCount; ++i) {
        if (store[i].genre == genre) {
            cout << "Film name: " << store[i].movieName << endl;
            cout << "Director: " << store[i].director << endl;
            cout << "Genre: " << store[i].genre << endl;
            cout << "Rating: " << store[i].popularityRating << endl;
            cout << "Price: " << store[i].price << endl;
            cout << "Amount of discs: " << store[i].quantity << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "films with this genre are not found." << endl;
    }
}

void searchByDirector(const string& director) {
    bool found = false;
    for (int i = 0; i < movieCount; ++i) {
        if (store[i].director == director) {
            cout << "Name film: " << store[i].movieName << endl;
            cout << "Director: " << store[i].director << endl;
            cout << "Genre: " << store[i].genre << endl;
            cout << "Rating: " << store[i].popularityRating << endl;
            cout << "Price: " << store[i].price << endl;
            cout << "Amount of discs: " << store[i].quantity << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Films by this director are not found." << endl;
    }
}

void getMostPopularMovieInGenre(const string& genre) {
    int maxRating = -1;
    int index = -1;
    for (int i = 0; i < movieCount; ++i) {
        if (store[i].genre == genre && store[i].popularityRating > maxRating) {
            maxRating = store[i].popularityRating;
            index = i;
        }
    }
    if (index != -1) {
        cout << "Most popular film with this genre " << genre << ":" << endl;
        cout << "Name film: " << store[index].movieName << endl;
        cout << "Director: " << store[index].director << endl;
        cout << "Genre: " << store[index].genre << endl;
        cout << "Rating: " << store[index].popularityRating << endl;
        cout << "Price: " << store[index].price << endl;
        cout << "Amount of discs: " << store[index].quantity << endl;
        cout << "------------------------" << endl;
    }
    else {
        cout << "Films in " << genre << " are not found." << endl;
    }
}

int main() {
    VideoStore movie1 = { "HARRY POTTER AND THE SORCERER'S STONE", "Chris Columbus", "fantasy", 85, 10.5, 5 };
    VideoStore movie2 = { "The Lord of the Rings", "Peter Jackson", "Adventures", 90, 15.0, 3 };
    VideoStore movie3 = { "Inglorious bastards", "Quentin Tarantino", "Militants", 75, 12.0, 2 };

    addMovie(movie1);
    addMovie(movie2);
    addMovie(movie3);

    cout << "ALL FILMS:" << endl;
    showMovies();

    string searchTitle = "Name1";
    cout << "Search by name: " << searchTitle << endl;
    searchByTitle(searchTitle);

    string searchGenre = "Genre1";
    cout << "Search by Genre: " << searchGenre << endl;
    searchByGenre(searchGenre);

    string searchDirector = "Director1";
    cout << "Search by Director: " << searchDirector << endl;
    searchByDirector(searchDirector);

    string genre = "Genre1";
    cout << "Most popular film by genre: " << genre << endl;
    getMostPopularMovieInGenre(genre);


	system("pause");
	return 0;
}