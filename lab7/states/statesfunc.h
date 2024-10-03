//Mahnmoud Hafez
//statesfunc.h
//Lab7_Part2: US States and Capitals


typedef struct {
    char abbreviation[3];  // 2 characters + null terminator
    char name[50];         // Assumed max length of state name
    char capital[50];      // Assumed max length of capital name
    int yearJoined;
} State;

void loadData(const char* fileName, State states[], int* count);
void displayMenu();
void listAllStates(const State states[], int count);
void findStateInfo(const State states[], int count);
void findCapitalInfo(const State states[], int count);
void listStatesByYear(const State states[], int count);
