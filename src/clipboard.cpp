#include <QClipboard>
#include <QGuiApplication>
#include "clipboard.hpp"

Clipboard::Clipboard(QObject *parent) : QObject(parent) {
}

void Clipboard::setText(QString arg) {
    QClipboard* clip = QGuiApplication::clipboard();
    clip->setText(arg);
    emit textChanged();
}

QString Clipboard::text() const {
    QClipboard* clip = QGuiApplication::clipboard();
    return clip->text();
}
