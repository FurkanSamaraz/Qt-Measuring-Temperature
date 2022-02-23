import QtQuick 2.0
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs.qml 1.0
import Qt.labs.animation 1.0
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12
import Qt.labs.settings 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: anasayfaWindow
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Anasayfa")

    Rectangle {
        id: rectangle
        width: 300
        color: "#ffffff"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0

        TextField {
            id: textField
            x: 50
            y: 140
            placeholderText: qsTr("Değer1")
        }

        TextField {
            id: textField1
            x: 50
            y: 228
            placeholderText: qsTr("Değer2")
        }

        Button {
            id: button
            x: 100
            y: 306
            text: qsTr("Ekle")
            onClicked:{
                database.veriEkle1(textField.text,textField1.text)
            }
        }
    }

    Rectangle {
        id: rectangle1
        color: "#ffffff"
        anchors.left: rectangle.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 20
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        anchors.rightMargin: 0

        ListView {
            id: listView
            anchors.fill: parent
            clip: true
            spacing: 10
            delegate: Item {
                width: listView.width
                height: 90
                Row {
                    id: row1
                    Rectangle {
                        width: listView.width
                        height: 90
                        Text {
                            id: text1
                            text: sicaklikidRole
                        }
                    }

                }
            }
            model: myModel
        }
    }
    //visibility: Qt.WindowFullScreen

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:5}
}
##^##*/
