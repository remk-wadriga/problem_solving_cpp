
class InterfaceListItem
{
public:
    void virtual setNext(InterfaceListItem* nextItem) = 0;
    InterfaceListItem virtual * getNext() = 0;
    std::string virtual toString() = 0;
};