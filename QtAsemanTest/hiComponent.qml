import QtQuick 2.0
import QtQuick.Controls 2.12

Component {
    id: hiComponent
    Page {
        id: page
        anchors.fill: parent
        property int cnt

        Button {
            id: btn
            text: "Open " + (page.cnt+1)
            anchors.centerIn: parent

            // append method could also pass properties to the dest object
            onClicked: viewPort.append(hiComponent, {"counter": page.cnt+1}, "popup")
        }
    }
}
