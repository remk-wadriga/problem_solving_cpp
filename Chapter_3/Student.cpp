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

Student students[10] = {
    {87, 10001, "Fred"},
    {28, 10010, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10006, "Erin"},
    {98, 10005, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10002, "Veronica"}
};