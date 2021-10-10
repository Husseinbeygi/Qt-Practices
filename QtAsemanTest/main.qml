import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import AsemanQml.Controls 2.0
import AsemanQml.Viewport 2.0

AsemanWindow {
    visible: true
    width: 480
    height: 720
    title: qsTr("Hello World")

    Header {
        width: parent.width
        text: "Hello"
        color: "#18f"
    }

    Drawer {
        id: menu
        anchors.fill: parent
        delegate: Rectangle {
            anchors.fill: parent
            color: "#333"
        }
    }

    HeaderMenuButton {
        id: btn
        /*
         * If BackHandler stack is not empty, It shows back
         * button instead of hamburger btn.
         */
        ratio: BackHandler.count? 1 : menu.percent
        onClicked: BackHandler.count? BackHandler.back() : menu.show()
    }
}
