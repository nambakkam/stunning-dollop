import QtQuick 2.15
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle {
    id: headingBar
    width: parent.width
    height: parent.height * 0.075
    color: "#273c75"
    signal previousClicked
    signal nextClicked
    property alias tabHeading: headingText.text
    RowLayout {
        id: headerItemsLayout
        anchors.fill: parent
        spacing: 0
        Rectangle {
            id: previousButton
            implicitWidth: parent.width * 0.15
            implicitHeight: parent.height * 0.7
            Layout.alignment: Qt.AlignVCenter
            opacity: prevButtonMouseArea.containsPress ? 0.3 : 1
            color: "transparent"
            Image {
                id: previousIcon
                source: "qrc:/icons/previous.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                id: prevButtonMouseArea
                anchors.fill: parent
                onClicked: {
                    previousClicked()
                }
            }
        }
        Rectangle {
            id: textHolder
            Layout.alignment: Qt.AlignVCenter
            implicitWidth: parent.width * 0.7
            implicitHeight: parent.height
            color: "transparent"
            clip: true
            Text {
                id: headingText
                text: "SampleText"
                color: "#f5f6fa"
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                elide: Text.ElideRight
                font {
                    family: "ROBOTO"
                    styleName: "Medium"
                    pixelSize: parent.height * 0.4
                }
            }
        }
        Rectangle {
            id: nextButton
            implicitWidth: previousButton.implicitWidth
            implicitHeight: previousButton.implicitHeight
            Layout.alignment: Qt.AlignVCenter
            opacity: nextMouseArea.containsPress ? 0.3 : 1
            color: "transparent"
            Image {
                id: nextIcon
                source: "qrc:/icons/next-button.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                id: nextMouseArea
                anchors.fill: parent
                onClicked: {
                    nextClicked()
                }
            }
        }
    }
}
