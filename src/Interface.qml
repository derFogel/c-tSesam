import QtQuick 2.5
import QtQuick.Controls 2.0
import Qt.labs.settings 1.0
import Password 1.0
import Clipboard 1.0

Rectangle {
    property alias textEdit: textEdit

    width: 230
    height: 220

    Item {
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Escape) {
                hide();
                clear.start()
                event.accepted = true;
            }
        }
    }

    Settings {
        id: settings
        property string pwchars: "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#!\"§$%&/()[]{}=-_+*<>;:."
        property string salt: "pepper"
        property int passwortLength: 10
        property int expire: 10
    }

    PBKDF2 {
        id: hasher

        salt: settings.salt
        usedChars: chars1.text
        passwordLength: settings.passwortLength
    }

    Clipboard {
        id: clip
    }

    Timer {
        id: clear
        interval: settings.expire * 1000

        onTriggered: {
            clip.text = "";
            Qt.quit();
        }
    }

    PasswordDialog {
        property bool isAccepted: false

        Component.onCompleted: {
            open();
        }

        onAccepted: {
            if (password.length < 1) {
                open();
            } else {
                hasher.password = password;
                hasher.string = textEdit.text;
                hasher.calculate();
                output.text = hasher.hash;
                isAccepted = true;
                textEdit.focus = true;
                textEdit.selectAll();
            }
        }
    }

    TextField {
        id: textEdit
        x: 81
        y: 10
        width: 140
        height: 30
        text: "www.google.de"

        onTextChanged: {
            hasher.string = text;
            hasher.calculate();
            output.text = hasher.hash;
            clip.text = hasher.hash;
        }

        Keys.onPressed: {
            if (event.key == Qt.Key_Escape) {
                hide();
                clear.start();
                event.accepted = true;
            }
        }
    }

    Text {
        id: text1
        x: 8
        y: 18
        text: "URL:"
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 8
        y: 55
        text: "Password:"
        font.pixelSize: 12
    }

    TextField {
        id: output
        x: 81
        y: 47
        width: 140
        height: 30
        readOnly: true
        text: hasher.hash
        passwordCharacter: "*"
        echoMode: TextInput.Password
    }

    Text {
        id: text3
        x: 8
        y: 128
        text: "Useable Chars:"
        font.pixelSize: 12
    }

    CheckBox {
        id: checkBox1
        x: 8
        y: 80
        width: 85
        height: 40
        text: "visible"

        onCheckedChanged: {
            if (checked) {
                output.echoMode = TextInput.Normal;
            } else {
                output.echoMode = TextInput.Password;
            }
        }

        Keys.onPressed: {
            if (event.key == Qt.Key_Escape) {
                hide();
                clear.start()
                event.accepted = true;
            }
        }
    }

    TextArea {
        id: chars1
        x: 8
        y: 144
        width: 214
        height: 67
        text: settings.pwchars
        wrapMode: TextEdit.WrapAnywhere

        onTextChanged: {
            settings.pwchars = text;
            hasher.usedChars = text;
            hasher.calculate()
            output.text = hasher.hash;
        }

        Keys.onPressed: {
            if (event.key == Qt.Key_Escape) {
                hide();
                clear.start()
                event.accepted = true;
            } else if (event.key == Qt.Key_F1) {
                text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#!\"§$%&/()[]{}=-_+*<>;:.";
                event.accepted = true;
            }
        }

        Rectangle {
            height: 70
            anchors.fill: parent
            border.width: 1
            anchors.margins: 0
            color: "#00000000"
        }
    }
}
