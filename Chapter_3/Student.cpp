struct Student {
    int ID;
    int grade;
    std::string name;

    std::string toString(std::string sep = "\n")
    {
        using namespace std;
        return "ID: " + to_string(ID) + sep +
            "Name: " + name + sep +
            "Grade: " + to_string(grade);
    }
};