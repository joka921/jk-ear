import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtMultimedia 5.0
import QtQuick.Layouts 1.1

import "qrc:/VexFlow.js" as VexFlow

ApplicationWindow {
    id: firstLevelElement
    title: qsTr("Hello World")
    property int margin: 11

    width: mainLayout.implicitWidth + 2 * margin
    height: mainLayout.implicitHeight + 2 * margin
    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin
    visible: true

    property var tempo:60
    property var numOfNotes: 3
    property var range: 12

    signal playExtern()
    signal stopExtern()

    signal newPattern(int range,int numOfNotes, int tempo)












ColumnLayout {
    id: mainLayout
    anchors.fill: parent
    anchors.margins: margin
RowLayout {

    ColumnLayout{

SettingElement{
    id: settingRange
    labelDescription.text: "Range"
    labelValue.text: range
    labelValue.onTextChanged: firstLevelElement.range=labelValue.text
}
SettingElement {
    id: settingNumNotes
    labelDescription.text: "Number of Notes"
    labelValue.text:numOfNotes
    labelValue.onTextChanged: firstLevelElement.numOfNotes=labelValue.text

}
SettingElement {
    id: settingTempo
    labelDescription.text: "Tempo"
    labelValue.text:tempo
    labelValue.onTextChanged: firstLevelElement.tempo=labelValue.text
}
}

MainForm {
    id: playbuttons

    button1.onClicked: firstLevelElement.playExtern()
    button2.onClicked: {
        firstLevelElement.newPattern(firstLevelElement.range,firstLevelElement.numOfNotes, firstLevelElement.tempo)


}


}



}


Canvas {
        id: musicCanvas


        height: 240
                width: 140
                //logical size 140 x 240

                property var renderer
                property var context
                property var trebleStave
                property var bassStave
                property real scale: 1
        onAvailableChanged: {
                    if (available) {onAvailableChanged: {
                            if (available) {

                                musicCanvas.renderer = new VexFlow.Vex.Flow.Renderer(musicCanvas, VexFlow.Vex.Flow.Renderer.Backends.CANVAS);
                                musicCanvas.context = renderer.getContext();
                                trebleStave = new VexFlow.Vex.Flow.Stave(10, 30, 120);
                                trebleStave.addClef("treble")
                                bassStave = new VexFlow.Vex.Flow.Stave(10, (trebleStave.options.num_lines + 1) * trebleStave.options.spacing_between_lines_px + 30, 120);
                                bassStave.addClef("bass");
                            }
                        }

                        musicCanvas.renderer = new VexFlow.Vex.Flow.Renderer(musicCanvas, VexFlow.Vex.Flow.Renderer.Backends.CANVAS);
                        musicCanvas.context = renderer.getContext();
                        trebleStave = new VexFlow.Vex.Flow.Stave(10, 30, 120);
                        trebleStave.addClef("treble")
                        bassStave = new VexFlow.Vex.Flow.Stave(10, (trebleStave.options.num_lines + 1) * trebleStave.options.spacing_between_lines_px + 30, 120);
                        bassStave.addClef("bass");

                    }
                }
        onPaint: {
                    context.save(); //clear only
                    context.clearRect(0, 0, width, height);
                    context.restore();
                    context.save();
                    context.scale(scale, scale);
                    trebleStave.setContext(context)
                    trebleStave.draw();
                    bassStave.setContext(context);
                    bassStave.draw();
        }
}
}
        }











