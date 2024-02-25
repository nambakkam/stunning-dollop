import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import VectorEnums 1.0

Rectangle {
    id:unitsScreen
    width: 480
    height: 800
    color: "#45aaf2"
    ColumnLayout{
        id: buttonsLayout
        width: parent.width
        anchors.centerIn: parent
        height: parent.height*0.75
        spacing: parent.height*0.01
        ComboBox{
            id:chooseUnits
            implicitWidth: parent.width*0.35
            implicitHeight: parent.height*0.07
            Layout.alignment: Qt.AlignCenter
            model: ["Choose Units","CGS", "MKS", "FPS"]
            onCurrentIndexChanged: {
                if(currentIndex > 0){
                    unitsFactory.setUnits(currentIndex-1)
                }
            }
        }

        Text {
            id: lengthUnitsText
            text: qsTr("Length Units: " + unitsFactory.lengthUnits)
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "white"
            font{
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height*0.05
            }


        }

        Text {
            id: massUnitsText
            text:qsTr( "MassUnits: " + unitsFactory.massUnits)
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "white"
            font{
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height*0.05
            }


        }

        Text {
            id: timeUnitsText
            text: qsTr("TimeUnits: "  + unitsFactory.timeUnits)
            width: parent.width
            horizontalAlignment: "AlignLeft"
            verticalAlignment: "AlignTop"
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
            Layout.alignment: Qt.AlignCenter
            color: "white"
            font{
                family: "ROBOTO"
                styleName: "MEDIUM"
                pixelSize: parent.height*0.05
            }


        }


    }

}
