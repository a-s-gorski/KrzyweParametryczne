// pch.h: wstępnie skompilowany plik nagłówka.
// Wymienione poniżej pliki są kompilowane tylko raz, co poprawia wydajność kompilacji dla przyszłych kompilacji.
// Ma to także wpływ na wydajność funkcji IntelliSense, w tym uzupełnianie kodu i wiele funkcji przeglądania kodu.
// Jednak WSZYSTKIE wymienione tutaj pliki będą ponownie kompilowane, jeśli którykolwiek z nich zostanie zaktualizowany między kompilacjami.
// Nie dodawaj tutaj plików, które będziesz często aktualizować (obniża to korzystny wpływ na wydajność).

#ifndef PCH_H
#define PCH_H

#include "..\ParametricCurves\Functions.hpp"
#include "..\ParametricCurves\Calculator.cpp"
#include "..\ParametricCurves\DrawingPlot.h"
#include "..\ParametricCurves\DrawingPlot.cpp"

#include "..\ParametricCurves\Frame.h"
#include "..\ParametricCurves\InputController.hpp"
#include <vector>
#include <cmath>

#endif //PCH_H
