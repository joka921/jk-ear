import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


Item {
    property alias labelDescription:labelDescription
    property alias labelValue: labelValue

    Layout.minimumHeight: mainLayout.implicitHeight
    Layout.minimumWidth: 200
        ColumnLayout {
            id: mainLayout
        Label {
            id:labelDescription
            text:"blabla"


        }
        RowLayout {

        Button {
            id: buttonNeg

            onClicked: { if (labelValue.text>1)
                           labelValue.text-=1;

            }
            text: "-"
        }



        Label {
            id: labelValue





        }
        Button {
            id:buttonPositive

            text: "+"
            onClicked: labelValue.text++
        }



}
        }
}
