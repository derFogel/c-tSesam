#ifndef PBKDF2_H
#define PBKDF2_H

#include <QObject>

class PBKDF2 : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString string READ string WRITE setString)
        Q_PROPERTY(QString usedChars READ usedChars WRITE setUsedChars)
        Q_PROPERTY(QString hash READ hash NOTIFY hashChanged)
        Q_PROPERTY(QString salt READ salt WRITE setSalt)
        Q_PROPERTY(QString password READ password WRITE setPassword)
        Q_PROPERTY(int passwordLength READ passwordLength WRITE setPasswordLength)
    public:
        explicit PBKDF2(QObject *parent = 0);

        QString string() const;
        void setString(QString arg);

        QString hash() const;

        QString usedChars() const;
        void setUsedChars(QString arg);

        QString salt() const;
        void setSalt(QString arg);

        int passwordLength() const;
        void setPasswordLength(int arg);

        QString password() const;
        void setPassword(QString arg);

        Q_INVOKABLE void calculate();

    private:
        QString mString, mHash, mUsedChars, mSalt, mPassword;
        int mPasswordLength;

    signals:
        void hashChanged();

    public slots:
};

#endif // PBKDF2_H
