#ifndef COLOR_H_
#define COLOR_H_

#include <ncurses.h>
#include <string>
using namespace std;

const int anColorTable[] = {
    COLOR_BLACK, COLOR_RED,     COLOR_GREEN, COLOR_YELLOW,
    COLOR_BLUE,  COLOR_MAGENTA, COLOR_CYAN,  COLOR_WHITE
};

class Color {
private:
    static const int m_nStartPairID = 1;
    static const int m_nMaxPairID = sizeof(anColorTable) / sizeof(anColorTable[0]);
    int m_nPairID;
    int m_nColorID;

public:
    Color(int nColor = COLOR_WHITE);
    virtual ~Color();

    // Setters
    void setColor(int nColorID);

    // Getters
    int getStartPairID()  { return m_nStartPairID; }
    int getMaxPairID()    { return m_nMaxPairID; }
    int getPairID()       { return m_nPairID; }
    int getColorID()      { return m_nColorID; }

    // Methods
    static void initColorPairs();
    bool atFirstColor();
    int getNextColor();
    string getColorString();
};

#endif
