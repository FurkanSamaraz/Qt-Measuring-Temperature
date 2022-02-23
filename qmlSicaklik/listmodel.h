#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>

class ListModel : public QSqlQueryModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        sicaklik1Role,
        sicaklik2Role,
        tarihRole,
        saatRole
    };

    explicit ListModel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    //float sicaklik_degeri1;
    //float sicaklik_degeri2;

protected:

    QHash<int, QByteArray> roleNames() const;

signals:

    //void ortalamaGoster(float a,float b);

public slots:
    void modelGuncelle();
    //void modelGetir(const QDate tarih1, const QDate tarih2);
    //void ortalamaGetir(const QDate tarih1, const QDate tarih2);
    //int idCek(int row);
};


#endif // LISTMODEL_H
