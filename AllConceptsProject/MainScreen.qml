import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

Item {
    id: mainScreen
    width: 480
    height: 800
    property alias currentIndex: stackItems.currentIndex
    StackLayout {
        id: stackItems
        anchors.fill: parent
        VectorsScreen {
            id: vectorScreen
            property string heading: "Vectors Implementation"
        }
        HashTable {
            id: hashTableScreen
            property string heading: "Hash Table Implementation"
        }
        UnitsDemonstrator {
            id: unitsScreen
            property string heading: "Units Demonstration"
        }
    }
    HeadingToolBar {
        id: header
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        tabHeading: stackItems.itemAt(currentIndex).heading
        onPreviousClicked: {
            if (currentIndex >= 1) {
                currentIndex--
            }
        }
        onNextClicked: {
            if (currentIndex < stackItems.count - 1) {
                currentIndex++
            }
        }
    }
}
