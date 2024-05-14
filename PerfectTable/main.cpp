
#include "mainwindow.h"







int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    std::vector<Item> items = {Item(12,"Александрит",32000,2300,"tre",4,QDate(2000,12,12),2),Item(44,"Еда",22,33,"QQQ",1,QDate(2000,10,12),1)};
   List q{items};


//   Diagram w(&q);
//   w.show();

   MainWindow w(&q);
   w.show();
    return a.exec();
}
