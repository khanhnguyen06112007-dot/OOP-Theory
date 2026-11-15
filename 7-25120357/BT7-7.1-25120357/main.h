#pragma
//1
class Square{};
class Rectangle{};
class Square : public Rectangle{};
//2
class Polygon{};
class Edge{};
class Polygon{
private:
    Edge *edges;
};
//3
class Manager{};
class Employee{};
class Manager : public Employee{};
//4 
class Circle{};
class Ellipse{};
class Circle : public Ellipse{};
//5
class Airplane{};
class Engine{};
class Airplane{
private:
    Engine *eng;
};
//6
class Sentence{};
class Word{};
class Sentence{
private:
    Word* word;
};
//7
class Cosmetic{};
class Goods{};
class Cosmetic : public Goods{};
//8
class Rice{};
class Food{};
class Rice : public Food{};
//9
class Library{};
class Book{};
class Library{
private:
    Book *book;
};
//10
class Cartoon{};
class Movie{};
class Cartoon : public Movie{};


