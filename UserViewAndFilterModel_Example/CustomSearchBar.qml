import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    implicitHeight: 40
    implicitWidth: 0

    property alias text: searchField.text
    signal searchTextChanged(string newText)

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 70
        height: 36
        radius: 18
        color: "#111111"
        border.color: "#ff9800"
        border.width: 1

        RowLayout {
            anchors.fill: parent
            spacing: 8
            Layout.margins: 8

            Rectangle {
                Layout.margins: 10
                Layout.preferredWidth: 22
                Layout.preferredHeight: 22
                color: "transparent"
                Image {
                    anchors.centerIn: parent
                    source: "Images/searchIcon.png"
                    fillMode: Image.PreserveAspectFit
                    width: 18
                    height: 18
                    opacity: 0.95
                }
            }

            TextField {
                id: searchField
                placeholderText: "Search Users..."
                placeholderTextColor: "#bfbfbf"
                color: "white"
                background: null
                font.pixelSize: 15
                Layout.fillWidth: true
                onTextChanged: root.searchTextChanged(text)
                cursorVisible: true
            }
        }
    }
}
