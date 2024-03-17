import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

Rectangle {
    id: hashTableScreen
    width: 480
    height: 800
    color: "#45aaf2"
    enabled: !hashTableHandler.disableScreen

    ColumnLayout {
        id: buttonsLayout
        width: parent.width
        anchors.centerIn: parent
        height: parent.height * 0.75
        spacing: parent.height * 0.01
        ListModel {
            id: vectorSizesListModel
            ListElement {
                data: "Choose Size..."
            }
            ListElement {
                data: "Small"
            }
            ListElement {
                data: "Medium"
            }
            ListElement {
                data: "Large"
            }
        }

        ComboBox {
            id: chooseSize
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.07
            model: vectorSizesListModel
            Layout.alignment: Qt.AlignCenter
            textRole: "data"
            delegate: ItemDelegate {
                text: model.data
                width: chooseSize.width
                font.pixelSize: hashTableScreen.height * 0.02
            }

            onCurrentIndexChanged: {
                if (currentIndex > 0) {
                    hashTableHandler.createHashtable(currentIndex)
                }
            }
        }
        StyledButton {
            id: insertButton
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Add Element"
            iconSource: "qrc:/icons/plus.svg"
            clickArea{
                onClicked: {
                    hashTableHandler.set()
                }
            }
        }

        StyledButton {
            id: deleteButton
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Delete Element"
            iconSource: "qrc:/icons/cross.svg"
            clickArea{
                onClicked: {
                    hashTableHandler.removeKey()
                }
            }
        }

        StyledButton {
            id: getValueButton
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Get Value"
            iconSource: "qrc:/icons/question.svg"
            clickArea{
                onClicked: {
                    hashTableHandler.get()
                }
            }
        }

        ScrollView {
            id: keysTextView
            implicitWidth: parent.width * 0.8
            implicitHeight: parent.height * 0.15
            Layout.alignment: Qt.AlignCenter
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            TextArea {
                id: keysText
                color: "black"
                implicitWidth: parent.width
                implicitHeight: parent.height
                horizontalAlignment: "AlignLeft"
                verticalAlignment: "AlignTop"
                wrapMode: "WrapAtWordBoundaryOrAnywhere"
                background: Rectangle {
                    color: "white"
                }
                font {
                    family: "Roboto"
                    styleName: "italic"
                    pixelSize: vectorTextview.implicitHeight * 0.15
                }

                text: "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
                      + "sed do eiusmod tempor incididunt ut labore et dolore magna "
                      + "aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
                      + "ullamco laboris nisi ut aliquip ex ea commodo cosnsequat. "
                      + "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
                      + "sed do eiusmod tempor incididunt ut labore et dolore magna "
                      + "aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
                      + "ullamco laboris nisi ut aliquip ex ea commodo cosnsequat"
            }
        }
        StyledButton {
            id: getButton
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Get Keys"
            iconSource: "qrc:/icons/key.svg"
            clickArea{
                onClicked: {
                    var keys = hashTableHandler.getAllKeys()
                    keysText.text = keys.join()
                }
            }
        }
        ScrollView {
            id: vectorTextview
            implicitWidth: parent.width * 0.8
            implicitHeight: parent.height * 0.15
            Layout.alignment: Qt.AlignCenter
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            TextArea {
                id: vectorText
                color: "black"
                implicitWidth: parent.width
                implicitHeight: parent.height
                horizontalAlignment: "AlignLeft"
                verticalAlignment: "AlignTop"
                wrapMode: "WrapAtWordBoundaryOrAnywhere"
                background: Rectangle {
                    color: "white"
                }
                font {
                    family: "Roboto"
                    styleName: "italic"
                    pixelSize: vectorTextview.implicitHeight * 0.15
                }

                text: hashTableHandler.displayData
            }
        }
        StyledButton {
            id: viewButton
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height * 0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "View"
            iconSource: "qrc:/icons/eye.svg"
            clickArea{
                onClicked: {
                    hashTableHandler.displayHashTable()
                }
            }
        }
        Text {
            id: infoText
            text: hashTableHandler.description
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "white"
            font {
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height * 0.025
            }
        }
    }
}
