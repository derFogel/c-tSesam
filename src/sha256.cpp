#include <openssl/sha.h>
#include "sha256.hpp"

SHA256::SHA256(QObject *parent) : QObject(parent) {
}

QString SHA256::hash() const {
    return mHash;
}

void SHA256::setHash(QString hash) {
    mHash = hash;
    mHashedValue = "";

    unsigned char hashbytes[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, hash.toStdString().c_str(), hash.length());
    SHA256_Final(hashbytes, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        mHashedValue += QString::number(hashbytes[i], 16);
    }

    emit hashedValueChanged();
}

QString SHA256::hashedValue() const {
    return mHashedValue;
}
