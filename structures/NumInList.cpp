
struct NumInList {
    int val;
    NumInList* next;

    int toInt()
    {
        int res = val;
        while (next != NULL) {
            res = res * 10 + next->val;
            next = next->next;
        }
        return res;
    }
};