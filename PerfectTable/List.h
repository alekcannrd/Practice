#pragma once
#include "Item.h"
#include "Funcs.h"
#include "Constants.h"
#include <vector>
#include <algorithm>
#include <QString>

class List
{
private:
	size_t m_iSize{0};
    unsigned m_uNextId{};

    std::vector <Item> m_vItemList;

public:

	void clear();
    Item &operator[](int index);
    int getNextId();

    int getSize() { return m_iSize; }

    void add(Item);
    void add(unsigned art, QString nm, double cst, double prc, QString df, int rm, QDate tm, int nop);
    void del(Item &deleted);
    void change(Item * before, Item * after);
    Item* findByArticle(int);

	List();
	List(std::vector<Item*> newList);
	List(std::vector<Item> newList);
};

