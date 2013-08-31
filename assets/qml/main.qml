import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import qmltest 1.0

ApplicationWindow {
    width: 360
    height: 360

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
        RowLayout {
            Text {
                text: qsTr("Universe:")
            }
            TextField {
                id: planetTextField
                text: "a planet"
            }
            TextField {
                id: moonTextField
                text: "a moon"
            }

            Universe {
                id: universe
                planet: Planet {
                    name: ""
                    moon: Moon {
                        name: ""
                    }
                }

                onPlanetChanged: {
                    var planet = universe.planet;
                    var moon = planet.moon;
                    moon.name = "Mond"
                    planet.name = "Erde";

                    console.debug("Planet changed");

                    planetTextField.text = planet.name;
                    moonTextField.text = moon.name;
                }
            }


        }

        Button {
            text: "Create Planet"
            onClicked: universe.createPlanet()
        }
    }
}
