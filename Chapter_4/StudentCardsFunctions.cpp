#include <iostream>
#include "./StudentCard.cpp"

typedef StudentCard* StudentCardsCollection;

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
    while (card != NULL && card->next != NULL) {
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
    StudentCard* lastRecord = getLastStudentCard(collection);
    if (lastRecord == NULL) {
        collection = createStudentCard(num, grade);
    } else {
        lastRecord->next = createStudentCard(num, grade);
    }
}

double averageStudentCardGrade(StudentCardsCollection collection)
{
    double sum = 0.0, count = 0.0;
    StudentCard* card = collection;
    while (card != NULL) {
        sum += card->grade;
        count++;
        card = card->next;
    }
    return count > 0 ? sum / count : 0.0;
}

void removeStudentCard(StudentCardsCollection &collection, int index)
{
    StudentCard* currentCard = collection;
    StudentCard* lastCard = NULL;
    StudentCard* firstCard = NULL;

    if (index == 0) {
        firstCard = currentCard != NULL ? currentCard->next : NULL;
        delete currentCard;
        collection = firstCard;
        return;
    }

    int number = 0;
    while (currentCard != NULL && lastCard == NULL) {
        if (number++ == index - 1) {
            lastCard = currentCard;
        }
        currentCard = currentCard->next;
    }

    if (lastCard == NULL || lastCard->next == NULL) {
        return;
    }

    currentCard = lastCard->next;
    firstCard = currentCard->next;

    lastCard->next = firstCard;
    delete currentCard;
}

void demonstrateStudentsCards4()
{
    using namespace std;

    StudentCardsCollection collection = NULL;

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
    cout << "__________" << "\n";
    removeStudentCard(collection, 5);
    cout << "__________" << "\n";
    printStudentCardsList(collection);
}