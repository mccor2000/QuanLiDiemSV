#include "./color.h"

Color::Color(int nColorID) {
    m_nColorID = nColorID;
    m_nPairID  = nColorID + 1;
}

Color::~Color() {
}

void Color::initColorPairs() {
    static bool bInitComplete = false;

    if (! bInitComplete)
        for (int iii = m_nStartPairID; iii < m_nMaxPairID + 1; iii++)
            init_pair(iii, anColorTable[iii - 1], COLOR_BLACK);

    bInitComplete = true;
}

void Color::setColor (int nColorID) {
    m_nColorID = nColorID;
    m_nPairID  = nColorID + 1;
}

bool Color::atFirstColor() {
    return (m_nPairID == m_nStartPairID ? true : false);
}

int Color::getNextColor() {
    if (m_nPairID == m_nMaxPairID)
    {
        m_nPairID = m_nStartPairID;
        m_nColorID = anColorTable[0];
    }
    else
    {
        m_nPairID++;
        m_nColorID++;
    }

    return m_nColorID;
}

string Color::getColorString() {
    string strColorString;

    switch (m_nColorID)
    {
        case COLOR_BLACK:   strColorString = "BLACK";   break;
        case COLOR_RED:     strColorString = "RED";     break;
        case COLOR_GREEN:   strColorString = "GREEN";   break;
        case COLOR_YELLOW:  strColorString = "YELLOW";  break;
        case COLOR_BLUE:    strColorString = "BLUE";    break;
        case COLOR_MAGENTA: strColorString = "MAGENTA"; break;
        case COLOR_CYAN:    strColorString = "CYAN";    break;
        case COLOR_WHITE:   strColorString = "WHITE";   break;
    }

    return strColorString;
}
