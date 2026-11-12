import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: itemListScreen
    width: 480
    height: 800
    color: "#45aaf2"

    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.11
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.86
        height: parent.height * 0.82
        spacing: parent.height * 0.015

        Text {
            text: qsTr("MVC item list")
            color: "white"
            font.pixelSize: itemListScreen.height * 0.035
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: qsTr("Add an item, then remove it with the button beside it.")
            color: "white"
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillWidth: true

            TextField {
                id: itemInput
                placeholderText: qsTr("New item")
                Layout.fillWidth: true
                onAccepted: addItem()
            }

            Button {
                text: qsTr("Add")
                onClicked: addItem()
            }
        }

        Text {
            text: itemListController.errorMessage
            color: "#7a1020"
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Text {
            text: qsTr("No items yet.")
            color: "white"
            visible: itemsList.count === 0
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: itemsList
            model: itemListModel
            clip: true
            spacing: itemListScreen.height * 0.008
            Layout.fillWidth: true
            Layout.fillHeight: true

            delegate: Rectangle {
                width: itemsList.width
                height: itemListScreen.height * 0.065
                radius: 4
                color: "white"

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.04
                    anchors.rightMargin: parent.width * 0.02

                    Text {
                        text: itemText
                        color: "#202020"
                        elide: Text.ElideRight
                        Layout.fillWidth: true
                    }

                    Button {
                        text: qsTr("Remove")
                        onClicked: itemListController.removeItem(index)
                    }
                }
            }
        }
    }

    function addItem() {
        itemListController.addItem(itemInput.text)
        if (itemListController.errorMessage === "")
            itemInput.clear()
    }
}
