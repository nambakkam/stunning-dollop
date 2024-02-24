import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import VectorEnums 1.0

Rectangle {
    id:vectorScreen
    width: 480
    height: 800
    color: "#45aaf2"
    opacity: vectorHandler.disableScreen? 0.3:1
    enabled: !vectorHandler.disableScreen
    ColumnLayout{
        id: buttonsLayout
        width: parent.width
        anchors.centerIn: parent
        height: parent.height*0.75
        spacing: parent.height*0.01
        ComboBox{
            id:chooseVector
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.07
            Layout.alignment: Qt.AlignCenter
            model: ["Choose Vector Size","Small", "Medium", "Large"]
            onCurrentIndexChanged: {
                switch(currentIndex){
                case VectorEnums.SMALL:
                    vectorHandler.setVectorSize(VectorEnums.SMALL)
                    break
                case VectorEnums.MEDIUM:
                    vectorHandler.setVectorSize(VectorEnums.MEDIUM)
                    break
                case VectorEnums.LARGE:
                    vectorHandler.setVectorSize(VectorEnums.LARGE)
                    break
                 default:
                }
            }
        }

        StyledButton{
            id:pushButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Push"
            iconSource: "qrc:/icons/arrow-right.svg"
            clickArea{
                onClicked: {
                    vectorHandler.pushRandomNumber()
                }
            }

        }
        StyledButton{
            id:popButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Pop"
            iconSource: "qrc:/icons/minus-circle.svg"
            clickArea{
                onClicked: {
                    vectorHandler.popLastNumber()
                }
            }
        }
        StyledButton{
            id:insertButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Insert"
            iconSource: "qrc:/icons/plus.svg"
            clickArea{
                onClicked: {
                    vectorHandler.insertatRandomIndex()
                }
            }
        }
        StyledButton{
            id:deleteButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Delete"
            iconSource: "qrc:/icons/cross.svg"
            clickArea{
                onClicked: {
                    vectorHandler.removeatRandomIndex()
                }
            }
        }
        StyledButton{
            id:findButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "Search"
            iconSource: "qrc:/icons/search.svg"
            clickArea{
                onClicked: {
                    vectorHandler.searchRandomNumber()
                }
            }
        }
        StyledButton{
            id:getButton
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignCenter
            buttonTextValue: "At Index"
            iconSource: "qrc:/icons/question.svg"
            clickArea{
                onClicked: {
                    vectorHandler.valueAtRandomIndex()
                }
            }
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

                text:vectorHandler.vectorString

            }
        }

        Text {
            id: infoText
            text: vectorHandler.description
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "white"
            font{
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height*0.025
            }


        }
    }

}
