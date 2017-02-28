#include <openssl/evp.h>
#include <openssl/sha.h>
#include "pbkdf2.hpp"

PBKDF2::PBKDF2(QObject *parent) : QObject(parent) {
    mUsedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    mPasswordLength = 10;
    mPassword = "12345";
}

QString PBKDF2::string() const {
    return mString;
}

void PBKDF2::setString(QString arg) {
    mString = arg;
}

QString PBKDF2::hash() const {
    return mHash;
}

QString PBKDF2::usedChars() const {
    return mUsedChars;
}

void PBKDF2::setUsedChars(QString arg) {
    if (arg.length() > 1) {
        mUsedChars = arg;
    }
}

QString PBKDF2::salt() const {
    return mSalt;
}

void PBKDF2::setSalt(QString arg) {
    mSalt = arg;
}

int PBKDF2::passwordLength() const {
    return mPasswordLength;
}

void PBKDF2::setPasswordLength(int arg) {
    if (arg > 1) {
        mPasswordLength = arg;
    }
}

QString PBKDF2::password() const {
    return mPassword;
}

void PBKDF2::setPassword(QString arg) {
    if (arg.length() > 1) {
        mPassword = arg;
    }
}

void PBKDF2::calculate() {
    unsigned char hash[64];

    QString toHash = mString + mPassword;

    PKCS5_PBKDF2_HMAC(toHash.toStdString().c_str(), toHash.length(), (unsigned char*)mSalt.toStdString().c_str(), mSalt.length(), 4096, EVP_sha512(), 64, hash);

    __uint128_t num = 0;

    for (int i = 0; i < 64; i++) {
        num = (num << 8) | hash[i];
    }

    mHash.clear();

    while (num > 0 && mHash.length() < mPasswordLength) {
        mHash.append(mUsedChars.at(num % mUsedChars.length()));
        num = num / mUsedChars.length();
    }

    emit hashChanged();
}
