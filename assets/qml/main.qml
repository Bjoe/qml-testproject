import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: mainWindow

    width: 360
    height: 360

    signal createPlanet()

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem {
                text: "Quit"
                shortcut: "Ctrl+Q"
                onTriggered: Qt.quit()
            }
        }
    }

    ColumnLayout {
        objectName: "layout"

        RowLayout {
            Text {
                text: qsTr("Universe:")
            }
            TextField {
                id: planetTextField
                text: universe.planetName
            }
            TextField {
                id: moonTextField
                text: universe.moonName
            }
        }

        Button {
            text: "Create Planet"
            onClicked: mainWindow.createPlanet()
        }
    }
}
