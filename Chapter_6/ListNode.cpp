
struct ListNode : public AbstractListItem
{
    public:
        int data;

        ListNode(int val, AbstractListItem* next = NULL)
        {
            data = val;
            setNext(next);
        }

        // Implementing Interface AbstractListItem
        std::string toString()
        {
            return std::to_string(data);
        }

        AbstractListItem* createCopy()
        {
            return new ListNode(data);
        }
        // END Implementing Interface AbstractListItem
};
typedef ListNode* listPtr;