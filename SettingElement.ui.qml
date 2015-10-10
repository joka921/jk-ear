import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


Item {
    property alias labelDescription:labelDescription
    property alias labelValue: labelValue

    height: 50
    width:1
        ColumnLayout {
        anchors.fill: parent
        Label {
            id:labelDescription
            text:"blabla"
            height:1

        }
        RowLayout {

        Button {
            id: buttonNeg
            width:5
            onClicked: { if (labelValue.text>1)
                           labelValue.text-=1;

            }
            text: "-"
        }



        Label {
            id: labelValue
            width: 5




        }
        Button {
            id:buttonPositive
            width:10
            text: "+"
            onClicked: labelValue.text++
        }



}
        }
}
