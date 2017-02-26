#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QObject>

class Clipboard : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    public:
        explicit Clipboard(QObject *parent = 0);

        QString text() const;
        void setText(QString arg);

    signals:
        void textChanged();

    public slots:
};

#endif // CLIPBOARD_H
