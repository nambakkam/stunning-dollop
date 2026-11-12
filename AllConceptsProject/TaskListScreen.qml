import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: taskListScreen
    width: 480
    height: 800
    color: "#2d98da"

    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.11
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.86
        height: parent.height * 0.82
        spacing: parent.height * 0.015

        Text {
            text: qsTr("MVVM task list")
            color: "white"
            font.pixelSize: taskListScreen.height * 0.035
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: qsTr("The view binds to ViewModel state and sends user actions to its commands.")
            color: "white"
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Text {
            text: qsTr("%1 remaining | %2 completed")
                  .arg(taskViewModel.remainingCount)
                  .arg(taskViewModel.completedCount)
            color: "white"
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            Layout.fillWidth: true

            TextField {
                id: taskInput
                placeholderText: qsTr("New task")
                Layout.fillWidth: true
                onAccepted: addTask()
            }

            Button {
                text: qsTr("Add")
                onClicked: addTask()
            }
        }

        Text {
            text: taskViewModel.errorMessage
            color: "#7a1020"
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Text {
            text: qsTr("No tasks yet.")
            color: "white"
            visible: taskList.count === 0
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: taskList
            model: taskViewModel.tasks
            clip: true
            spacing: taskListScreen.height * 0.008
            Layout.fillWidth: true
            Layout.fillHeight: true

            delegate: Rectangle {
                width: taskList.width
                height: taskListScreen.height * 0.065
                radius: 4
                color: "white"

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.04
                    anchors.rightMargin: parent.width * 0.02

                    Text {
                        text: taskText
                        color: completed ? "#757575" : "#202020"
                        font.strikeout: completed
                        elide: Text.ElideRight
                        Layout.fillWidth: true
                    }

                    Button {
                        text: completed ? qsTr("Reopen") : qsTr("Complete")
                        onClicked: taskViewModel.setTaskCompleted(index, !completed)
                    }

                    Button {
                        text: qsTr("Remove")
                        onClicked: taskViewModel.removeTask(index)
                    }
                }
            }
        }
    }

    function addTask() {
        taskViewModel.addTask(taskInput.text)
        if (taskViewModel.errorMessage === "")
            taskInput.clear()
    }
}
