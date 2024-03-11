import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 480
    height: 800
    visible: true
    title: qsTr("Hello World")

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/MainScreen.qml"
        onLoaded: {

        }
    }
}
