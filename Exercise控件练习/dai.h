#ifndef DAI_H
#define DAI_H

#include <QMainWindow>
#include <QObject>

class Dai : public QObject
{
    Q_OBJECT
public:
    explicit Dai(QObject *parent = nullptr);
    int Get_Shang();
    int Get_Gong();
signals:

public slots:

private:
    int Shang,Gong;
};

#endif // DAI_H
