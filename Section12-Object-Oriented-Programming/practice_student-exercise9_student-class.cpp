#include <iostream>
#include <string>
#include <map>

class Student
{
private:
    std::string name;
    int roll;
    std::map<std::string, int> mark_list;

public:
    Student(std::string name, int roll, std::map<std::string, int> mark_list)
    {
        this->name = name;
        this->roll = roll;
        this->mark_list = mark_list;
    }

    // Accessors
    std::string get_name() { return this->name; }
    int get_roll() { return this->roll; }
    std::map<std::string, int> get_marklist() { return this->mark_list; }

    // Mutators
    void set_name(std::string name) { this->name = name; }
    void set_roll(int roll) { this->roll = roll; }
    void set_marklist(std::map<std::string, int> mark_list) { this->mark_list = mark_list; }

    // Calculators
    int get_totalmarks();
    std::map<std::string, char> get_grades();
};
int Student::get_totalmarks()
{
    auto mark_list = this->mark_list;
    int total = 0;

    for (auto itr = mark_list.begin(); itr != mark_list.end(); ++itr)
    {
        total += itr->second;
    }

    return total;
}
std::map<std::string, char> Student::get_grades()
{
    int marks = this->get_totalmarks();

    auto mark_list = this->mark_list;

    std::map<std::string, char> grade_list;
    char overall_grade;

    auto ml_itr = mark_list.begin();

    for (ml_itr; ml_itr != mark_list.end(); ++ml_itr)
    {
        grade_list.insert({ml_itr->first, NULL});

        if (ml_itr->second >= 90)
            grade_list[ml_itr->first] = 'A';
        else if (ml_itr->second >= 75)
            grade_list[ml_itr->first] = 'B';
        else if (ml_itr->second >= 50)
            grade_list[ml_itr->first] = 'C';
        else if (ml_itr->second >= 25)
            grade_list[ml_itr->first] = 'D';
        else
            grade_list[ml_itr->first] = 'F';
    }

    return grade_list;
}

int main()
{
    std::map<std::string, int> s1_marklist = {
        {"Math", 93},
        {"Science", 96},
        {"English", 72},
        {"French", 35},
        {"History", 89},
        {"Geography", 99},
        {"Politics", 100}
    };

    Student s1 = Student("Johnny Appleseed", 29, s1_marklist);
    auto s1_gradelist = s1.get_grades();

    for (auto itr = s1_gradelist.begin(); itr != s1_gradelist.end(); ++itr)
        std::cout << itr->first << ": " << itr->second << std::endl;
    
    s1.set_name("Jack Brown");
    s1.set_roll(31);
    std::cout << s1.get_name() << ": Roll " << s1.get_roll() << std::endl;

    return 0;
}