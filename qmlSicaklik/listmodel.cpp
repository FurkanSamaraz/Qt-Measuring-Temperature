#include "listmodel.h"
#include "islem.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->modelGuncelle();
}

QVariant ListModel::data(const QModelIndex & index, int role) const {

    int columnId = role - Qt::UserRole - 1;

    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> ListModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[IdRole] = "sicaklikidRole";
    roles[sicaklik1Role] = "sicaklik1Role";
    roles[sicaklik2Role] = "sicaklik2Role";
    roles[tarihRole] = "sicakliktarihRole";
    roles[saatRole] = "sicakliksaatRole";
    return roles;
}


void ListModel::modelGuncelle()
{
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT sicaklik_id,sicaklik_degeri1,sicaklik_degeri2,sicaklik_tarih,sicaklik_saat  FROM sicakliklar ORDER BY sicaklik_id DESC");
}

/*void ListModel::modelGetir( const QDate tarih1, const  QDate tarih2)
{

    QDate gelen_tarihim1 = tarih1;
    QString tarihim1 = gelen_tarihim1.toString(Qt::ISODate);
    QDate gelen_tarihim2 = tarih2;
    QString tarihim2 = gelen_tarihim2.toString(Qt::ISODate);

    this->setQuery("SELECT * FROM sicakliklar WHERE sicaklik_tarih>='"+tarihim1+"' AND sicaklik_tarih<='"+tarihim2+"'  ORDER BY sicaklik_id DESC ");
}*/

/*void ListModel::ortalamaGetir( const QDate tarih1, const  QDate tarih2)
{

    QDate gelen_tarihim1 = tarih1;
    QString tarihim1 = gelen_tarihim1.toString(Qt::ISODate);
    QDate gelen_tarihim2 = tarih2;
    QString tarihim2 = gelen_tarihim2.toString(Qt::ISODate);

    QSqlQuery query1;
    query1.exec("SELECT AVG(sicaklik_degeri1) FROM sicakliklar WHERE sicaklik_tarih>='"+tarihim1+"' AND sicaklik_tarih<='"+tarihim2+"'");
    while(query1.next()){
        sicaklik_degeri1 = query1.value(0).toFloat();
    }

    QSqlQuery query2;
    query2.exec("SELECT AVG(sicaklik_degeri2) FROM sicakliklar WHERE sicaklik_tarih>='"+tarihim1+"' AND sicaklik_tarih<='"+tarihim2+"'");
    while(query2.next()){
        sicaklik_degeri2 = query2.value(0).toFloat();
    }

    qDebug() << sicaklik_degeri1 << sicaklik_degeri2;

     ortalamaGoster(sicaklik_degeri1,sicaklik_degeri2);
}*/



/*int ListModel::idCek(int row)
{
    return this->data(this->index(row, 0), IdRole).toInt();
}*/
