#ifndef TESTDOMAIN_H
#define TESTDOMAIN_H
class TestMovie {
private:
    ///Description
    /// Function for testing the getters from the class Movie
    ///The getters:
    ///  ->getId()
    ///  ->getTitle()
    ///  ->getLikes()
    ///  ->getGenre()
    ///  ->getLink()
    ///  ->getYear()
    static void test_getters();

    ///Description
    /// Function for testing the setters from the class Movie
    ///The setters:
    ///  ->setTitle()
    ///  ->setLikes()
    ///  ->setGenre()
    ///  ->setLink()
    ///  ->setYear()
    static void test_setters();

    static void test_toString();
    static void test_toStringWithoutLink();

public:
    ///Description
    ///Constructor for the class TestMovie (default)
    TestMovie();

    ///Description
    ///Deconstruct for the class TestMovie
    ~TestMovie();

    ///Description
    ///Function for testing all the functionalities of the class Movie
    /// calls the functions : -> TestSetters
    ///                       -> TestGetters
    static void test_all();
};


class TestDynamicArray{
private:
    static void testSize();
    static void testPush();
    static void testResize();
    static void testErase();

public:
    ///
    TestDynamicArray();

    ///
    ~TestDynamicArray();

    ///
    static void testAll();

};
#endif //TESTDOMAIN_H
