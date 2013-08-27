import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    width: 360
    height: 360

    RowLayout {
        Text {
            text: qsTr("Planet:")
        }
        Text {
            text: planet.name
        }
        Text {
            text: qsTr("Moon:")
        }
        Text {
            text: planet.moon.name
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
