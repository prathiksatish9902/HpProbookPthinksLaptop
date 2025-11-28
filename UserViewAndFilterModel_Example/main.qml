import QtQuick
import QtQuick.Window

Window {
    id: win
    width: 400
    height: 550
    visible: true
    title: qsTr("User Management")
    color: "black"

    minimumWidth: width
    maximumWidth: width
    minimumHeight: height
    maximumHeight: height

    UserListView {
        id: _user
        width: 420
        height: 440
        anchors.centerIn: parent
    }
}
