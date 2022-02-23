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
    id: applicationWindow
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Giriş")
    //visibility: Qt.WindowFullScreen

    property bool giris_durum: false

    StackView {
        id: stackView
        anchors.fill: parent
 }
        Rectangle {
            id: rectangle
            x: 780
            y: 476
            width: 200
            height: 200
            color: "#ffffff"

            Text {
                id: text1
                text: qsTr("GİRİŞ YAP")
                anchors.fill: parent
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Connections{
                target: database
                onGirisBasarili: giris_durum =a
            }
            Component.onCompleted: {
                mouseArea.clicked.connect(function(){
                    if(giris_durum==true){
                        stackView.replace("qrc:/anasayfa.qml")
                        applicationWindow.close()
                    }else{
                        //dialogHata.open()
                    }
                });
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: {
                    database.giris()
                    console.log(giris_durum)
                }
            }
        }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
