import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
   // width: 400
    Layout.minimumHeight: button1.implicitHeight+button2.implicitHeight+button3.implicitHeight
    Layout.minimumWidth: button2.width

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    ColumnLayout {
        anchors.fill:parent

        Button {
            id: button1
            text: qsTr("Play Sound")
        }

        Button {
            id: button2
            text: qsTr("New Pattern")
        }

        Button {
            id: button3
            text: qsTr("Press Me 3")
        }
    }
}
