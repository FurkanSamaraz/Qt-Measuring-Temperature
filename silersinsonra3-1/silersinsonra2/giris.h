#ifndef GIRIS_H
#define GIRIS_H

#include <QWidget>

namespace Ui {
class giris;
}

class giris : public QWidget
{
    Q_OBJECT

public:
    explicit giris(QWidget *parent = nullptr);
    ~giris();

private:
    Ui::giris *ui;
};

#endif // GIRIS_H
