
#include "Item.h"
QString strTitleNames[static_cast<size_t>(TITLES::TITLE_SIZE)] = { "Артикул", "Наименование", "Закупочная стоимость [руб]", "Цена [руб]", "Размещение на складе", "Остаток на складе [шт] ", "Срок годности [дд.мм.гггг]", "Номер партии" };

Item::Item() {}

QVariant Item::operator [](int index)
{
    switch (index)
    {
        case 0: return m_uArticle; break;
    case 1: return m_strName; break;
    case 2: return m_dCost;break;
    case 3: return m_dPrice;break;
        case 4: return (m_strDefinition); break;
    case 5: return m_uRemain;break;
    case 6: return m_dateTime;break;
    case 7: return m_iNumOfParty;break;
    default: return "error";
    };
}

QTextStream &operator<<(QTextStream &out, Item &item)
{

    out << item.m_uArticle << ';' << item.m_strName << ';' << item.m_dCost << ';' << item.m_dPrice << ';' << item.m_strDefinition << ';' << item.m_uRemain << ';' << item.m_dateTime.toString("dd.MM.yyyy") << ';' << item.m_iNumOfParty << '\n';
    return out;
}

QTextStream &operator>>(QTextStream &in, Item &item)
{
    QString line = in.readLine();
    QStringList fields = line.split(';');

    item = Item(fields[0].toInt(),fields[1],fields[2].toDouble(),fields[3].toDouble(),fields[4],fields[5].toInt(),QDate::fromString(fields[6],"dd.MM.yyyy"),fields[7].toInt());


    return in;
}

Item::Item(int art, QString nm, double cst, double prc, QString df, int rm, QDate tm, int nop) : m_uArticle(art),m_strName(nm),m_dCost(cst),m_dPrice(prc),m_strDefinition(df),m_uRemain(rm),m_dateTime(tm),m_iNumOfParty(nop)
{


}


void Item::copy(Item* after) {
    m_uArticle = after->getArticle();
    m_strName = after->getName();
    m_dCost = after->getCost();
    m_dPrice = after->getPrice();
    m_strDefinition = after->getDefinition();
    m_uRemain = after->getRemain();
    m_dateTime = after->getTime();
    m_iNumOfParty = after->getNumOfParty();
}

