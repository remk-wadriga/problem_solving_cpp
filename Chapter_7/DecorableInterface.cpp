#include "./Decorable.cpp"

class DecorableInterface: public Decorable
{
    public:
        DecorableInterface()
        {
            _next = NULL;
        }

        void setNext(DecorableInterface* next)
        {
            _next = next;
        }

        DecorableInterface* getNext()
        {
            return _next == NULL ? NULL : (DecorableInterface*)_next;
        }

        virtual std::string toString() {}
    private:
        Decorable* _next;
};