import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2

Dialog {
    id: pwDialog
    property string password

    title: "Master password"
    standardButtons: StandardButton.Ok | StandardButton.Cancel

    Row {
        Text {
            text: "Enter password: "
            font.pixelSize: 12
            width: 100
            y: 8
        }

        TextField {
            id: pw
            width: 150
            height: 30
            placeholderText: "Password"
            passwordCharacter: "*"
            echoMode: TextInput.Password

            onTextChanged: {
                password = pw.text;
            }
        }
    }

    onVisibilityChanged: {
        pw.focus = true;
    }

    onRejected: {
        Qt.quit();
    }
}
