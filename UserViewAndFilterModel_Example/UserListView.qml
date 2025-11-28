import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UserViewAndFilterModel_Example 1.0

Item{
    Rectangle {
        anchors.fill: parent
        color: "#000000"
        radius: 0

        ColumnLayout {
            id: container
            anchors.fill: parent
            anchors.margins: 10
            width: parent.width / 3
            height: parent.height
            Layout.margins: 5
            spacing: 12

            UserFilterModel { id: userFilterModel }

            Label {
                text: "Users"
                font.pointSize: 22
                font.bold: true
                color: "#ff9800"
                Layout.alignment: Qt.AlignHCenter
            }

            CustomSearchBar {
                Layout.fillWidth: true
                onSearchTextChanged: txt => userFilterModel.nameFilter = txt
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "transparent"
                anchors.margins: 0

                ListView {
                    id: userList
                    model: userFilterModel
                    anchors.fill: parent
                    clip: true
                    boundsBehavior: Flickable.StopAtBounds

                    delegate: Item {
                        id: userItem
                        width: parent.width
                        property bool expanded: model.isExpanded
                        height:  expanded ? 150 : 56

                        Rectangle {
                            anchors.fill: parent
                            color: expanded ? "#1a1a1a" : "#111111"
                            border.color: "#ff9800"
                            border.width: 1
                            radius: 8
                            anchors.margins: 4

                            Column {
                                anchors.fill: parent
                                anchors.margins: 10
                                spacing: 8

                                RowLayout {
                                    id: headerRow
                                    width: parent.width
                                    spacing: 10
                                    Layout.alignment: Qt.AlignVCenter

                                    Text {
                                        text: name
                                        font.pointSize: 15
                                        color: "white"
                                        elide: Text.ElideRight
                                        Layout.fillWidth: true
                                        verticalAlignment: Text.AlignVCenter
                                    }

                                    Button {
                                        id: expandBtn
                                        width: 36
                                        height: 28
                                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                        onClicked: userFilterModel.expandRow(index)

                                        background: Rectangle {
                                            color: expanded ? "#ff9800" : "transparent"
                                            border.color: "#ff9800"
                                            radius: 6
                                        }
                                        contentItem: Text {
                                            text: userItem.expanded ? "\u25B2" : "\u25BC"
                                            font.pixelSize: 14
                                            color: expanded ? "black" : "#ff9800"
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                        }
                                    }
                                }

                                Column {
                                    visible: userItem.expanded
                                    spacing: 6
                                    anchors.left: parent.left
                                    anchors.right: parent.right

                                    Text { text: "Name: " + name; color: "#e6e6e6"; font.pixelSize: 13 }
                                    Text { text: "Role: " + role; color: "#d0d0d0"; font.pixelSize: 13 }
                                    Text { text: "User ID: " + id; color: "#c8c8c8"; font.pixelSize: 13 }
                                    Text { text: "Password: " + password; color: "#c0c0c0"; font.pixelSize: 13 }
                                }
                            }
                        }

                        Behavior on height {
                            NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
                        }
                    }
                }
            }
        }
    }
}
