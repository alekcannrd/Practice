#pragma once
#include <QString>
const int UNIT_LEN{ 15 };
enum class TITLES
{
    article,
    Name,
    Cost,
    Price,
    Definition,
    Remain,
    Time,
    NumOfParty,
    TITLE_SIZE
};
extern QString strTitleNames[static_cast<size_t>(TITLES::TITLE_SIZE)];

