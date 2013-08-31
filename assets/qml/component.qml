import QtQuick.Controls 1.0
import qmltest 1.0

Universe {
    id: universe

    property alias planetName: planet.name
    property alias moonName: moon.name

    TextField {
        text: "test"
    }

    planet: Planet {
        id: planet
        name: ""
        moon: Moon {
            id: moon
            name: ""
        }
    }

    onPlanetChanged: {
        var planet = universe.planet;
        var moon = planet.moon;
        moon.name = "Mond"
        planet.name = "Erde";

        console.debug("Planet changed");
    }


}
