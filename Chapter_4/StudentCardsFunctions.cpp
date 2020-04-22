#include <iostream>
#include "./StudentCard.cpp"

void printStudentCardsList(StudentCardsCollection collection)
{
    int i = 1;
    StudentCard* card = collection;
    while (card != NULL) {
        cout << i++ << ". " << card->toString() << "\n";
        card = card->next;
    }
}

StudentCard* getLastStudentCard(StudentCardsCollection collection)
{
    StudentCard* card = collection;
    while (card->next != NULL) {
        card = card->next;
    }
    return card;
}

StudentCard* createStudentCard(int num, int grade)
{
    StudentCard* newCard = new StudentCard;
    newCard->num = num;
    newCard->grade = grade;
    newCard->next = NULL;
    return newCard;
}

void addStudentCardRecordToStart(StudentCardsCollection &collection, int num, int grade)
{
    StudentCard* newCard = createStudentCard(num, grade);
    newCard->next = collection;
    collection = newCard;
    newCard = NULL;
}

void addStudentCardRecordToEnd(StudentCardsCollection &collection, int num, int grade)
{
    getLastStudentCard(collection)->next = createStudentCard(num, grade);
}

void demonstrateStudentsCards4()
{
    using namespace std;

    StudentCardsCollection collection;

    StudentCard* card1 = new StudentCard;
    StudentCard* card2 = new StudentCard;
    StudentCard* card3 = new StudentCard;

    card1->num = 1001; card1->grade = 78; card1->next = card2;
    card2->num = 1002; card2->grade = 63; card2->next = card3;
    card3->num = 1003; card3->grade = 91; card3->next = NULL;

    collection = card1;
    card1 = card2 = card3 = NULL;

    addStudentCardRecordToStart(collection, 1004, 75);
    addStudentCardRecordToStart(collection, 1005, 88);

    printStudentCardsList(collection);
}