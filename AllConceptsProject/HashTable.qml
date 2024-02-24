import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

Rectangle {
    id:hashTableScreen
    width: 480
    height: 800
    color: "#45aaf2"

    ColumnLayout{
        id: buttonsLayout
        width: parent.width
        anchors.centerIn: parent
        height: parent.height*0.75
        spacing: parent.height*0.01
        StyledButton{
            id:pushButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Push"
            iconSource: "qrc:/icons/arrow-right.svg"
        }
        StyledButton{
            id:popButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Pop"
            iconSource: "qrc:/icons/minus-circle.svg"
        }
        StyledButton{
            id:insertButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Insert"
            iconSource: "qrc:/icons/plus.svg"
        }
        StyledButton{
            id:deleteButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Delete"
            iconSource: "qrc:/icons/cross.svg"
        }
        StyledButton{
            id:findButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Search"
            iconSource: "qrc:/icons/search.svg"
        }
        StyledButton{
            id:getButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "At Index"
            iconSource: "qrc:/icons/question.svg"
        }
        ScrollView{
            id:vectorTextview
            implicitWidth: parent.width*0.8
            implicitHeight: parent.height*0.15
            Layout.alignment: Qt.AlignCenter
            ScrollBar.vertical.policy:ScrollBar.AlwaysOn
            TextArea{
                id:vectorText
                color: "black"
                implicitWidth: parent.width
                implicitHeight: parent.height
                horizontalAlignment: "AlignLeft"
                verticalAlignment: "AlignTop"
                wrapMode: "WrapAtWordBoundaryOrAnywhere"
                background: Rectangle{
                    color: "white"
                }
                font{
                    family: "Roboto"
                    styleName: "italic"
                    pixelSize: vectorTextview.implicitHeight*0.15
                }

                text:"Lorem ipsum dolor sit amet, consectetur adipisicing elit, " +
                     "sed do eiusmod tempor incididunt ut labore et dolore magna " +
                     "aliqua. Ut enim ad minim veniam, quis nostrud exercitation " +
                     "ullamco laboris nisi ut aliquip ex ea commodo cosnsequat. "+
                     "Lorem ipsum dolor sit amet, consectetur adipisicing elit, " +
                                          "sed do eiusmod tempor incididunt ut labore et dolore magna " +
                                          "aliqua. Ut enim ad minim veniam, quis nostrud exercitation " +
                                          "ullamco laboris nisi ut aliquip ex ea commodo cosnsequat";

            }
        }

        Text {
            id: infoText
            text: qsTr("Click on the above buttons to perform " + "Vector"+" Operations")
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "#e84118"
            font{
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height*0.025
            }


        }
    }

}
