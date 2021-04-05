
#include <cassert>
#include "C:\Users\Maria\Desktop\a45-916-Maria-Popescu\Domain\DynamicArray.h"
#include "TestDomain.h"
#include "../Domain/Movie.h"


void TestMovie::test_getters() {
    Movie movie = Movie(12, "Title 1", "some link", "comedy drama", 1900, 40500);
    //Id
    assert(movie.getId() == 12);
    //Link
    assert(movie.getLink() == "some link");
    //Likes
    assert(movie.getLikes() == 40500);
    //Genre
    assert(movie.getGenre() == "comedy drama");
    //Title
    assert(movie.getTitle() == "Title 1");
    //Year
    assert(movie.getYear() == 1900);
}

void TestMovie::test_setters() {
    Movie movie = Movie(14, "Title", "my link", "teenage love", 2019, 4000);
    // Likes
    movie.setLikes(1000);
    assert(movie.getLikes() == 1000);
    // Title
    movie.setTitle("new title");
    assert(movie.getTitle() == "new title");
    // Link
    movie.setLink("new link");
    assert(movie.getLink() == "new link");
    //Genre
    movie.setGenre("new genre");
    assert(movie.getGenre() == "new genre");
    //Year
    movie.setYear(1900);
    assert(movie.getYear() == 1900);

    // Likes
    movie.setLikes(-444);
    assert(movie.getLikes() == -444);
    // Title
    movie.setTitle(" ");
    assert(movie.getTitle() == " ");
    // Link
    movie.setLink("asdfghjkl;09876re");
    assert(movie.getLink() == "asdfghjkl;09876re");
    //Genre
    movie.setGenre("987654");
    assert(movie.getGenre() == "987654");
    //Year
    movie.setYear(-666666);
    assert(movie.getYear() == -666666);

}

TestMovie::TestMovie() = default;

TestMovie::~TestMovie() = default;


void TestMovie::test_toString() {
    Movie movie = Movie(12, "Title", "link", "genre", 1900, 3000);
    std::string check_string = "Movie id: 12 \n      title: Title \n      genre: genre \n      year: 1900 \nlikes: 3000 \n      link: link\n";
    assert(movie.toString() != check_string);
    assert(typeid(movie.toString()) == typeid(check_string));

}

void TestMovie::test_toStringWithoutLink() {
    Movie movie = Movie(12, "Title", "link", "genre", 1900, 3000);
    std::string check_string = "Movie id: 12 \n      title: Title \n      genre: genre \n      year: 1900 \nlikes: 3000 \n      link: link\n";
    assert(movie.toStringWithoutLink() != check_string);
    assert(typeid(movie.toStringWithoutLink()) == typeid(check_string));

}
void TestMovie::test_all() {
    test_getters();
    test_setters();
    test_toString();
    test_toStringWithoutLink();
}




//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

TestDynamicArray::TestDynamicArray() = default;

TestDynamicArray::~TestDynamicArray() = default;

void TestDynamicArray::testSize() {
    DynamicArray<int> da = DynamicArray<int>(5);
    assert(da.size() == 0);
    da.push(7);
    assert(da.size() == 1);
    da.push(8);
    assert(da.size() == 2);
}

void TestDynamicArray::testPush() {
    DynamicArray<int> da = DynamicArray<int>(5);
    da.push(7);
    assert(da[0] == 7);
    da.push(8);
    assert(da[1] == 8);
    da.push(9);
    assert(da[2] == 9);
    da.push(10);
    assert(da[3] == 10);
    da.push(11);
    assert(da[4] == 11);
    da.push(6);
    assert(da[5] == 6);
    da.push(5);
    assert(da[6] == 5);
    da.push(55);
    assert(da[7] == 55);

}

void TestDynamicArray::testResize() {
    DynamicArray<int> da = DynamicArray<int>(5);
    da.push(7);
    assert(da[0] == 7);
    da.push(8);
    assert(da[1] == 8);
    da.push(9);
    assert(da[2] == 9);
    da.push(10);
    assert(da[3] == 10);
    da.push(11);
    assert(da[4] == 11);
    da.push(6);
    assert(da[5] == 6);
    da.push(5);
    assert(da[6] == 5);
    da.push(55);
    assert(da[7] == 55);

    assert(da.size() == 8);

}

void TestDynamicArray::testErase() {
    DynamicArray<int> da = DynamicArray<int>(5);
    da.push(7);
    assert(da[0] == 7);
    da.push(8);
    assert(da[1] == 8);
    da.push(9);
    assert(da.size() == 3);
    da.erase(0);
    assert(da.size() == 2);
    assert(da[0] == 9);
}

void TestDynamicArray::testAll() {
    testErase();
    testPush();
    testSize();
    testResize();

}
