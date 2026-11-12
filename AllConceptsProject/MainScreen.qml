import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

Item {
    id: mainScreen
    width: 480
    height: 800
    property alias currentIndex: stackItems.currentIndex

    Rectangle {
        id: background
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#F5F2FF" }
            GradientStop { position: 1.0; color: "#EAF3FF" }
        }
    }

    Rectangle {
        id: navyOverlay
        anchors.fill: parent
        color: "#000080"
        opacity: 0.18
    }

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
        ItemListScreen {
            id: itemListScreen
            property string heading: "MVC Item List"
        }
        TaskListScreen {
            id: taskListScreen
            property string heading: "MVVM Task List"
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
