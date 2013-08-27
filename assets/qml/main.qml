import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import qmltest 1.0

ApplicationWindow {
    width: 360
    height: 360

    RowLayout {
        Text {
            text: qsTr("Universe:")
        }
        Universe {

        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
