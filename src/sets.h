#ifndef SETSGENERATOR_SETS_H
#define SETSGENERATOR_SETS_H


class SetException: public std::exception {
private:
    std::string error;
public:
    explicit SetException(std::string error);
    const char* what() const noexcept override;
};


// template <typename TYPE>
bool isSet(const int* set, int n);
// template <typename TYPE>
void printSet(const int* set, int n);


#endif
