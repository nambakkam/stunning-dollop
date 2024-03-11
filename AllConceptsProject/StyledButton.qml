import QtQuick 2.15
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: styledButton
    color: "#f5f6fa"
    radius: parent.height * 0.01
    opacity: buttonMouseArea.containsPress ? 0.3 : 1
    property alias buttonTextValue: buttonText.text
    property alias buttonTextColor: buttonText.color
    property alias buttonTextFont: buttonText.font
    property alias iconSource: icon.source
    property alias clickArea: buttonMouseArea
    Text {
        id: buttonText
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width * 0.7
        height: parent.height
        font {
            family: "ROBOTO"
            styleName: "Regular"
            pixelSize: parent.height * 0.5
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    ToolSeparator {
        id: seperator
        anchors.left: buttonText.right
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height
    }

    Image {
        id: icon
        width: parent.width * 0.2
        height: parent.height * 0.6
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.0075
        anchors.verticalCenter: parent.verticalCenter
        fillMode: Image.PreserveAspectFit
    }
    MouseArea {
        id: buttonMouseArea
        anchors.fill: parent
    }
}
