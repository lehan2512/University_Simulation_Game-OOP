#include <string>
#include <memory>
#include <vector>

class CPlayer
{
private:
    std::string mName;
    int mMotivation;
    int mSuccess;
    int mYear;
    int mPosition;

public:
    CPlayer(std::string name);
    void setName(std::string name);
    void setMotivation(int motivation);
    void setSuccess(unsigned int success);
    void setYear(int year);
    void setPosition(int position);
    std::string getName();
    int getMotivation();
    int getSuccess();
    int getYear();
    int getPosition();
};

// Define an alias for the shared pointer
using CPlayerPtr = std::shared_ptr<CPlayer>;
