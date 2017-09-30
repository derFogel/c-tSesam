#ifndef SHA265_H
#define SHA265_H
#include <QObject>

class SHA256 : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString hash READ hash WRITE setHash)
        Q_PROPERTY(QString hashedValue READ hashedValue NOTIFY hashedValueChanged)
    public:
        explicit SHA256(QObject *parent = 0);

        QString hash() const;
        void setHash(QString hash);

        QString hashedValue() const;

    private:
        QString mHash, mHashedValue;

    signals:
        void hashedValueChanged();

    public slots:
};

#endif // SHA265_H
