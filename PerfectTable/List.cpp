#include "List.h"
using namespace std;

void List::clear()
{
	m_vItemList.clear();
	m_iSize = 0;
    m_uNextId = 1;
}

Item &List::operator[](int index)
{
    return m_vItemList[index];
}

int List::getNextId()
{
    return m_uNextId;
}


List::List(){}
List::List(std::vector<Item*> newList){
	m_iSize = newList.size();
	for (size_t i{}; i < newList.size(); i++) {
		m_vItemList.push_back(*newList[i]);
        m_uNextId = max(m_uNextId,newList[i]->getArticle()+1);

	}
}
List::List(std::vector<Item> newList) {
	m_vItemList = newList;
    for (size_t i{}; i<newList.size(); ++i)
    {
        m_uNextId = max(m_uNextId,newList[i].getArticle()+1);
    }
	m_iSize = newList.size();
}



void List::add(unsigned art, QString nm, double cst, double prc, QString df, int rm, QDate tm, int nop)
{
	m_vItemList.push_back(Item(art, nm, cst, prc, df, rm, tm, nop));
	++m_iSize;
    m_uNextId = max(art+1,m_uNextId);

}
void List::add(Item q)
{
	m_vItemList.push_back(q);
	++m_iSize;
    m_uNextId = max(q.getArticle()+1,m_uNextId);
}
void List::del(Item& deleted)
{
	bool exist{ false };
	int id{ 0 };
	for (int i{}; i < m_iSize; ++i)
	{
		if (&m_vItemList[i] == &deleted)
		{
			exist = true;
			id = i;

		}
	}
	if (exist)
	{
		auto beg = m_vItemList.cbegin();
		m_vItemList.erase(beg + id);
		--m_iSize;
	}
	else
	{
		std::cout << "ERROR: deleted element Doesn't exist" << std::endl;
	};

}
Item* List::findByArticle(int article)
{
	Item* a{nullptr};
	for (int i{}; i < m_iSize; ++i)
	{
		if (article == m_vItemList[i].getArticle())
		{
			a = &m_vItemList[i];
		};
	};
	return a;
}

void List::change(Item* before, Item* after) {
	before->copy(after);
}


