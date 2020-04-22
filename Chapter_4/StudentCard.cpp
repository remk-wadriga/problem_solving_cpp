
struct StudentCard {
    int num;
    int grade;
    StudentCard* next;

    std::string toString(std::string sep = "; ")
    {
        using namespace std;
        return "Num: " + to_string(num) + sep + "Grade: " + to_string(grade);
    }
};

typedef StudentCard* StudentCardsCollection;